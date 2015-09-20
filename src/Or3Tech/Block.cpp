#include <Or3Tech\Block.hpp>


namespace Or3Tech {

	Block::Block(){

	}

	Block::~Block() {

	}

	bool Block::IsActive() {
		return m_active;
	}

	void Block::SetActive(bool active) {
		if (!m_active) {
			m_active = true;
		}
	}

}