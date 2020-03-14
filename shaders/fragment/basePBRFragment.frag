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
uniform int plNum;  //点光源数量
uniform int slNum;  //聚光数量
//PBR材质数据
uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;

const float PI = 3.14159265359;

//定向光计算
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir, vec3 F0);
//点光源计算
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0);
//聚光计算
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0);

//法线分布函数
float DistributionGGX(vec3 normal, vec3 halfvec, float roughness);
//几何遮挡函数
float GeometrySchlickGGX(float NdotV, float roughness);
//几何遮蔽与几何阴影整合
float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness);
//菲涅尔方程
vec3 fresnelSchlick(float cosTheta, vec3 F0);

void main()
{
    vec3 normalized_normal = normalize(normal);
    vec3 viewDir = normalize(cameraPos - fragPos);
    vec3 Lo = vec3(0.0);
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);
    //定向光
    Lo += CalcDirectLight(dirLight, normalized_normal, viewDir, F0);
    //点光源
    for (int i = 0; i < plNum; i++)
    {
        Lo += CalcPointLight(pointLights[i], normalized_normal, fragPos, viewDir, F0);
    }
    //聚光
    for (int i = 0; i < slNum; i++)
    {
        Lo += CalcSpotLight(spotLights[i], normalized_normal, fragPos, viewDir, F0);
    }
    vec3 ambient = vec3(0.03) * albedo * ao;
    vec3 color = ambient + Lo;
    //伽马校正和HDR
    color = color / (color + vec3(1.0));
    color = pow(color, vec3(1.0 / 2.2));
    FragColor = vec4(color, 1.0);
}

//法线分布函数
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

//几何遮挡函数
float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r * r) / 8.0;
    float nom = NdotV;
    float denom = NdotV * (1.0 - k) + k;
    return nom / denom;
}

//几何遮蔽与几何阴影整合
float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness)
{
    float NdotV = max(dot(normal, viewDir), 0.0);
    float NdotL = max(dot(normal, lightDir), 0.0);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    return ggx1 * ggx2;
}

//菲涅尔方程
vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}

//定向光计算
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir, vec3 F0)
{
    //前置数据
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
    //结果
    float NdotL = max(dot(normal, lightDir), 0.0);
    vec3 color = (kd * albedo / PI + specular) * radiance * NdotL;
    return color;
}

//点光源计算
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0)
{
    //前置数据
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfVec = normalize(viewDir + lightDir);
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (distance * distance);
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
    //结果
    float NdotL = max(dot(normal, lightDir), 0.0);
    vec3 color = (kd * albedo / PI + specular) * radiance * NdotL;
    return color;
}

//聚光计算
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 F0)
{
    //前置数据
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfVec = normalize(viewDir + lightDir);
    //远近衰减计算
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    //中心衰减计算
    float theta = dot(normalize(-light.direction), lightDir);
    float epsilon = light.cutOff - light.cutoffout;
    float intensity = clamp((theta - light.cutoffout) / epsilon, 0.0, 1.0);

    vec3 radiance = light.lightColor * attenuation * intensity;

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
    //结果
    float NdotL = max(dot(normal, lightDir), 0.0);
    vec3 color = (kd * albedo / PI + specular) * radiance * NdotL;
    return color;
}