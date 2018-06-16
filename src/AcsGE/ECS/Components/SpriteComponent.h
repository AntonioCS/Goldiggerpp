#pragma once

#include "../Component.h"
#include "../../Sprite.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
	class SpriteComponent : public Component
	{
		Sprite m_sprite;
	public:
		SpriteComponent(Texture &texture, SDL_Rect s);
		~SpriteComponent() = default;

		Sprite &getSprite();
	};
}

