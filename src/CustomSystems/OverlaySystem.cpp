#include "OverlaySystem.h"
#include "../CustomComponents/MapItemComponent.h"
#include <SDL2/SDL.h>
#include <iostream>

void OverlaySystem::init()
{
	m_vecRef = m_entityManager.findByComponent<MapItemComponent>();
	m_eventManager.attach(SDL_MOUSEBUTTONUP, [this](SDL_Event &e) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			std::cout << "X: " <<
				m_previousEntity->getComponent<MapItemComponent>().x <<
				" - - Y: " 	<< m_previousEntity->getComponent<MapItemComponent>().y
				<< '\n';
		}
	});
}

void OverlaySystem::update(float dt)
{
	int mouseX;
	int mouseY;

	SDL_GetMouseState(&mouseX, &mouseY);
	SDL_Rect a{};
	SDL_Rect b{};


	if (mouseX == 0 && mouseY == 0) {
		return;
	}

	for (const auto ref : m_vecRef) {
		auto &e = ref.get();
		auto &c = e.getComponent<MapItemComponent>();

		if (mouseX >= c.x && mouseY >= c.y && mouseX <= c.x + c.w && mouseY <= c.y + c.h) {
			if (m_previousEntity != nullptr) {
				m_previousEntity->getComponent<MapItemComponent>().fill = false;
			}

			c.fill = true;
			m_previousEntity = &e;

			break;
		}
	}
}

void OverlaySystem::render()
{

}

