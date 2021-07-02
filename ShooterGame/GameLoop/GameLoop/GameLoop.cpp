#include "pch.h"
#include "GameLoop.h"


// Defines Player as a class
class Player;

TileMap* tileMap;

Text* text;


GameLoop::GameLoop()
{

}


// Called at the start of the program
bool GameLoop::init()
{
	// Sets up the input system
	for (int i = 0; i < 256; i++) {
		keyDown[i] = false;
	}

	//Try and initialise the video system.
	//If we can't, quit the program.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not initialise SDL: " << SDL_GetError();
		return false;
	}

	//Create a window in which to render our program.
	window = SDL_CreateWindow(
		"SDL Bouncing Ball Sandbox",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1280, 768,
		SDL_WINDOW_SHOWN
	);

	//If we can't, quit the program.
	if (!window) {
		std::cerr << "Could not create SDL window: " << SDL_GetError();
		return false;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		return false;
	}


	// Loads the text font, sets size, what it says and colour
	text = new Text(renderer, "Art/comic.ttf", 40, "HIT AS MAY BUTTONS AS YOU CAN", { 0,0,0,0 });

	// Creates a new instance of the tilemap
	tileMap = new TileMap(this->renderer);
	// Runs the TileMap.h init class
	tileMap->init();


	// Creates a new instance of the player
	player = new Player(this->renderer, this->tileMap);
	// Runs the Player.h init class
	player->init();



	// Creates a new instance of the bullet
	bulletmanager = new BulletManager(this->renderer, this->player, this->tileMap);
	bulletmanager->init();
}


bool GameLoop::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}

		if (e.type == SDL_KEYDOWN) {
			// check against array size to prevent writing outside the bounds
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = true;
			}
		}
		else if (e.type == SDL_KEYUP) {
			// check against array size to prevent writing outside the bounds
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = false;
			}
		}

		//process any input for game classes here
		player->processInput(e);
		bulletmanager->processInput(keyDown);
		tileMap->processInput(e);
	}

	return true;
}

void GameLoop::update()
{
	// If camX is less than ? then it will increase by one
	if (tileMap->camX < 5120) {
		tileMap->camX += 1;
	}


	//process updating for game classes here
	player->update(keyDown);

	bulletmanager->update();

	tileMap->update();

}

void GameLoop::draw()
{
	
	//process drawing for game classes here
	SDL_RenderClear(renderer);
	tileMap->draw();
	bulletmanager->draw();
	player->draw();

	// Load text stuff location x, y
	text->display(300, 0, renderer);

	SDL_RenderPresent(renderer);

	
	//SDL_RenderPresent(renderer);
	SDL_Delay(16);


	

}

void GameLoop::clean()
{
	//process clean up for game classes here
	player->clean();
	if (player) {
		delete player;
		player = nullptr;
	}

	bulletmanager->clean();


	tileMap->clean();
	if (tileMap) {
		delete tileMap;
		tileMap = nullptr;
	}

}