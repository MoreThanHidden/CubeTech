#include "Or3Tech/Game.hpp"
#include <iostream>
// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

#include <Or3Tech/texture.hpp>
#include <Or3Tech/controls.hpp>
#include <Or3Tech/Shape.hpp>
#include <Or3Tech/CreateShape.hpp>
#include <Or3Tech/Render.hpp>
#include <Or3Tech/Chunk.hpp>
#include <Or3Tech/TextureRegistry.hpp>

void Game::run() {

	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Ore World", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.");
		getchar();
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	TextureRegistry TextureReg;

	Render* Renderer = new Render;
	Chunk chunk = Chunk();
	Renderer->prep();
	Shape shapechunk = chunk.CreateMesh();
	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	


	CreateShape shapemaker;
	Shape cube = shapemaker.CreateCube();

	do {
			Renderer->beginDo();

			Renderer->bindTexture(TextureReg, TextureReg.TEXTURE_NOTEXTURE);
			

			Renderer->build(shapechunk);

			glfwSwapBuffers(window);
			glfwPollEvents();

		} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
	}

	int Game::quit() {

		// Close OpenGL window and terminate GLFW
		glfwTerminate();

		return 0;
	}