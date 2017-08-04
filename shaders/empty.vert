#version 410 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec4 vColor;
uniform mat4 VP;
out vec4 color;
void main(){
	color = vColor;
	gl_Position = VP * vec4(vertexPosition_modelspace,1);
}
// layout(location = 0) in vec4 vPosition;
// layout(location = 1) in vec4 vColor;
// // mat4 VP = 	mat4(1,0,0,0,
// // 			 0,1,0,0,
// // 			 0,0,1,0,
// // 			 1,1,0,1);
// uniform mat4 VP;
// out vec4 color;
// void main()
// {
// 	color = vColor;
// 	gl_Position = VP * vPosition;
// }