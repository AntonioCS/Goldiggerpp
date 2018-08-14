#include <iostream>
#include <SDL2/SDL.h>

#include "PlayerSystem.h"
#include "../AcsGE/ECS/EntityManager.h"
#include "../AcsGE/ECS/Entity.h"
#include "../AcsGE/ECS/Components/SpriteComponent.h"
#include "../AcsGE/ECS/Components/PositionComponent.h"
#include "../CustomComponents/PlayerComponent.h"
#include "../AcsGE/Util/Vector2D.h"


PlayerSystem::PlayerSystem(AcsGameEngine::ECS::EntityManager & em, AcsGameEngine::EventManager & eventManager) :
	AcsGameEngine::ECS::System(em), m_eventManager(eventManager)
{
}

PlayerSystem::~PlayerSystem()
{
}



void PlayerSystem::init()
{
	m_vecRef = m_entityManager.findByComponent<
		PlayerComponent,
		AcsGameEngine::ECS::PositionComponent,
		AcsGameEngine::ECS::SpriteComponent
	>();

	if (m_vecRef.size() != 1) {
		throw "Wrong number of player entity";
	}

	m_player = &(m_vecRef.at(0).get());
	//m_position = &(m_player->getComponent<AcsGameEngine::ECS::PositionComponent>());
	//m_sprite = &(m_player->getComponent<AcsGameEngine::ECS::SpriteComponent>());

	auto func = [this](SDL_Event &event, bool state) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			m_leftPressed = state;
			break;
		case SDLK_RIGHT:
			m_rightPressed = state;
			break;
		case SDLK_UP:
			m_upPressed = state;
			break;
		case SDLK_DOWN:
			m_downPressed = state;
			break;
		}
	};

	m_eventManager.onKeyDown([func](SDL_Event &event) {
		func(event, true);
	});

	m_eventManager.onKeyUp([func](SDL_Event &event) {
		func(event, false);
	});

	//m_eventManager.
	//https://stackoverflow.com/questions/43683569/sdl2-and-measuring-the-time-a-key-is-pressed
/*		case SDLK_LEFT:
			buttons[Back].pressed = true;   // Toggle Back button to pressed
			cout << "Back held" << endl;
			// TODO Measure elapsed time and artificially toggle the pressed state to false if > 5s
			break;
		case SDLK_DOWN:
			buttons[Reset].pressed = true;  // Toggle Reset button to pressed
			break;
		}
		break;
	case SDL_KEYUP:     // Key released
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			if (buttons[Back].pressed) {
				// TODO Measure elapsed time and print "Back emitted" if less than 5s
				buttons[Back].pressed = false;  // Toggle Back button to unpressed and emit Back event
			}
			break;
		case SDLK_DOWN:
			buttons[Reset].pressed = false; // Toggle Reset button to unpressed
			cout << "Reset emitted" << endl;
			break;
		}
		break;

})*;*/
}

//void PlayerSystem::update(std::chrono::milliseconds dt)
void PlayerSystem::update(float dt)
{
	static auto &sprite = m_player->getComponent<AcsGameEngine::ECS::SpriteComponent>().getSprite();
	static auto &positon = m_player->getComponent<AcsGameEngine::ECS::PositionComponent>().getPosition();
	int moveValue = 550;

	if (m_leftPressed) {
		SDL_Rect recs = sprite.getDestination();

		positon -= AcsGameEngine::Util::Vector2D{ moveValue * dt , 0};

		sprite.setDestinationXY(
			static_cast<int>(positon.getX()),
			static_cast<int>(positon.getY())
		);
	}

	if (m_rightPressed) {
		SDL_Rect recs = sprite.getDestination();

		positon += AcsGameEngine::Util::Vector2D{ moveValue * dt , 0 };

		sprite.setDestinationXY(
			static_cast<int>(positon.getX()),
			static_cast<int>(positon.getY())
		);
	}

	if (m_downPressed) {
		SDL_Rect recs = sprite.getDestination();
		positon += AcsGameEngine::Util::Vector2D{ 0 , moveValue * dt };

		sprite.setDestinationXY(
			static_cast<int>(positon.getX()),
			static_cast<int>(positon.getY())
		);
	}

	if (m_upPressed) {
		SDL_Rect recs = sprite.getDestination();
		positon -= AcsGameEngine::Util::Vector2D{ 0 , moveValue * dt };

		sprite.setDestinationXY(
			static_cast<int>(positon.getX()),
			static_cast<int>(positon.getY())
		);
	}
}

void PlayerSystem::render()
{

}

