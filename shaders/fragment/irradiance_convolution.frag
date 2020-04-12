#version 330 core

in vec3 worldPos;

out vec4 FragColor;

uniform samplerCube environmentMap;

const float PI = 3.14159265359;

void main()
{
	vec3 normal = normalize(worldPos);
	vec3 irradiance = vec3(0.0);
	vec3 up = vec3(0.0, 1.0, 0.0);
	vec3 right = cross(up, normal);
	up = cross(normal, right);
	float sampleDelta = 0.025;
	int nrSample = 0;
	for (float phi = 0.0; phi < 2.0 * PI; phi += sampleDelta)
	{
		for (float theta = 0.0; theta < 0.5 * PI; theta += sampleDelta)
		{
			vec3 tangentSample = vec3(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
			vec3 sampleVec = tangentSample.x * right + tangentSample.y * up + tangentSample.z * normal;
			irradiance += texture(environmentMap, sampleVec).rgb * cos(theta) * sin(theta);
			nrSample++;
		}
	}
	irradiance = PI * irradiance * (1.0 / float(nrSample));
	//irradiance = texture(environmentMap, normal).rgb;
	FragColor = vec4(irradiance, 1.0);
}