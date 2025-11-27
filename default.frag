#version 330 core
in vec3 fragColor;
in vec2 texCoord;
// Imports the normal from the Vertex Shader
in vec3 Normal;
// Imports the current position from the Vertex Shader
in vec3 crntPos;

out vec4 FragColor;

uniform sampler2D tex0;

uniform vec4 lightColor;

uniform vec3 lightPos;

void main()
{
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - crntPos);

    float diffuse = max(dot(normal, lightDirection), 0.0);

    vec4 tex = texture(tex0, texCoord);
    FragColor = tex * lightColor * diffuse;
}