#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

using namespace std;
const GLint WIDTH = 800, HEIGHT = 600;

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//cuando se pulsa una tecla escape cerramos la aplicacion
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {

	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);

	//comprobar que GLFW estaactivo
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//crear la ventana
	window = glfwCreateWindow(WIDTH, HEIGHT, "Primera ventana", nullptr, nullptr);
	if (!window) {
		cout << "Error al crear la ventana" << endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) {
		std::cout << "Error al inicializar glew" << std::endl;
		glfwTerminate();
		return NULL;
	}

	int screenWithd, screenHeight;
	glfwGetFramebufferSize(window, &screenWithd, &screenHeight);

	//que funcion se llama cuando se detecta una pulsaci�n de tecla en la ventana x
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		////definir las dimensiones del buffer
		//int screenWithd, screenHeigtht;
		//float ratio;
		//glfwGetFramebufferSize(window, &screenWithd, &screenHeigtht);
		//ratio = screenWithd / (float)screenHeigtht;

		//origen de la camara, dimensiones de la ventana
		glViewport(0, 0, screenWithd, screenHeight);
		glClear(GL_COLOR_BUFFER_BIT);

		//color de fondo
		glClearColor(1.0, 1.0, 1.0, 1.0);

		//definir la matriz de proyeccion
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-10, 10, -10.f, 10.f, -1.0f, 10.f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef((float)glfwGetTime() * 50.f,1.f, 0.f, 0.f);

		//para volver a dejar la rotacion parada
		//glLoadIdentity();

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//Activar normales en sentido antihorario GL_CCW -> Horario GL_CW
		glFrontFace(GL_CCW);

		//Fondo
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.611, 0.843);
		glVertex3f(-10.0f, 10.0f, 0.f);
		glVertex3f(-10.0f, -10.0f, 0.f);
		glVertex3f(10.0f, -10.0f, 0.f);
		glVertex3f(10.0f, 10.0f, 0.f);
		
			//Terreno
			glColor3f(0.380, 0.545, 0.235);
			glVertex3f(-10.0f, 1.0f, 0.f);
			glVertex3f(-10.0f, -10.0f, 0.f);
			glVertex3f(10.0f, -10.0f, 0.f);
			glVertex3f(10.0f, 1.0f, 0.f);

			//Carretera
			glColor3f(0.498, 0.388, 0.239);
			glVertex3f(0.0f, 1.0f, 0.f);
			glVertex3f(-15.0f, -10.0f, 0.f);
			glVertex3f(0.0f, -10.0f, 0.f);
			glVertex3f(4.0f, 1.0f, 0.f);
			
				//Rayas
				glColor3f(0.439, 0.439, 0.439);
				glVertex3f(0.0f, 1.0f, 0.f);
				glVertex3f(-15.0f, -10.0f, 0.f);
				glVertex3f(-14.5f, -10.0f, 0.f);
				glVertex3f(0.5f, 1.0f, 0.f);

				glVertex3f(3.5f, 1.0f, 0.f);
				glVertex3f(-0.5f, -10.0f, 0.f);
				glVertex3f(0.0f, -10.0f, 0.f);
				glVertex3f(4.0f, 1.0f, 0.f);

				//Nubes
				glColor4f(1, 1, 1, 1.0);
				glVertex3f(-9.0f, 8.0f, 0.f);
				glVertex3f(-9.0f, 6.0f, 0.f);

				glColor4f(1, 1, 1, 0.0);
				glVertex3f(-2.0f, 6.0f, 0.f);
				glVertex3f(-2.0f, 8.0f, 0.f);

				glColor4f(1, 1, 1, 1.0);
				glVertex3f(-6.0f, 7.0f, 0.f);
				glVertex3f(-6.0f, 5.0f, 0.f);

				glColor4f(1, 1, 1, 0.0);
				glVertex3f(1.0f, 5.0f, 0.f);
				glVertex3f(1.0f, 7.0f, 0.f);

		//SOL Amarillo
				glColor4f(1, 0.862, 0.180, 0.0);
				glVertex3f(-10.0f, 10.0f, 0.f);

				glColor4f(1, 0.862, 0.180, 0.0);
				glVertex3f(-15.0f, -15.0f, 0.f);

				glColor4f(1, 0.862, 0.180, 0.0);
				glVertex3f(10.0f, -10.0f, 0.f);

				glColor4f(1, 0.862, 0.180, 1.0);
				glVertex3f(10.0f, 10.0f, 0.f);

				//2 Naranja
				glColor4f(1, 0.568, 0.180,0.0f);
				glVertex3f(-10.0f, 10.0f, 0.f);

				glColor4f(1, 0.568, 0.180,0.0f);
				glVertex3f(-15.0f, -15.0f, 0.f);

				glColor4f(1, 0.568, 0.180,0.0f);
				glVertex3f(10.0f, -10.0f, 0.f);

				glColor4f(1, 0.568, 0.180,0.3f);
				glVertex3f(10.0f, 10.0f, 0.f);

					//Cara
					glColor3f(0.0, 0.0, 0.0);
					glVertex3f(8.0f, 9.0f, 0.f);
					glVertex3f(8.0f, 8.5f, 0.f);
					glVertex3f(8.5f, 8.0f, 0.f);
					glVertex3f(8.5f, 8.5f, 0.f);

					glVertex3f(9.0f, 8.0f, 0.f);
					glVertex3f(9.0f, 7.5f, 0.f);
					glVertex3f(9.5f, 7.0f, 0.f);
					glVertex3f(9.5f, 7.5f, 0.f);

					glVertex3f(7.3f, 9.0f, 0.f);
					glVertex3f(7.6f, 7.5f, 0.f);
					glVertex3f(9.0f, 6.0f, 0.f);
					glVertex3f(9.8f, 6.5f, 0.f);

		glEnd();












		//intercambia el framebuffer
		glfwSwapBuffers(window);
		//comprueba que algun disparador se halla activado (tales como el teclado, raton, etc)
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}