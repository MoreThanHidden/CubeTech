#include <Or3Tech/Render.hpp>
#include <Or3Tech/shader.hpp>
#include <Or3Tech/texture.hpp>
#include <Or3Tech/controls.hpp>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

void Render::prep() {
	programID = LoadShaders("data/shaders/default.vert.glsl", "data/shaders/default.frag.glsl");
	MatrixID = glGetUniformLocation(programID, "MVP");
	TextureID = glGetUniformLocation(programID, "myTextureSampler");
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
}


void Render::build(Shape shape) {

	if (!activebuffer) {
	activebuffer = true;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, shape.verticies.size() * sizeof(GLfloat), &shape.verticies.front(), GL_STATIC_DRAW);

	glGenBuffers(1, &ebobuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebobuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape.indices.size() * sizeof(GLuint), &shape.indices.front(), GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, shape.uvs.size() * sizeof(GLfloat), &shape.uvs.front(), GL_STATIC_DRAW);

	}
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	int size;  glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

void Render::bindTexture(TextureRegistry textureReg, enum TextureRegistry::TextureEnum textureEnum) {
	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	Texture = textureReg.getTexture(textureEnum);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glUniform1i(TextureID, 0);
}

void Render::beginDo() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(programID);

	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs();
	glm::mat4 MVP = getMVP();

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

Render::~Render() {
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &ebobuffer);
	// Cleanup VBO and shader
	glDeleteProgram(programID);
	glDeleteTextures(1, &TextureID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

