#include <Or3Tech\Block.hpp>

Block::Block(){
	m_active = true;
	m_solid = true;
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

void Block::SetActive() {
	if (!m_active) {
		m_active = true;
	}
}