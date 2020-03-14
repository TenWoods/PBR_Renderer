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
uniform vec3 albedo;  //��ɫ

//��������
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir);
//���Դ����
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
//�۹����
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 viewDir = cameraPos - fragPos;
    viewDir = normalize(viewDir);
    vec3 color = vec3(0.0, 0.0, 0.0);
    //ƽ�й�
	color += CalcDirectLight(dirLight, normal, viewDir);
    //���Դ
    for (int i = 0; i < plNum; i++)
        color += CalcPointLight(pointLights[i], normal, fragPos, viewDir);
    //�۹�
    for (int i = 0; i < slNum; i++)
        color += CalcSpotLight(spotLights[i], normal, fragPos, viewDir);
	FragColor = vec4(color, 1.0);
}

//��������
vec3 CalcDirectLight(DirectionLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // ��������ɫ
    float diff = max(dot(normal, lightDir), 0.0);
    // �������ɫ
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
    // �ϲ����
    vec3 ambient  = light.ambient  * vec3(0.05, 0.05, 0.05);
    vec3 diffuse  = light.lightColor * diff * albedo;
    vec3 specular = light.lightColor * spec * albedo;
    return (ambient + diffuse + specular);
}

//���Դ����
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    //��������ɫ
    float diff = max(dot(normal, lightDir), 0.0);
    //�������ɫ
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
    //˥������
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); 
    //�ϲ����
    vec3 ambient = light.ambient * vec3(0.05, 0.05, 0.05);
    vec3 diffuse = light.lightColor * diff * albedo;
    vec3 specular = light.lightColor * spec * albedo;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

//�۹����
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    //��������ɫ
    float diff = max(dot(normal, lightDir), 0.0);
    //�������ɫ
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
    //Զ��˥������
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    //����˥������
    float theta = dot(normalize(-light.direction), lightDir);
    float epsilon = light.cutOff - light.cutoffout;
    float intensity = clamp((theta - light.cutoffout) / epsilon, 0.0, 1.0);
    //�ϲ����
    vec3 ambient = light.ambient * vec3(0.05, 0.05, 0.05);
    vec3 diffuse = light.lightColor * diff * albedo;
    vec3 specular = light.lightColor * spec * albedo;
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}