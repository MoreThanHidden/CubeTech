#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Or3Tech/Common.hpp>
#include <Or3Tech/ShaderProgram.hpp>

GLOBAL const int g_windowWidth = 854;
GLOBAL const int g_windowHeight = 480;

INTERNAL void glfwHints()
{
	glfwWindowHint(GLFW_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_VERSION_MINOR, 1);
}

int main(int argc, char** argv)
{
	GLFWwindow* window;

	if (!glfwInit())
		return EXIT_FAILURE;


	glfwHints();
	window = glfwCreateWindow(g_windowWidth, g_windowHeight, "Or3Tech", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glewInit();

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	float vertices[] = {
		// x,    y,    r,   g,    b
		+0.5f, +0.5f, 1.0f, 1.0f, 1.0f,// Vertex 0
		-0.5f, +0.5f, 0.0f, 0.0f, 1.0f,// Vertex 1
		+0.5f, -0.5f, 0.0f, 1.0f, 0.0f,// Vertex 2
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f,// Vertex 3
	};


	GLuint vbo; // Vertex Buffer Object
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	Or3Tech::ShaderProgram shaderProgram;
	shaderProgram.attachShaderFromFile(Or3Tech::ShaderType::Vertex, "data/shaders/default.vert.glsl");
	shaderProgram.attachShaderFromFile(Or3Tech::ShaderType::Fragment, "data/shaders/default.frag.glsl");

	shaderProgram.bindAttribLocation(0, "vertPosition");
	shaderProgram.bindAttribLocation(1, "vertColor");
	shaderProgram.link();
	shaderProgram.use();


	bool running = true;
	bool fullscreen = false;
	while (running){
		

		glClearColor(0.5f, 0.69f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);{

			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const GLvoid*)(2 * sizeof(float)));

			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
		}


		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwWindowShouldClose(window) ||
			glfwGetKey(window, GLFW_KEY_ESCAPE))
			running = false;

		if (glfwGetKey(window, GLFW_KEY_F11)){
			fullscreen = !fullscreen;

			GLFWwindow* newWindow;

			glfwHints();
			if (fullscreen){

				int count;
				const GLFWvidmode* modes =
					glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);
					newWindow = glfwCreateWindow(modes[count - 1].width, modes[count - 1].height, "Or3Tech", glfwGetPrimaryMonitor(), window);

				}else{

					newWindow = glfwCreateWindow(g_windowWidth, g_windowHeight, "Or3Tech", nullptr, window);

				}
				
				glfwDestroyWindow(window);
				window = newWindow;
				glfwMakeContextCurrent(window);

			}

		}

		glfwTerminate();
		return EXIT_SUCCESS;
}