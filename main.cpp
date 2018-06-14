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
#include "src/Game/EntitySprite.h"
#include "src/AcsGE/ECS/Entity.h"
#include "src/AcsGE/ECS/Components/SpriteComponent.h"

constexpr int mapLength = 20;
constexpr int mapHeight = 10;
using EntityMap = std::array<std::array<std::unique_ptr<Entity>, mapLength>, mapHeight>;

void readMap(std::string mapFilePath) {
	//0 = nothing
	//1 = block_grass
	//2 = block

	std::ifstream mapFile{ mapFilePath };

	if (mapFile.is_open()) {
		std::string line;
		int moveBy = 64;
		int height = 0;
		int currentMoveByY = 0;

		while (std::getline(mapFile, line))
		{
			int currentMoveByX = 0;
			int width = 0;
			int i;

			std::istringstream iss(line);

			while (iss >> i) {
				std::cout << i << " - X:" << currentMoveByX << " - Y:" << currentMoveByY << '\n';
				currentMoveByX += moveBy;
			}

			currentMoveByY += moveBy;
		}

	}
	else {
		throw std::runtime_error(std::string{ "Unable to open map file: " + mapFilePath });
	}
}


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
	using AcsGameEngine::ECS::SpriteComponent;

	AcsGameEngine::Window window{ "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280 , 640 };
	AcsGameEngine::Renderer renderer(window);
	AcsGameEngine::EventManager em;


	//using AcsGameEngine::ECS::Entity;
	std::array<std::array<std::unique_ptr<EntitySprite>, mapLength>, mapHeight> mapEntities;
	std::unordered_map<int, std::string> mapMappings{
		{1, "block_grass"},
		{2, "block"},
		{4, "gold"},
		{3, "green_ladder"},
		{9, "enemy_snake"},
		{5, "portal_blue"}
	};
	std::unordered_map<std::string, SDL_Rect> spriteMappings{
		{"block_grass",{ 0, 383, 64, 64}},
		{"block", {64, 384, 64, 64}},
		{"block_snow", { 128, 383, 64, 64}},
		{"gold", {192,383,64,64}},
		{"green_ladder", {256, 384, 64, 64 }},
		{"spikes", {320, 383, 64, 64 }},
		{"ladder", {384, 383, 64, 64 }},
		{"player", {0, 0, 45, 64}},
		{"enemy_snake", {0, 455, 55, 56}},
		{"porta_blue", {0, 710, 59, 120 }}
		//{"background_cave",{ 0, 0, 2000, 741 } }
	};
	/*
	std::unordered_map<std::string, AcsGameEngine::Texture> backgrounds{
		{"cave", renderer.make_texture("assets/images/cave-background.jpg")},
		{"cave2", renderer.make_texture("assets/images/cave-background2.jpg")},
		{"snowy", renderer.make_texture("assets/images/snowy-background.jpg")},
	};*/

	auto spritesTexture = renderer.make_texture("assets/images/Sprites.png");
	auto backgroundTexture = renderer.make_texture("assets/images/cave-background.jpg");
	//EntitySprite backgroundSprite(backgroundTexture, { 0, 0, 2000, 741 });
	//backgroundSprite.getSprite().setDestinationXYWH(0, 0, 1280, 640);

	/*
	//readMap("assets/levels/level1");
	std::string mapFilePath{ "assets/levels/level1" };
	std::ifstream mapFile{ mapFilePath };

	if (mapFile.is_open()) {
		std::string line;
		int moveBy = 64;
		int height = 0;
		int currentMoveByY = 0;

		while (std::getline(mapFile, line))
		{
			int currentMoveByX = 0;
			int width = 0;
			int mapValue;

			std::istringstream mapLineStream(line);

			while (mapLineStream >> mapValue) {
				//std::cout << mapValue << " - X:" << currentMoveByX << " - Y:" << currentMoveByY << " - [" << height << "," << width << "]" <<" | ";
				//mapEntities[]
				if (mapValue != 0) {
					//if (mapValue == 1 || mapValue == 2) {
					mapEntities[height][width] = std::make_unique<EntitySprite>(&spritesTexture, spriteMappings[mapMappings[mapValue]]);
					mapEntities[height][width].get()->getSprite().setDestinationXY(currentMoveByX, currentMoveByY);
					//}
				}
				width++;
				currentMoveByX += moveBy;
			}
			std::cout << '\n';

			currentMoveByX = 0;
			currentMoveByY += moveBy;
			height++;
		}

	}*/
	//else {
		//throw std::runtime_error(std::string{ "Unable to open map file: " + mapFilePath });
	//}


	//EntitySprite es{ &spritesTexture, spriteMappings["block_grass"] };
	//es.getSprite().setDestinationXY(20, 20);
	AcsGameEngine::ECS::Entity e;
	auto &sprite = e.addComponent<SpriteComponent>(spritesTexture, spriteMappings["block_grass"]);
	sprite.getSprite().setDestinationXY(20, 20);

	//entities.push_back(e);


	bool running{ true };

	em.onQuit([&running](SDL_Event & e) {
		running = false;
	});

	constexpr uint8_t framesPerSecond = 60;
	constexpr std::chrono::milliseconds frameDelay{ 1000 / framesPerSecond };

	std::chrono::system_clock::time_point frameStart;
	std::chrono::system_clock::duration frameTime{};

	while (running) {
		try {
			frameStart = std::chrono::system_clock::now();
			em.processEvents();

			renderer.Clear(ColorList::white);

			//renderer.DrawSprite(backgroundSprite.getSprite());
			auto &x = e.getComponent<AcsGameEngine::ECS::SpriteComponent>().getSprite();
			renderer.DrawSprite(e.getComponent<AcsGameEngine::ECS::SpriteComponent>().getSprite());
			//renderer.DrawSprite(sprite.getSprite());
			//renderer.DrawSprite(es.getSprite());

			//mapEntities[1][0].get()->getSprite();


			//Entity *entityPtr = mapEntities[1][0].get();
			//auto &spr = mapEntities[1][0].get()->getSprite();			
			//renderer.DrawSprite(spr);

			
			/*
			for (int mHeight = 0; mHeight < mapHeight; mHeight++) {
				for (int mLength = 0; mLength < mapLength; mLength++) {
					if (mapEntities[mHeight][mLength]) {
						auto &spr = mapEntities[mHeight][mLength].get()->getSprite();
						//auto s = spr.getDestination();
						//std::cout << " - X:" << s.x  << " - Y:" << s.y << " - [" << mHeight << "," << mLength << "]" << " | ";
						renderer.DrawSprite(spr);
					}
				}
			}
			//*/
			//mapLength = 20;
			//mapHeight


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
