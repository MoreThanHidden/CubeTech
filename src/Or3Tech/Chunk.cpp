#include <Or3Tech/Chunk.hpp>

#include <Or3Tech/Block.hpp>
#include <Or3Tech/ShaderProgram.hpp>

namespace Or3Tech {

	Chunk::Chunk() {
		// Create the blocks
		m_pBlocks = new Block**[CHUNK_SIZE];
		for (int i = 0; i < CHUNK_SIZE; i++)
		{
			m_pBlocks[i] = new Block*[CHUNK_SIZE];

			for (int j = 0; j < CHUNK_SIZE; j++)
			{
				m_pBlocks[i][j] = new Block[CHUNK_SIZE];
			}
		}
	}

	Chunk::~Chunk() {
		// Delete the blocks
		for (int i = 0; i < CHUNK_SIZE; ++i)
		{
			for (int j = 0; j < CHUNK_SIZE; ++j)
			{
				delete[] m_pBlocks[i][j];
			}

			delete[] m_pBlocks[i];
		}
		delete[] m_pBlocks;
	}

	void Chunk::Update(float dt){

	}

	void Chunk::Render(ShaderProgram* pRenderer){

	}

	void Chunk::CreateMesh(){

		for (int x = 0; x < CHUNK_SIZE; x++){

			for (int y = 0; y < CHUNK_SIZE; y++){

				for (int z = 0; z < CHUNK_SIZE; z++){

					if (m_pBlocks[x][y][z].IsActive() == false)	{
						// Don't create triangle data for inactive blocks
						continue;
					}

					CreateCube();
				}

			}

		}

	}

	void Chunk::CreateCube() {


	}



}