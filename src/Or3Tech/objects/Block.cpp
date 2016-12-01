#include <Or3Tech\Block.hpp>

Block::Block(){
	m_active = false;
	m_solid = true;
}

Block::Block(BlockType type) {
	m_active = true;
	m_solid = true;
	m_blockType = type;
}

Block::~Block() {

}

bool Block::IsActive() {
	return m_active;
}
bool Block::IsSolid() {
	if (IsActive()) {
	return m_solid;
	} else {
	return false;
	}
	
}

SidedTexture Block::GetTexture(TextureRegistry * texreg) {
	GLuint top;
	GLuint side = texreg->getTexture(texreg->TEXTURE_NOTEXTURE);
	GLuint bottom;

	switch (m_blockType){
		case BlockType::BlockType_Grass:
			top = texreg->getTexture(texreg->TEXTURE_GRASSTOP);
			side = texreg->getTexture(texreg->TEXTURE_GRASS);
			bottom = texreg->getTexture(texreg->TEXTURE_DIRT);
			return texreg->newSidedTexture(side, side, side, side, bottom, top);
		case BlockType::BlockType_Stone:
			side = texreg->getTexture(texreg->TEXTURE_STONE);
			break;
		case BlockType::BlockType_Sand:
			side = texreg->getTexture(texreg->TEXTURE_SAND);
			break;
		case BlockType::BlockType_Dirt:
			side = texreg->getTexture(texreg->TEXTURE_DIRT);
			break;
	}	
	return texreg->newSidedTexture(side, side, side, side, side, side);
}

void Block::SetActive(bool active) {
	if (!m_active) {
		m_active = active;
	}
}

BlockType Block::GetType() {
	return m_blockType;
}