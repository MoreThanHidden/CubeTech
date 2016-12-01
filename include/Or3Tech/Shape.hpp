#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <GL/glew.h>
#include <vector>

class Shape {
public:
	std::vector<GLfloat> verticies;
	std::vector<GLuint> indices;
	std::vector<GLfloat> uvs;
	std::vector<GLuint> textures;
};
#endif
