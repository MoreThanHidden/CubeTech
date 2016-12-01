#ifndef TEXTUREREGISTRY_HPP
#define TEXTUREREGISTRY_HPP
#include <Or3Tech/texture.hpp>
#include <Or3Tech/SidedTexture.hpp>
#include <GL/glew.h>

class TextureRegistry{
private:
GLuint Stone;
GLuint Grass;
GLuint GrassTop;
GLuint Dirt;
GLuint Sand;
GLuint Gravel;
GLuint NoTexture;

public:
enum TextureEnum{
	TEXTURE_NOTEXTURE,
	TEXTURE_STONE,
	TEXTURE_GRASS,
	TEXTURE_GRASSTOP,
	TEXTURE_DIRT,
	TEXTURE_SAND,
	TEXTURE_GRAVEL
};
TextureRegistry();
GLuint getTexture(TextureRegistry::TextureEnum Texture);
SidedTexture newSidedTexture(GLuint TexBack, GLuint TexFront, GLuint TexRight, GLuint TexLeft, GLuint TexDown, GLuint TexUp);

};

#endif


