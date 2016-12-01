#ifndef SIDEDTEXTURE_HPP
#define SIDEDTEXTURE_HPP
#include <GL/glew.h>

class SidedTexture {
	public:
		GLuint TexBack;
		GLuint TexFront;
		GLuint TexRight;
		GLuint TexLeft;
		GLuint TexDown;
		GLuint TexUp;
};
#endif
