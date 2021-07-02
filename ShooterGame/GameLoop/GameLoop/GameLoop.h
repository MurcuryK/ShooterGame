#pragma once

#include <SDL.h>
#include <iostream>
#include "Player.h"
#include "TileMap.h"
#include "BulletManager.h"
#include "TextRenderer.h"


using namespace std;

class Player;
class BulletManager;
class TileMap;
class GameLoop {

public:
	GameLoop();
	
	bool init();

	bool processInput();

	void update();	// Returns true only if application is closed

	void draw();

	void clean();
	
	// Sets up the keyboard input system
	bool getKeyDown(int keyCode) {
		if (keyCode > 0 && keyCode < 512) {
			return this->keyDown[keyCode];
		}
		return false;
	}

private:
	// Creates variables for GameLoop
	SDL_Window* window;
	SDL_Renderer* renderer;

	Player* player;
	TileMap* tileMap;

	BulletManager* bulletmanager;

	bool keyDown[256];


};