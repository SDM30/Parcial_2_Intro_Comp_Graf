#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aColor;
layout (location = 3) in vec2 aTexCoord;

out vec3 crntPos;
out vec3 Normal;
out vec3 fragColor;
out vec2 texCoord;


uniform mat4 camMatrix;
uniform mat4 model;

void main()
{
    crntPos = vec3(model * vec4(aPos, 1.0));
    // Transform normal with inverse-transpose of model for correct lighting
    Normal = mat3(transpose(inverse(model))) * aNormal;
    // Pass color and texture coordinates to fragment shader
    fragColor = aColor;
    texCoord = aTexCoord;

    // Outputs position of all vertices
    gl_Position = camMatrix * vec4(crntPos, 1.0);
}