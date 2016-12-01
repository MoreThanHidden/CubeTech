#include <Or3Tech/TextureRegistry.hpp>

TextureRegistry::TextureRegistry() {
	TextureRegistry::Stone = loadBMP_custom("textures/stone.bmp");
	TextureRegistry::Grass = loadBMP_custom("textures/grass.bmp");
	TextureRegistry::GrassTop = loadBMP_custom("textures/grasstop.bmp");
	TextureRegistry::Dirt = loadBMP_custom("textures/dirt.bmp");
	TextureRegistry::Sand = loadBMP_custom("textures/sand.bmp");
	TextureRegistry::Gravel = loadBMP_custom("textures/gravel.bmp");
	TextureRegistry::NoTexture = loadBMP_custom("textures/notexture.bmp");
}

GLuint TextureRegistry::getTexture(TextureRegistry::TextureEnum Texture) {
	switch (Texture){
	case TEXTURE_STONE:
		return Stone;
	case TEXTURE_GRASS:
		return Grass;
	case TEXTURE_GRASSTOP:
		return GrassTop;
	case TEXTURE_DIRT:
		return Dirt;
	case TEXTURE_SAND:
		return Sand;
	case TEXTURE_GRAVEL:
		return Gravel;
	default:
		return NoTexture;
	}
}

SidedTexture TextureRegistry::newSidedTexture(GLuint TexBack, GLuint TexFront, GLuint TexRight, GLuint TexLeft, GLuint TexDown, GLuint TexUp) {
	SidedTexture texture;
	texture.TexBack = TexBack;
	texture.TexFront = TexFront;
	texture.TexRight = TexRight;
	texture.TexLeft = TexLeft;
	texture.TexDown = TexDown;
	texture.TexUp = TexUp;
	return texture;
}
