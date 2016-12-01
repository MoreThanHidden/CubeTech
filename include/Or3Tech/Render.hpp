#ifndef RENDER_HPP
#define RENDER_HPP
#include <Or3Tech/Shape.hpp>
#include <Or3Tech/TextureRegistry.hpp>
#include <GL/glew.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

class Render {
public:	
	void beginDo();
	void prep();
	void build(Shape * shape);
	void update();
	~Render();
private:
	int vertexCount;
	GLuint vertexbuffer;
	GLuint ebobuffer;
	GLuint uvbuffer;
	GLuint Texturebuffer;
	bool activebuffer = false;
	GLuint Texture;
	GLuint TextureID;
	GLuint programID;
	GLuint MatrixID;
	GLuint VertexArrayID;
};
#endif