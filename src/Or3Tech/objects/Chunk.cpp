#include <Or3Tech/Chunk.hpp>
#include <Or3Tech/Block.hpp>

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


void Chunk::CreateMesh(){

		for (int x = 0; x < CHUNK_SIZE; x++){

			for (int y = 0; y < CHUNK_SIZE; y++){

				for (int z = 0; z < CHUNK_SIZE; z++){

					if (m_pBlocks[x][y][z].IsActive() == false)	{
						continue;
					}

					bool bUp = true; if ((y + 1) < CHUNK_SIZE) { bUp = !m_pBlocks[x][y + 1][z].IsSolid(); };
					bool bDown = true; if ((y - 1) > 0) { bDown = !m_pBlocks[x][y - 1][z].IsSolid(); };
					bool bRight = true; if ((x + 1) < CHUNK_SIZE) { bRight = !m_pBlocks[x + 1][y][z].IsSolid(); };
					bool bLeft = true; if ((x - 1) > 0) { bLeft = !m_pBlocks[x - 1][y][z].IsSolid(); };
					bool bFront = true; if ((z + 1) < CHUNK_SIZE) { bFront = !m_pBlocks[x][y][z + 1].IsSolid(); };
					bool bBack = true; if ((z - 1) > 0) { bBack = !m_pBlocks[x][y][z - 1].IsSolid(); };

					CreateCube(x, y, z, bUp, bDown, bLeft, bRight, bFront, bBack);
				}

			}

		}

	}

	void Chunk::CreateCube(int x, int y, int z, bool bUp, bool bDown, bool bLeft, bool bRight, bool bFront, bool bBack) {

		CreateShape shapemaker;
		Shape tempShape = shapemaker.CreateCube(x, y, z, bUp, bDown, bLeft, bRight, bFront, bBack);
	}