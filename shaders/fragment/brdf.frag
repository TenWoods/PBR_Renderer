#version 330 core

in vec2 texcoords;

out vec2 FragColor;

const float PI = 3.14159265359;

float RadicalInverse_VdC(uint bits)
{
	bits = (bits << 16u) | (bits >> 16u);
	bits = ((bits & 0x55555555u) << 1u) | ((bits & 0xAAAAAAAAu) >> 1u);
    bits = ((bits & 0x33333333u) << 2u) | ((bits & 0xCCCCCCCCu) >> 2u);
    bits = ((bits & 0x0F0F0F0Fu) << 4u) | ((bits & 0xF0F0F0F0u) >> 4u);
    bits = ((bits & 0x00FF00FFu) << 8u) | ((bits & 0xFF00FF00u) >> 8u);
    return float(bits) * 2.3283064365386963e-10; // / 0x100000000
}

vec2 Hammersley(uint i, uint N)
{
    return vec2(float(i) / float(N), RadicalInverse_VdC(i));
}

//重要性采样GGX
vec3 ImportanceSampleGGX(vec2 Xi, vec3 N, float roughness)
{
    float r2 = roughness*roughness;
	
	float phi = 2.0 * PI * Xi.x;
	float cosTheta = sqrt((1.0 - Xi.y) / (1.0 + (r2 * r2 - 1.0) * Xi.y));
	float sinTheta = sqrt(1.0 - cosTheta*cosTheta);
	
	vec3 H;
	H.x = cos(phi) * sinTheta;
	H.y = sin(phi) * sinTheta;
	H.z = cosTheta;
	
	vec3 up = abs(N.z) < 0.999 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0);
	vec3 tangent = normalize(cross(up, N));
	vec3 bitangent = cross(N, tangent);
	
	vec3 sampleVec = tangent * H.x + bitangent * H.y + N * H.z;
	return normalize(sampleVec);
}

//几何遮挡函数
float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = roughness;
    float k = (r * r) / 2.0;
    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;
    return nom / denom;
}

//几何遮蔽与几何阴影整合
float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness)
{
    float NdotV = max(dot(normal, viewDir), 0.0);
    float NdotL = max(dot(normal, lightDir), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);
    return ggx1 * ggx2;
}

//整合BRDF
vec2 IntegrateBRDF(float NdotV, float roughness)
{
    vec3 viewDir;
    viewDir.x = sqrt(1.0 - NdotV*NdotV);
    viewDir.y = 0.0;
    viewDir.z = NdotV;
    float A = 0.0;
    float B = 0.0; 
    vec3 normal = vec3(0.0, 0.0, 1.0);
    const uint SAMPLE_COUNT = 1024u;
    for(uint i = 0u; i < SAMPLE_COUNT; ++i)
    {
        //生成采样向量
        vec2 Xi = Hammersley(i, SAMPLE_COUNT);
        vec3 halfvec = ImportanceSampleGGX(Xi, normal, roughness);
        vec3 lightDir = normalize(2.0 * dot(viewDir, halfvec) * halfvec - viewDir);
        float NdotL = max(lightDir.z, 0.0);
        float NdotH = max(halfvec.z, 0.0);
        float VdotH = max(dot(viewDir, halfvec), 0.0);
        if(NdotL > 0.0)
        {
            float G = GeometrySmith(normal, viewDir, lightDir, roughness);
            float G_Vis = (G * VdotH) / (NdotH * NdotV);
            float Fc = pow(1.0 - VdotH, 5.0);
            A += (1.0 - Fc) * G_Vis;
            B += Fc * G_Vis;
        }
    }
    A /= float(SAMPLE_COUNT);
    B /= float(SAMPLE_COUNT);
    return vec2(A, B);
}

void main() 
{
    vec2 integratedBRDF = IntegrateBRDF(texcoords.x, texcoords.y);
    FragColor = integratedBRDF;
}