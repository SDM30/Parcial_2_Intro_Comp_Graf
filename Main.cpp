#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

const unsigned int width = 800;
const unsigned int height = 800;

// Vertices coordinates
GLfloat pyramidVertexData[] =
{ //     COORDINATES     /        COLORS      
	// Base 
	-0.5f, 0.0f,  0.5f,     1.0f, 0.0f, 0.0f,	// R (vert 0)
	-0.5f, 0.0f, -0.5f,     0.0f, 1.0f, 0.0f,	// G (vert 1)
	 0.5f, 0.0f, -0.5f,     0.0f, 0.0f, 1.0f,	// B (vert 2)
	 0.5f, 0.0f,  0.5f,     1.0f, 0.0f, 1.0f,	// Dark G(vert 3)

	 // Peak
	  0.0f, 0.8f,  0.0f,     1.0f, 0.5f, 0.0f	// Orange (vert 4)
};

GLuint pyramidElementIndices[] =
{
	0, 1, 2, // Pyramid base upper diagonal
	0, 2, 3, // Pyramid base lower diagonal

	0, 1, 4, // Side 1 front
	1, 2, 4, // Side 2 right
	2, 3, 4, // Side 3 back
	3, 0, 4  // Side 4 left
};

int main()
{
	// Initialize GLFW - Inicializa la biblioteca GLFW
	glfwInit();

	// Configura la versión de OpenGL a usar (3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Usa el perfil core de OpenGL (solo funciones modernas)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Crea una ventana de 800x800 pixels
	GLFWwindow* window = glfwCreateWindow(width, height, "PARCIAL II - Piramide Rotando", NULL, NULL);
	// Verifica si la ventana se creó correctamente
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Hace que la ventana sea el contexto actual de OpenGL
	glfwMakeContextCurrent(window);

	// Carga las funciones de OpenGL mediante GLAD
	gladLoadGL();
	// Define el área de visualización dentro de la ventana
	glViewport(0, 0, width, height);

	// Crea un objeto shader con los archivos de vértice y fragmento
	Shader shaderProgram("default.vert", "default.frag");

	// Crea y enlaza el Vertex Array Object
	VAO VAO1;
	VAO1.Bind();

	// Crea el Vertex Buffer Object con los datos de los vértices
	VBO VBO1(pyramidVertexData, sizeof(pyramidVertexData));
	// Crea el Element Buffer Object con los índices de los triángulos
	EBO EBO1(pyramidElementIndices, sizeof(pyramidElementIndices));

	// Configura el atributo de posición (location 0) en el VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	// Configura el atributo de color (location 1) en el VAO
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	// Desenlaza todos los objetos para evitar modificaciones accidentales
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Variable para controlar la rotación de la pirámide
	float rotation = 0.0f;
	// Variable para almacenar el tiempo del frame anterior
	double prevTime = glfwGetTime();

	// Habilita el depth testing para renderizado 3D correcto
	glEnable(GL_DEPTH_TEST);

	// Loop principal de la aplicación
	while (!glfwWindowShouldClose(window))
	{
		// Establece el color de fondo (azul oscuro)
		glClearColor(0.10f, 0.10f, 0.17f, 1.0f);
		// Limpia los buffers de color y profundidad
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Activa el programa de shaders
		shaderProgram.Activate();

		// Obtiene el tiempo actual
		double crntTime = glfwGetTime();
		// Actualiza la rotación cada 1/60 segundos
		if (crntTime - prevTime >= 1.0f / 60.0f)
		{
			// Incrementa el ángulo de rotación
			rotation += 1.5f;
			// Mantiene el ángulo entre 0 y 360 grados
			if (rotation > 360.0f) rotation -= 360.0f;
			// Actualiza el tiempo del frame anterior
			prevTime = crntTime;
		}

		// Matrices de transformación
		glm::mat4 model = glm::mat4(1.0f);  // Matriz modelo (transformaciones del objeto)
		glm::mat4 view = glm::mat4(1.0f);   // Matriz vista (posición/orientación de la cámara)
		glm::mat4 proj = glm::mat4(1.0f);   // Matriz proyección (perspectiva)

		// Mueve la pirámide 3 unidades hacia atrás en el eje Z
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
		// Rota la pirámide continuamente alrededor del eje Y
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));

		// Configura la cámara en posición fija
		view = glm::lookAt(
			glm::vec3(0.0f, 2.0f, 0.0f),    // Posición de la cámara (arriba y centrada)
			glm::vec3(0.0f, 0.0f, -3.0f),   // Punto al que mira la cámara (centro de la pirámide)
			glm::vec3(0.0f, 1.0f, 0.0f)     // Vector que indica la dirección "arriba"
		);

		// Configura la proyección en perspectiva
		proj = glm::perspective(glm::radians(45.0f), (float)(width / height), 0.1f, 100.0f);

		// Obtiene la ubicación del uniform "model" en el shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		// Envía la matriz modelo al shader
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		// Obtiene la ubicación del uniform "view" en el shader
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		// Envía la matriz vista al shader
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Obtiene la ubicación del uniform "proj" en el shader
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		// Envía la matriz proyección al shader
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// Enlaza el VAO para dibujar
		VAO1.Bind();
		// Dibuja la pirámide usando los índices (triángulos)
		glDrawElements(GL_TRIANGLES, sizeof(pyramidElementIndices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);

		// Intercambia los buffers (doble buffer)
		glfwSwapBuffers(window);
		// Procesa eventos de la ventana
		glfwPollEvents();
	}

	// Limpieza: elimina todos los objetos creados
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Destruye la ventana
	glfwDestroyWindow(window);
	// Termina GLFW
	glfwTerminate();
	return 0;
}