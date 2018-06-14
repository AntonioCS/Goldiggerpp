#pragma once

#include "Entity.h"
#include <SDL2/SDL_main.h>
#include "..\AcsGE\Texture.h"
#include "..\AcsGE\Sprite.h"

class EntitySprite : public Entity
{
	AcsGameEngine::Sprite m_sprite;
public:
	EntitySprite(AcsGameEngine::Texture *texture, SDL_Rect s);
	~EntitySprite();

	AcsGameEngine::Sprite &getSprite() noexcept;
};

