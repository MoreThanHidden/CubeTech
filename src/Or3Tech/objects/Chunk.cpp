#include <Or3Tech/Chunk.hpp>
#include <Or3Tech/Block.hpp>

	Chunk::Chunk() {
		
		// Create the blocks
		m_pBlocks = new Block**[CHUNK_SIZE];
		for (int i = 0; i < CHUNK_SIZE; i++){

			m_pBlocks[i] = new Block*[CHUNK_HEIGHT];

			for (int j = 0; j < CHUNK_HEIGHT; j++){
				m_pBlocks[i][j] = new Block[CHUNK_SIZE];
			}

		}

	}

	Chunk::~Chunk() {
		// Delete the blocks
		for (int i = 0; i < CHUNK_SIZE; ++i)
		{
			for (int j = 0; j < CHUNK_HEIGHT; ++j){
				delete[] m_pBlocks[i][j];
			}

			delete[] m_pBlocks[i];
		}
		delete[] m_pBlocks;
	}

	void Chunk::Update(float dt){
	
	}

	Block Chunk::getBlock(uint x, uint y, uint z) {
		if ((x < CHUNK_SIZE) && (z < CHUNK_SIZE) && (y < CHUNK_HEIGHT)){
		return m_pBlocks[x][y][z];
		}
	}

	void Chunk::setBlock(uint x, uint y, uint z, Block block) {
		if ((x < CHUNK_SIZE) && (z < CHUNK_SIZE) && (y < CHUNK_HEIGHT)) {
			m_pBlocks[x][y][z] = block;
		}
	}


	void Chunk::CreateMesh(Shape * shape, TextureRegistry * texreg){

		for (int x = 0; x < CHUNK_SIZE; x++){

			for (int y = 0; y < CHUNK_HEIGHT; y++){

				for (int z = 0; z < CHUNK_SIZE; z++){

					if (m_pBlocks[x][y][z].IsActive() == false)	{
						continue;
					}
					CreateShape cshape;
					int renX = (pos.x) << 3;
					int renZ = (pos.z) << 3;
					bool bUp = true; if ((y + 1) < CHUNK_HEIGHT) { bUp = !m_pBlocks[x][y + 1][z].IsSolid(); };
					bool bDown = true; if ((y - 1) >= 0) { bDown = !m_pBlocks[x][y - 1][z].IsSolid(); };
					bool bRight = true; if ((x + 1) < CHUNK_SIZE) { bRight = !m_pBlocks[x + 1][y][z].IsSolid(); };
					bool bLeft = true; if ((x - 1) >= 0) { bLeft = !m_pBlocks[x - 1][y][z].IsSolid(); };
					bool bFront = true; if ((z + 1) < CHUNK_SIZE) { bFront = !m_pBlocks[x][y][z + 1].IsSolid(); };
					bool bBack = true; if ((z - 1) >= 0) { bBack = !m_pBlocks[x][y][z - 1].IsSolid(); };
					cshape.CreateCube(shape, renX + x, y, renZ + z, bUp, bDown, bLeft, bBack, bRight, bFront, m_pBlocks[x][y][z].GetTexture(texreg));
				}

			}

		}

	}

	void Chunk::saveToFile(std::ofstream &outfile){
		for (int x = 0; x < CHUNK_SIZE; x++)
			for (int y = 0; y < CHUNK_HEIGHT; y++)
					outfile.write((char *)m_pBlocks[x][y], CHUNK_SIZE);
		outfile.close();
	}

	void Chunk::loadFromFile(std::ifstream &infile) {
		for (int x = 0; x < CHUNK_SIZE; x++)
			for (int y = 0; y < CHUNK_HEIGHT; y++)
					infile.read((char *)m_pBlocks[x][y], CHUNK_SIZE);
		infile.close();
	}