#version 330 core

in vec3 fragPos;
in vec3 normal;
//in vec2 texcoord;

out vec4 FragColor;

void main()
{
	FragColor = vec4(normal, 1.0);
}