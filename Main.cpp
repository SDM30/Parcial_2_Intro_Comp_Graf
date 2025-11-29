#include "Mesh.h"



const unsigned int width = 800;
const unsigned int height = 800;

Vertex cubeVertexData[] =
{ //     COORDINATES     /        COLORS      /   NORMALS     /   TEXCOORDINATES   
	// Front face
	Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},  // 0
	Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},  // 1
	Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},  // 2
	Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},  // 3

	// Back face
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f)}, // 4
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f)}, // 5
	Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f)}, // 6
	Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f)}, // 7

	// Top face
	Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},  // 8
	Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},  // 9
	Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},  // 10
	Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},  // 11

	// Bottom face
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)}, // 12
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)}, // 13
	Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)}, // 14
	Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)}, // 15

	// Right face
	Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},  // 16
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},  // 17
	Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},  // 18
	Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},  // 19

	// Left face
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)}, // 20
	Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)}, // 21
	Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)}, // 22
	Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)}  // 23
};

GLuint cubeElementIndices[] =
{
	// Front face
	0, 1, 2,
	2, 3, 0,

	// Back face
	4, 5, 6,
	6, 7, 4,

	// Top face
	8, 9, 10,
	10, 11, 8,

	// Bottom face
	12, 13, 14,
	14, 15, 12,

	// Right face
	16, 17, 18,
	18, 19, 16,

	// Left face
	20, 21, 22,
	22, 23, 20
};

Vertex lightVertices[] =
{
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "PROYECTO", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	Texture textures[]
	{
		Texture("wall_tiles_texture.png", "diffuse", GL_TEXTURE0, GL_UNSIGNED_BYTE),
		Texture("wall_tiles_texture_spec.png", "specular", GL_TEXTURE1, GL_UNSIGNED_BYTE)
	};

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	std::vector<Vertex> vertices(cubeVertexData, cubeVertexData + sizeof(cubeVertexData) / sizeof(Vertex));
	std::vector<GLuint> indices(cubeElementIndices, cubeElementIndices + sizeof(cubeElementIndices) / sizeof(GLuint));
	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	Mesh cubeMesh(vertices, indices, tex);


	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	Mesh lightMesh(lightVerts, lightInd, tex);


	glm::vec4 lightColor = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(1.0f, 0.1f, 0.2f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 cubePos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 cubeModel = glm::mat4(1.0f);
	cubeModel = glm::translate(cubeModel, cubePos);


	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(cubeModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST); 
	// FACE CULLING
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 3.0f));


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.10f, 0.10f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Handle camera inputs
		camera.Inputs(window);
		// Update and export the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		cubeMesh.Draw(shaderProgram, camera);
		lightMesh.Draw(lightShader, camera);

		
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	// Delete all the objects we've created
	shaderProgram.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}