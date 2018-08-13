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
#include "src/AcsGE/ECS/Systems/RendererSystem.h"
#include "src/CustomSystems/MapSystem.h"
#include "src/GameValues.h"
#include "src/Game.h"
#include "src/CustomSystems/OverlaySystem.h"
#include "src/CustomSystems/PlayerSystem.h"


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
	constexpr int windowWidth{ 1280 };
	constexpr int windowHeight{ 640 };
	constexpr int blockSize{ 64 };

	GameValues gameValues;
	gameValues.windowWidth = 1280;
	gameValues.windowHeight = 640;
	gameValues.blockSize = 64;

	AcsGameEngine::Window window{ "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gameValues.windowWidth , gameValues.windowHeight };
	AcsGameEngine::Renderer renderer(window);
	AcsGameEngine::EventManager eventManager;
	AcsGameEngine::ECS::EntityManager entityManager;
	bool running{ true };
	
	Game game{renderer, entityManager, gameValues };
	AcsGameEngine::ECS::RendererSystem renderSystem{ entityManager, renderer };
	MapSystem msystem{ entityManager, renderer };
	OverlaySystem overlaySystem{ entityManager , eventManager};
	PlayerSystem playerSystem{ entityManager , eventManager };

	msystem.init();
	renderSystem.init();
	overlaySystem.init();
	playerSystem.init();

	eventManager.onQuit([&running](SDL_Event & e) {
		running = false;
	});

	// https://gist.github.com/mariobadr/673bbd5545242fcf9482
	using namespace std::chrono_literals;
	using clock = std::chrono::high_resolution_clock;
	
	// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
	//constexpr std::chrono::milliseconds timeStep{ 16ms };
	constexpr std::chrono::milliseconds timeStep{ 12ms };

	std::chrono::milliseconds accumulator{};
	std::chrono::milliseconds frameTime{}; //deltaTime I prefer the word frameTime
	auto timeStart = clock::now();
	// http://gameprogrammingpatterns.com/game-loop.html#play-catch-up
	while (running) {
		auto timeCurrent = clock::now();
		frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeCurrent - timeStart);
		timeStart = timeCurrent;
		accumulator += frameTime;

		try {
			eventManager.processEvents();
			

			while (accumulator >= timeStep)
			{
				//std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(timeStep).count() << '\n';
				//std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(accumulator).count() << '\n';
				//std::cin.get();

				//overlaySystem.update(timeStep);
				overlaySystem.update(0.012f);
				playerSystem.update(0.012f);
				accumulator -= timeStep;
			}

			renderer.Clear(ColorList::white);

			renderSystem.render();
			msystem.render();

			renderer.Present();
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
