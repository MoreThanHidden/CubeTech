#ifndef OR3TECH_CHUNK_HPP
#define OR3TECH_CHUNK_HPP

#include <Or3Tech/Block.hpp>
#include <Or3Tech/ShaderProgram.hpp>

namespace Or3Tech {

	class Chunk{
	public:
		Chunk();
		virtual ~Chunk();

		void Update(float dt);

		void Render(ShaderProgram* pRenderer);

		void CreateMesh();
		void CreateCube();

		void Render(ShaderProgram * pRenderer, bool translateTexture);

		static const int CHUNK_SIZE = 16;

	private:
		// The blocks data
		Block*** m_pBlocks;
	
	};	

}//namesapce Or3Tech

#endif