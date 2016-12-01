#ifndef GAME_HPP
#define GAME_HPP
// Include GLEW
#include <GL/glew.h>
#include <Or3Tech/Render.hpp>


class Game{
public:
	void run();
	int quit();

private:
	Render *Renderer;
};

#endif