#pragma once
// SDL header files
#include <SDL.h>
#include <SDL_image.h>
// Vector for managing array
#include <vector>
#include <math.h>
#include <algorithm>

#include "Player.h"
#include "GameLoop.h"
#include "TileMap.h"

#define PI 3.14159265

using namespace std;

class Player;

struct Bullet {
	float x, y, distance, rotation;
};

// Creates instances of the bullet structure
class BulletManager {
public:
	BulletManager(SDL_Renderer * renderer, Player*player, TileMap*m) : renderer(renderer), player(player), m(m){}

	void init();
	
	void processInput(bool * keyDown);

	void update();

	void draw();

	void clean();


private:
	SDL_Renderer*renderer;
	SDL_Texture * bulletTexture;
	vector<Bullet> bullets;
	// Need a reference to the player
	Player * player;

	TileMap * m;	// The tile map

	// Time limit  between shots
	const int SHOOT_TIMER_MS = 300;
	// Number of pixels travelled per frame
	const int BULLET_VELOCITY = 15;
	unsigned int lastShot = 0;

};