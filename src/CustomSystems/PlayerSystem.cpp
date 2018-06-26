#include "PlayerSystem.h"
#include "../AcsGE/ECS/EntityManager.h"
#include "../AcsGE/ECS/Entity.h"
#include "../AcsGE/ECS/Components/SpriteComponent.h"
#include "../CustomComponents/PlayerComponent.h"


PlayerSystem::PlayerSystem(AcsGameEngine::ECS::EntityManager & em, AcsGameEngine::EventManager & eventManager) : AcsGameEngine::ECS::System(em), m_eventManager(eventManager)
{
}

PlayerSystem::~PlayerSystem()
{
}

void PlayerSystem::init()
{
	m_vecRef = m_entityManager.findByComponent<AcsGameEngine::ECS::SpriteComponent, PlayerComponent>();
}

void PlayerSystem::update(float dt)
{
}

void PlayerSystem::render()
{

}

