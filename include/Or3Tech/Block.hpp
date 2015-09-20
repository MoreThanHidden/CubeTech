#ifndef OR3TECH_BLOCK_HPP
#define OR3TECH_BLOCK_HPP

namespace Or3Tech {

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
		void SetActive(bool active);

	private:
		bool m_active;

		BlockType m_blockType;
	};

}//namesapce Or3Tech

#endif