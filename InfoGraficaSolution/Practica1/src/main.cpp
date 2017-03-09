//GLEW
#define GLEW_STATIC
#include <GL\glew.h>
//GLFW
#include <GLFW\glfw3.h>
#include <iostream>
#include <shader.hpp>

using namespace std;
const GLint WIDTH = 800, HEIGHT = 600;
bool WIDEFRAME = false;


int main() {
	//initGLFW
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);

	//set GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	//create a window
	window = glfwCreateWindow(WIDTH, HEIGHT, "P1", nullptr, nullptr);
	if (!window) {  // Control de errores
		cout << "Error al crear la ventana" << endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	//set GLEW and inicializate
//TODO
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) { // Control de errores
		std::cout << "Error al inicializar glew" << std::endl;
		glfwTerminate();
		return NULL;
	}

	int screenWithd, screenHeight;
	glfwGetFramebufferSize(window, &screenWithd, &screenHeight);

	//set function when callback
	glfwSetKeyCallback(window, key_callback);

	//set windows and viewport
	glViewport(0, 0, screenWithd, screenHeight);
	

	//fondo
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);


	//cargamos los shader
	GLuint programID = LoadShaders("./src/SimpleVertexShader.vertexshader", "./src/SimpleFragmentShader.fragmentshader");

	// Definir el buffer de vertices

	// Definir el EBO

	GLuint EBO;

	// Crear los VBO, VAO y EBO
	
	GLuint VBO;
	//GLuint VAO;

	//reservar memoria para el VAO, VBO y EBO

	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);
	// VAO


	//Establecer el objeto
		//Declarar el VBO y el EBO

		//Enlazar el buffer con openGL

		//Establecer las propiedades de los vertices

		//liberar el buffer
	
	//liberar el buffer de vertices


	//bucle de dibujado
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions

		//Establecer el color de fondo

		//establecer el shader
		glUseProgram(programID);

		//pintar el VAO

		//pintar con lineas


		//pintar con triangulos



		// Swap the screen buffers
	}

	// liberar la memoria de los VAO, EBO y VBO
	//glDeleteBuffers(, *EBO);
	//glDeleteBuffers(, *VBO);
	//glDeleteBuffers(, *VAO);

	// Terminate GLFW, clearing any resources allocated by GLFW.
	exit(EXIT_SUCCESS);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	//TODO, comprobar que la tecla pulsada es escape para cerrar la aplicación y la tecla w para cambiar a modo widwframe
	//W
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {

	}

	//ESC
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}