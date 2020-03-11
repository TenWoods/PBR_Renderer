#version 330 core
#define POINTNUM 10
#define SPOTNUM 5

in vec3 fragPos;
in vec3 normal;
in vec2 texcoord;
in mat3 TBN;

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

struct Material
{
    sampler2D texture_diffuse;
    sampler2D texture_normal;
    sampler2D texture_specular;
    sampler2D texture_height;
};

uniform vec3 cameraPos;
uniform DirectionLight dirLight;
uniform PointLight pointLights[POINTNUM];
uniform SpotLight spotLights[SPOTNUM];
uniform int plNum;  //点光源数量
uniform int slNum;  //聚光数量
uniform Material material;

//定向光计算
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir);
//点光源计算
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
//聚光计算
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    //法线贴图
    vec3 normal_Map = vec3(texture(material.texture_normal, texcoord));
    normal_Map = normalize(normal_Map * 2.0 - 1.0f);
    normal_Map = normalize(TBN * normal_Map);
    //视角方向
    vec3 viewDir = cameraPos - fragPos;
    viewDir = normalize(viewDir);
    //平行光
	vec3 color = CalcDirectLight(dirLight, normal_Map, viewDir);
    //点光源
    for (int i = 0; i < plNum; i++)
        color += CalcPointLight(pointLights[i], normal_Map, fragPos, viewDir);
    //聚光
    for (int i = 0; i < slNum; i++)
        color += CalcSpotLight(spotLights[i], normal_Map, fragPos, viewDir);
	FragColor = vec4(color, 1.0);
}

//定向光计算
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
    // 合并结果
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse, texcoord));
    vec3 diffuse  = light.lightColor * diff * vec3(texture(material.texture_diffuse, texcoord));
    vec3 specular = light.lightColor * spec * vec3(texture(material.texture_specular, texcoord));
    return (ambient + diffuse + specular);
}

//点光源计算
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    //漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    //镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
    //衰减计算
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); 
    //合并结果
    vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse, texcoord));
    vec3 diffuse = light.lightColor * diff * vec3(texture(material.texture_diffuse, texcoord));
    vec3 specular = light.lightColor * spec * vec3(texture(material.texture_specular, texcoord));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

//聚光计算
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    //漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    //镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
    //远近衰减计算
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    //中心衰减计算
    float theta = dot(normalize(-light.direction), lightDir);
    float epsilon = light.cutOff - light.cutoffout;
    float intensity = clamp((theta - light.cutoffout) / epsilon, 0.0, 1.0);
    //合并结果
    vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse, texcoord));
    vec3 diffuse = light.lightColor * diff * vec3(texture(material.texture_diffuse, texcoord));
    vec3 specular = light.lightColor * spec * vec3(texture(material.texture_specular, texcoord));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}

