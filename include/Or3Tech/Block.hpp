#ifndef BLOCK_HPP
#define BLOCK_HPP

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
		virtual ~Block();

		bool IsActive();
		void SetActive();
		bool IsSolid();

	private:
		bool m_active;
		bool m_solid;
		BlockType m_blockType;
};
#endif