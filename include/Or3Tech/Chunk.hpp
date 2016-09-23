#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <Or3Tech/Block.hpp>
#include <Or3Tech/Render.hpp>
#include <Or3Tech/Shape.hpp>
#include <Or3Tech/controls.hpp>
#include <Or3Tech/CreateShape.hpp>

class Chunk{
	public:
		Chunk();
		virtual ~Chunk();

		void Update(float dt);

		void CreateMesh();
		void CreateCube(int x, int y, int z, bool bUp, bool bDown, bool bLeft, bool bRight, bool bFront, bool vbBack);

		static const int CHUNK_SIZE = 16;

	private:
		// The blocks data
		Block*** m_pBlocks;
		Shape shape;
	
};	

#endif