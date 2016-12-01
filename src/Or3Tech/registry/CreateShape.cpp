#include <iostream>
#include <vector>
#include <Or3Tech/CreateShape.hpp>

void CreateShape::CreateCube(Shape * ret, float x, float y , float z, bool pUp, bool pDown, bool pLeft, bool pRight, bool pForward, bool pBackward, SidedTexture Texture) {

	std::vector<GLfloat> uv{
		1.0f, 0.0f,
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	std::vector<GLuint> indices{ 0, 1, 3, 0, 3, 2};

	if (pUp) {
		std::vector<GLfloat> tempVert{ x, y + 1.0f, z + 1.0f, x + 1.0f, y + 1.0f, z + 1.0f, x, y + 1.0f, z, x + 1.0f, y + 1.0f, z };
		std::vector<GLuint> Textures{ Texture.TexUp };
		AddtoShape(ret, indices, tempVert, uv, Textures);
	}

	if(pBackward){
		std::vector<GLfloat> tempVert{x, y, z + 1.0f, x + 1.0f, y, z + 1.0f, x, y + 1.0f, z + 1.0f, x + 1.0f, y + 1.0f, z + 1.0f};
		std::vector<GLuint> Textures{ Texture.TexBack };
		AddtoShape(ret, indices, tempVert, uv, Textures);
	}

	if (pForward) {
		std::vector<GLfloat> tempVert{ x + 1.0f, y, z + 1.0f, x + 1.0f, y, z, x + 1.0f, y + 1.0f, z + 1.0f, x + 1.0f, y + 1.0f, z};
		std::vector<GLuint> Textures{ Texture.TexFront };
		AddtoShape(ret, indices, tempVert, uv, Textures);
	}

	if (pRight) {
		std::vector<GLfloat> tempVert{x + 1.0f, y, z, x, y, z, x + 1.0f, y + 1.0f, z, x, y + 1.0f, z };
		std::vector<GLuint> Textures{ Texture.TexRight };
		AddtoShape(ret, indices, tempVert, uv, Textures);
	}

	if (pLeft) {
		std::vector<GLfloat> tempVert{ x, y, z, x, y, z + 1.0f, x, y + 1.0f, z, x, y + 1.0f, z + 1.0f };
		std::vector<GLuint> Textures{ Texture.TexLeft };
		AddtoShape(ret, indices, tempVert, uv, Textures);
	}

	if (pDown) {
		std::vector<GLfloat> tempVert{ x, y, z, x + 1.0f, y, z, x, y, z + 1.0f, x + 1.0f, y, z + 1.0f };
		std::vector<GLuint> Textures{ Texture.TexDown };
		AddtoShape(ret, indices, tempVert, uv, Textures);
	}


}

void CreateShape::CreateCube(Shape * ret, SidedTexture Texture) {
	CreateCube(ret, 0, 0, 0, true, true, true, true, true, true, Texture);
}

void CreateShape::AddtoShape(Shape * ret, std::vector<GLuint> ind, std::vector<GLfloat> verts, std::vector<GLfloat> uvs, std::vector<GLuint> tex) {
	for (size_t i = 0; i < 6; i++) {
				ind[i] += ((ret->indices.size() / 6) * 4);
	}

	ret->verticies.reserve(ret->verticies.size() + verts.size());
	ret->verticies.insert(ret->verticies.end(), verts.begin(), verts.end());

	ret->uvs.reserve(ret->uvs.size() + uvs.size());
	ret->uvs.insert(ret->uvs.end(), uvs.begin(), uvs.end());

	ret->indices.reserve(ret->indices.size() + ind.size());
	ret->indices.insert(ret->indices.end(), ind.begin(), ind.end());

	ret->textures.reserve(ret->textures.size() + tex.size());
	ret->textures.insert(ret->textures.end(), tex.begin(), tex.end());
}