#include "cutscene.hpp"

Cutscene::Cutscene(State * state) {
	m_position = 0;
	m_curr_img = &m_sprites[m_position];
	m_state = state;
}

Cutscene::~Cutscene() {
	delete[] &m_sprites;
}

void Cutscene::handleEvent(const SDL_Event& e) {
	if (e.type == SDL_SCANCODE_RIGHT && m_position < size(m_sprites)-1) m_curr_img = &m_sprites[m_position++];
	else if (e.type == SDL_SCANCODE_LEFT && m_position > 0) m_curr_img = &m_sprites[m_position--];
}

void Cutscene::update(int delta) {
	m_state->update(delta);
}

void Cutscene::render() {
	m_state->render();
}
