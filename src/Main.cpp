#include <iostream>

#include <GLFW/glfw3.h>

#include <Or3Tech/Common.hpp>

GLOBAL int g_windowWidth = 854;
GLOBAL int g_windowHight = 480;

int main(int argc, char** argv) {
	
	GLFWwindow* window;

	if (!glfwInit())
		return EXIT_FAILURE;

	window = glfwCreateWindow(g_windowWidth, g_windowHight, "Or3Tech", nullptr, nullptr);
		if (!window) {

			glfwTerminate();
			return EXIT_FAILURE;

		}

		glfwMakeContextCurrent(window);

		bool running = true;
		bool fullscreen = false;
		while (running) {

			glClearColor(0.5f, 0.69f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();

			if (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE))
				running = false;

			if (glfwGetKey(window, GLFW_KEY_F11)){
				fullscreen = !fullscreen;
				GLFWwindow* newWindow;

				if (fullscreen) {
					newWindow = glfwCreateWindow(1680, 1050, "Or3Tech", glfwGetPrimaryMonitor(), window);
				}else{
					newWindow = glfwCreateWindow(g_windowWidth, g_windowHight, "Or3Tech", nullptr, window);
				}
				
				glfwDestroyWindow(window);
				window = newWindow;
				glfwMakeContextCurrent(window);

			}
		}

		glfwTerminate();
		return EXIT_SUCCESS;
}