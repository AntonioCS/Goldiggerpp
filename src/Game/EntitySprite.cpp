#include "EntitySprite.h"

EntitySprite::EntitySprite(AcsGameEngine::Texture *texture, SDL_Rect s) : m_sprite(texture, s)
{
}

EntitySprite::~EntitySprite()
{
}

AcsGameEngine::Sprite & EntitySprite::getSprite() noexcept
{
	return m_sprite;
}
