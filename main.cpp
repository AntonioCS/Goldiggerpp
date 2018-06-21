#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <sstream> //istringstream
#include <fstream> //ifstream

#include <chrono>
#include <memory>
#include <thread>

#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <stdexcept>
#include <string>
#include <array>

#include "src/AcsGE/EventManager.h"
#include "src/AcsGE/Renderer.h"
#include "src/AcsGE/Util/ColorList.h"
#include "src/AcsGE/Window.h"
#include "src/AcsGE/Texture.h"
#include "src/AcsGE/ECS/EntityManager.h"
#include "src/AcsGE/ECS/Components/SpriteComponent.h"
#include "src/Game.h"
#include "src/MapSystem.h"

int main(int argc, char *argv[])
{
	///*
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Unable to initialize SDL: " << SDL_GetError() << '\n';
		std::cin.get();
		exit(-1);
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if ((IMG_Init(imgFlags) & imgFlags) == 0) {
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << '\n';
		std::cin.get();
		exit(-1);
	}

	if (TTF_Init() == -1) {
		std::cout << "TTF_Init: " << TTF_GetError() << '\n';
		std::cin.get();
		exit(-1);
	}
	//*/
	/*
	int flags = MIX_INIT_MP3;
	int initted = Mix_Init(flags);
	if ((initted & flags) != flags) {
		std::cout << "Mix_Init: Failed to init!\n";
		std::cout << "Mix_Init: " << Mix_GetError() << '\n';
		std::cin.get();
		exit(-1);
	}
	*/

	using AcsGameEngine::Util::ColorList;

	AcsGameEngine::Window window{ "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280 , 640 };
	AcsGameEngine::Renderer renderer(window);
	AcsGameEngine::EventManager eventManager;
	AcsGameEngine::ECS::EntityManager entityManager;
	bool running{ true };
	constexpr uint8_t framesPerSecond = 60;
	constexpr std::chrono::milliseconds frameDelay{ 1000 / framesPerSecond };
	std::chrono::system_clock::time_point frameStart;
	std::chrono::system_clock::duration frameTime{};
	Game game{renderer, entityManager};
	MapSystem msystem{ renderer, entityManager };

	msystem.init();

	eventManager.onQuit([&running](SDL_Event & e) {
		running = false;
	});

	while (running) {
		try {
			frameStart = std::chrono::system_clock::now();
			eventManager.processEvents();

			renderer.Clear(ColorList::white);

			msystem.render();

			renderer.Present();

			frameTime = std::chrono::system_clock::now() - frameStart;

			if (frameDelay > frameTime) {
				std::this_thread::sleep_for(frameDelay - frameTime);
			}
		}
		catch (const std::exception &e) {
			std::cout << "Exception: " << e.what();
		}
		catch (...) {
			std::cout << "Error - Uncaught exception\n";
			//throw; //throw again
		}
	}

	//Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	//*/
	//std::cout << "Hello";
	//std::cin.get();
	return 0;
}
