#version 410 core

layout(location = 0) in	vec3 vertexPosition_modelspace;
layout(location = 1) in	vec4 vColor;
uniform mat4			WVP;
uniform	float			fcoef;
out vec4				color;
out	vec2				UV;
out float				fdelta;

void main(){
	color = fColor;
	coef = coef;
	UV.x = vertexPosition_modelspace.x;
	UV.y = vertexPosition_modelspace.y;
	gl_Position = WVP * vec4(vertexPosition_modelspace,1);
}
