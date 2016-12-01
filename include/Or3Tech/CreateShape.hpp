#ifndef CREATESHAPE_HPP
#define CREATESHAPE_HPP
#include <GL/glew.h>
#include <Or3Tech/Shape.hpp>
#include <Or3Tech/SidedTexture.hpp>

class CreateShape {
public:
	void CreateCube(Shape* ret, SidedTexture Texture);
	void CreateCube(Shape* ret, float x, float y, float z, bool pUp, bool pDown, bool pLeft, bool pRight, bool pForward, bool pBackward, SidedTexture Texture);
	void AddtoShape(Shape * ret, std::vector<GLuint> ind, std::vector<GLfloat> verts, std::vector<GLfloat> uvs, std::vector<GLuint> textures);
};
#endif