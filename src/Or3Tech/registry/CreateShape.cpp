#include <iostream>
#include <vector>
#include <Or3Tech/CreateShape.hpp>

Shape CreateShape::CreateCube(float x, float y , float z, bool pUp, bool pDown, bool pLeft, bool pRight, bool pForward, bool pBackward) {
	Shape ret;

	std::vector<GLfloat> verts;
	std::vector<GLfloat> uvs;

	std::vector<GLfloat> uv{
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f
	};

	std::vector<GLuint> indices{ 0, 1, 3, 0, 3, 2, 4, 5, 7, 4, 7, 6, 8, 9, 11, 8, 11, 10, 12, 13, 15, 12, 15, 14, 16, 17, 19, 16, 19, 18, 20, 21, 23, 20, 23, 22 };

	if(pBackward){
		std::vector<GLfloat> tempVert{x, y, z + 1.0f, x + 1.0f, y, z + 1.0f, x, y + 1.0f, z + 1.0f, x + 1.0f, y + 1.0f, z + 1.0f};
		
		verts.reserve(verts.size() + tempVert.size());
		verts.insert(verts.end(), tempVert.begin(), tempVert.end());
		uvs.reserve(uvs.size() + uv.size());
		uvs.insert(uvs.end(), uv.begin(), uv.end());
	}

	if (pForward) {
		std::vector<GLfloat> tempVert{ x + 1.0f, y, z + 1.0f, x + 1.0f, y, z, x + 1.0f, y + 1.0f, z + 1.0f, x + 1.0f, y + 1.0f, z};
		verts.reserve(verts.size() + tempVert.size());
		verts.insert(verts.end(), tempVert.begin(), tempVert.end());
		uvs.reserve(uvs.size() + uv.size());
		uvs.insert(uvs.end(), uv.begin(), uv.end());
	}

	if (pRight) {
		std::vector<GLfloat> tempVert{x + 1.0f, y, z, x, y, z, x + 1.0f, y + 1.0f, z, x, y + 1.0f, z };
		verts.reserve(verts.size() + tempVert.size());
		verts.insert(verts.end(), tempVert.begin(), tempVert.end());
		uvs.reserve(uvs.size() + uv.size());
		uvs.insert(uvs.end(), uv.begin(), uv.end());
	}

	if (pLeft) {
		std::vector<GLfloat> tempVert{ x, y, z, x, y, z + 1.0f, x, y + 1.0f, z, x, y + 1.0f, z + 1.0f };
		verts.reserve(verts.size() + tempVert.size());
		verts.insert(verts.end(), tempVert.begin(), tempVert.end());
		uvs.reserve(uvs.size() + uv.size());
		uvs.insert(uvs.end(), uv.begin(), uv.end());
	}

	if (pDown) {
		std::vector<GLfloat> tempVert{ x, y, z, x + 1.0f, y, z, x, y, z + 1.0f, x + 1.0f, y, z + 1.0f };
		verts.reserve(verts.size() + tempVert.size());
		verts.insert(verts.end(), tempVert.begin(), tempVert.end());
		uvs.reserve(uvs.size() + uv.size());
		uvs.insert(uvs.end(), uv.begin(), uv.end());
	}

	if (pUp) {
		std::vector<GLfloat> tempVert{ x, y + 1.0f, z + 1.0f, x + 1.0f, y + 1.0f, z + 1.0f, x, y + 1.0f, z, x + 1.0f, y + 1.0f, z };
		verts.reserve(verts.size() + tempVert.size());
		verts.insert(verts.end(), tempVert.begin(), tempVert.end());
		uvs.reserve(uvs.size() + uv.size());
		uvs.insert(uvs.end(), uv.begin(), uv.end());
	}

	ret.verticies.reserve(ret.verticies.size() + verts.size());
	ret.uvs.reserve(ret.uvs.size() + uvs.size());
	ret.indices.reserve(ret.indices.size() + indices.size());
	ret.verticies.insert(ret.verticies.end(), verts.begin(), verts.end());
	ret.uvs.insert(ret.uvs.end(), uvs.begin(), uvs.end());
	ret.indices.insert(ret.indices.end(), indices.begin(), indices.end());
	return ret;

}

Shape CreateShape::CreateCube() {
	return CreateCube(0, 0, 0, true, true, true, true, true, true);
}