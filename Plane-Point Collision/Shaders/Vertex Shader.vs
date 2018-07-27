#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 normal;

out vec3 fragPos;
out vec3 fragNormal;
out vec4 fragColor;

uniform mat4 MVP;
uniform mat4 model; // Or ‘normalMatrix’

void main(void) {
	gl_Position = MVP * vec4(position, 1.0);
	fragPos = vec3(model * vec4(position, 1.0f));
	fragNormal = mat3(transpose(inverse(model))) * normal;
	fragColor = vec4(color, 1.0f);
}