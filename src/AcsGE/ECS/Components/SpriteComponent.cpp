#include "SpriteComponent.h"
#include <utility>
#include "../../Texture.h"

namespace AcsGameEngine::ECS {
	SpriteComponent::SpriteComponent(Texture &texture, SDL_Rect s) : m_sprite(texture, s)
	{
	}
	Sprite & SpriteComponent::getSprite()
	{
		return m_sprite;
	}
}