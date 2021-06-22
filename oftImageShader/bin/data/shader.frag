#version 150

uniform sampler2DRect tex0;
uniform vec2 u_window;

in vec2 v_texcoord;
out vec4 color;

void main()
{
    vec4 tex = texture(tex0, v_texcoord);

	color = tex;
}