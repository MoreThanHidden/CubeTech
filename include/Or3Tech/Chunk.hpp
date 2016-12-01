#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <GL/glew.h>
#include <fstream>
#include <Or3Tech/Block.hpp>
#include <Or3Tech/Render.hpp>
#include <Or3Tech/Shape.hpp>
#include <Or3Tech/ChunkPos.hpp>
#include <Or3Tech/controls.hpp>
#include <Or3Tech/CreateShape.hpp>
#include <Or3Tech/SidedTexture.hpp>

class Chunk{
	public:
		Chunk();
		virtual ~Chunk();
		ChunkPos pos = ChunkPos(0, 0);
		int loadedID;

		void Update(float dt);
		Block Chunk::getBlock(uint x, uint y, uint z);
		void Chunk::setBlock(uint x, uint y, uint z, Block block);
		void CreateMesh(Shape * shape, TextureRegistry * texreg);
		void saveToFile(std::ofstream &outfile);
		void loadFromFile(std::ifstream &infile);

		static const int CHUNK_SIZE = 16;
		static const int CHUNK_HEIGHT = 256;

	private:
		// The blocks data
		Block*** m_pBlocks;
		Shape shape;
		Render *Renderer;
	
};	

#endif