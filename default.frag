#version 330 core
in vec3 fragColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D tex0;

void main()
{
    vec4 tex = texture(tex0, texCoord);
    FragColor = tex;
}