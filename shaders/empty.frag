#version 410 core

// out vec3 color;
// void main(){
//   color = vec3(1,0,0);
// }

in vec4				color;
out vec4			fColor;
in vec2				UV;
uniform sampler2D	myTextureSampler;
void main()
{
	fColor = texture( myTextureSampler, UV );
}