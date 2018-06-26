#pragma once

#include "../AcsGE/ECS/Component.h"
#include <SDL2/SDL.h>

class OverlayComponent : public AcsGameEngine::ECS::Component {
	SDL_Rect m_rect;
public:
	OverlayComponent(int x, int y) {
		m_rect.x = x;
		m_rect.y = y;
		m_rect.w = 64;
		m_rect.y = 64;
	}
};