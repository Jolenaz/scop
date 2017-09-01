#version 410 core

in vec4				color;
out vec4			fColor;
in vec2				UV;
in float			coef;
uniform sampler2D	myTextureSampler;
void main()
{
	fColor = texture( myTextureSampler, UV) * coef + color * (1.0 - coef);
}