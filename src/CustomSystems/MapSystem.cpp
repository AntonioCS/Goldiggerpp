#include "MapSystem.h"
#include "../AcsGE/Util/ColorList.h"
//#include <iostream>


MapSystem::MapSystem(EntityManager & em, Renderer & renderer) : 
	AcsGameEngine::ECS::System(em), m_renderer(renderer) {}

MapSystem::~MapSystem()
{
}

void MapSystem::init()
{	
	m_vecRef = m_entityManager.findByComponent<MapItemComponent>();
}

void MapSystem::update(float dt)
{
}

void MapSystem::render()
{	
	using colorList = AcsGameEngine::Util::ColorList;
	SDL_Rect rect{};

	for (const auto ref : m_vecRef) {
		auto &e = ref.get();
		auto &c = e.getComponent<MapItemComponent>();

		rect.x = c.x;
		rect.y = c.y;
		rect.w = c.w;
		rect.h = c.h;
	
		m_renderer.DrawRect(rect, colorList::red, c.fill);
	}
}
