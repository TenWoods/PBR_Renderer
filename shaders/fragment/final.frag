#version 330 core
#define POINTNUM 10
#define SPOTNUM 5

in vec3 fragPos;
in vec3 normal;
in vec2 texcoord;

out vec4 FragColor;

struct DirectionLight
{
	vec3 direction;
    vec3 ambient;
    vec3 lightColor;
};

struct PointLight
{
	vec3 position;
    float constant;
    float linear;
    float quadratic;   
    vec3 ambient;
    vec3 lightColor;
};

struct SpotLight
{
    vec3 position;
    vec3  direction;
    float constant;
    float linear;
    float quadratic; 
    vec3 ambient;
    vec3 lightColor;
    float cutOff;
    float cutoffout;
};

uniform vec3 cameraPos;
uniform DirectionLight dirLight;
uniform PointLight pointLights[POINTNUM];
uniform SpotLight spotLights[SPOTNUM];
uniform int plNum;  //���Դ����
uniform int slNum;  //�۹�����
//PBR��������
uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;
uniform samplerCube irradianceMap;
uniform samplerCube prefilterMap;
uniform sampler2D brdfLUT;

const float PI = 3.14159265359;

//��������
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir, vec3 F0);
//���Դ����
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0);
//�۹����
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0);

//���߷ֲ�����
float DistributionGGX(vec3 normal, vec3 halfvec, float roughness);
//�����ڵ�����
float GeometrySchlickGGX(float NdotV, float roughness);
//�����ڱ��뼸����Ӱ����
float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness);
//����������
vec3 fresnelSchlick(float cosTheta, vec3 F0);
vec3 fresnelSchlickRoughness(float cosTheta, vec3 F0, float roughness);

void main()
{
    vec3 normalized_normal = normalize(normal);
    vec3 viewDir = normalize(cameraPos - fragPos);
    vec3 reflectDir = reflect(-viewDir, normalized_normal); 
    vec3 Lo = vec3(0.0);
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);
    //�����
    Lo += CalcDirectLight(dirLight, normalized_normal, viewDir, F0);
    //���Դ
    for (int i = 0; i < plNum; i++)
    {
        Lo += CalcPointLight(pointLights[i], normalized_normal, fragPos, viewDir, F0);
    }
    //�۹�
    for (int i = 0; i < slNum; i++)
    {
        Lo += CalcSpotLight(spotLights[i], normalized_normal, fragPos, viewDir, F0);
    }
    vec3 F = fresnelSchlickRoughness(max(dot(normalized_normal, viewDir), 0.0), F0, roughness);
    vec3 ks = F;
    vec3 kd = 1.0 - ks;
    kd *= 1.0 - metallic;
    vec3 irradiance = texture(irradianceMap, normalized_normal).rgb;
    vec3 diffuse = irradiance * albedo;

    const float MAX_REFLECTION_LOD = 4.0;
    vec3 prefilteredColor = textureLod(prefilterMap, reflectDir, roughness * MAX_REFLECTION_LOD).rgb;
    vec2 brdf  = texture(brdfLUT, vec2(max(dot(normalized_normal, viewDir), 0.0), roughness)).rg;
    vec3 specular = prefilteredColor * (F * brdf.x + brdf.y);

    vec3 ambient = (kd * diffuse + specular) * ao;
    vec3 color = ambient + Lo;
    //٤��У����HDR
    color = color / (color + vec3(1.0));
    color = pow(color, vec3(1.0 / 2.2));
    FragColor = vec4(color, 1.0);
}

//���߷ֲ�����
float DistributionGGX(vec3 normal, vec3 halfvec, float roughness)
{
    float a = roughness * roughness;
    float a2 = a * a;
    float NdotH = max(dot(normal, halfvec), 0.0);
    float NdotH2 = NdotH * NdotH;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;
    return a2 / denom;
}

//�����ڵ�����
float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r * r) / 8.0;
    float nom = NdotV;
    float denom = NdotV * (1.0 - k) + k;
    return nom / denom;
}

//�����ڱ��뼸����Ӱ����
float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness)
{
    float NdotV = max(dot(normal, viewDir), 0.0);
    float NdotL = max(dot(normal, lightDir), 0.0);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    return ggx1 * ggx2;
}

//����������
vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}

vec3 fresnelSchlickRoughness(float cosTheta, vec3 F0, float roughness)
{
    return F0 + (max(vec3(1.0 - roughness), F0) - F0) * pow(1.0 - cosTheta, 5.0);
} 

//��������
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir, vec3 F0)
{
    //ǰ������
    vec3 lightDir = normalize(-light.direction);
    vec3 halfVec = normalize(viewDir + lightDir);
    vec3 radiance = light.lightColor;
    //BRDF
    float D = DistributionGGX(normal, halfVec, roughness);
    float G = GeometrySmith(normal, viewDir, lightDir, roughness);
    vec3 F = fresnelSchlick(clamp(dot(halfVec, viewDir), 0.0, 1.0), F0);
    vec3 ks = F;
    vec3 kd = vec3(1.0) - ks;
    kd *= (1.0 - metallic);
    vec3 nom = D * G * F;
    float denom = 4.0 * max(dot(normal, viewDir), 0.0) * max(dot(normal, lightDir), 0.0);
    vec3 specular = nom / max(denom, 0.001);
    //���
    float NdotL = max(dot(normal, lightDir), 0.0);
    vec3 color = (kd * albedo / PI + specular) * radiance * NdotL;
    return color;
}

//���Դ����
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0)
{
    //ǰ������
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfVec = normalize(viewDir + lightDir);
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (distance * distance);
    vec3 radiance = light.lightColor * attenuation;
    //BRDF
    float D = DistributionGGX(normal, halfVec, roughness);
    float G = GeometrySmith(normal, viewDir, lightDir, roughness);
    vec3 F = fresnelSchlick(clamp(dot(halfVec, viewDir), 0.0, 1.0), F0);
    vec3 nominator = D * G * F;
    vec3 ks = F;
    vec3 kd = vec3(1.0) - ks;
    kd *= (1.0 - metallic);
    vec3 nom = D * G * F;
    float denom = 4.0 * max(dot(normal, viewDir), 0.0) * max(dot(normal, lightDir), 0.0);
    vec3 specular = nom / max(denom, 0.001);
    //���
    float NdotL = max(dot(normal, lightDir), 0.0);
    vec3 color = (kd * albedo / PI + specular) * radiance * NdotL;
    return color;
}

//�۹����
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0)
{
    //ǰ������
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfVec = normalize(viewDir + lightDir);
    //Զ��˥������
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    //����˥������
    float theta = dot(normalize(-light.direction), lightDir);
    float epsilon = light.cutOff - light.cutoffout;
    float intensity = clamp((theta - light.cutoffout) / epsilon, 0.0, 1.0);

    vec3 radiance = light.lightColor * attenuation;

    //BRDF
    float D = DistributionGGX(normal, halfVec, roughness);
    float G = GeometrySmith(normal, viewDir, lightDir, roughness);
    vec3 F = fresnelSchlick(clamp(dot(halfVec, viewDir), 0.0, 1.0), F0);
    vec3 ks = F;
    vec3 kd = vec3(1.0) - ks;
    kd *= (1.0 - metallic);
    vec3 nom = D * G * F;
    float denom = 4.0 * max(dot(normal, viewDir), 0.0) * max(dot(normal, lightDir), 0.0);
    vec3 specular = nom / max(denom, 0.001);
    //���
    float NdotL = max(dot(normal, lightDir), 0.0);
    vec3 color = (kd * albedo / PI + specular) * radiance * NdotL;
    return color * intensity;
}