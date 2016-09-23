#ifndef CREATESHAPE_HPP
#define CREATESHAPE_HPP
#include <GL/glew.h>
#include <Or3Tech/Shape.hpp>

class CreateShape {
public:
	Shape CreateCube();
	Shape CreateCube(float x, float y, float z, bool pUp, bool pDown, bool pLeft, bool pRight, bool pForward, bool pBackward);
};
#endif