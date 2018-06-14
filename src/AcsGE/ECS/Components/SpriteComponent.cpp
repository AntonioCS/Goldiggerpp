#include "SpriteComponent.h"
#include <utility>

namespace AcsGameEngine::ECS {
	SpriteComponent::SpriteComponent(Texture  *texture, SDL_Rect s) : m_sprite(texture, s)
	{
	}
	Sprite & SpriteComponent::getSprite()
	{
		return m_sprite;
	}
}