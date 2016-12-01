#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <GL/glew.h>
#include <Or3Tech/TextureRegistry.hpp>

enum class BlockType {
		BlockType_Default = 0,

		BlockType_Stone,
		BlockType_Sand,
		BlockType_Water,
		BlockType_Dirt,
		BlockType_Grass,

};

	class Block{
	public:
		Block();
		Block(BlockType type);
		virtual ~Block();

		bool IsActive();
		void SetActive(bool active);
		bool IsSolid();
		SidedTexture GetTexture(TextureRegistry * texreg);
		BlockType GetType();

	private:
		bool m_active;
		bool m_solid;
		BlockType m_blockType;
};
#endif