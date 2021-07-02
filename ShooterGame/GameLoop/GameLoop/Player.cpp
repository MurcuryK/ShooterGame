#include "pch.h"
#include "Player.h"


extern GameLoop * gameLoop;

bool arrowKeysState[4] = { false,false,false,false };


Player::Player(SDL_Renderer * renderer, TileMap*m)
{
	this->renderer = renderer;

	this->m = m;
}

void Player::init()
{
	// Calls the player image
	SDL_Surface * surface = IMG_Load("Art/Eye Animation.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	lastAnimChange = SDL_GetTicks();



	// Points to the texture and renderer so the Player can be rendered to the surface
	//this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	//SDL_FreeSurface(surface);


	// defines the Players position and size 
	position.x = 0;
	position.y = 320;
	position.w = 64;
	position.h = 64;

}

void Player::processInput(SDL_Event e)
{

}

void Player::update(bool * keys)
{
	// Player animated for every second
	if (SDL_GetTicks() - lastAnimChange > ANIMATION_SPEED) {
		lastAnimChange = SDL_GetTicks();
		animFrame++;
		if (animFrame >= 8) {
			animFrame = 0;
		}

	}

		int oldX = position.x;
		int oldY = position.y;

		// changes player position to move up
		if (keys[SDL_SCANCODE_W])
			position.y -= 3;

		// changes player position to move down
		if (keys[SDL_SCANCODE_S])
			position.y += 3;


		// Sets player position and size
		SDL_Rect playerPos = { position.x,position.y,64,64 };

		// Go through all the tiles on the tile map

		// Check Y axis
		for (int i = 0; i < 12; i++) {
			// Check X axis
			for (int j = 0; j < 100; j++) {


				// For tile 0 (the ground)
				if (m->MAP_DATA[i][j] == 0) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64)- m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 1 (the up)
				if (m->MAP_DATA[i][j] == 1) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 4 (Ramp thing)
				if (m->MAP_DATA[i][j] == 4) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 5 (Ramp thing)
				if (m->MAP_DATA[i][j] == 5) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 6 (Ramp thing)
				if (m->MAP_DATA[i][j] == 6) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 7 (Ramp thing)
				if (m->MAP_DATA[i][j] == 7) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 8 (Button up)
				if (m->MAP_DATA[i][j] == 8) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 9 (Button left)
				if (m->MAP_DATA[i][j] == 9) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 10 (Button down)
				if (m->MAP_DATA[i][j] == 10) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}


				// For tile 11 (Button Right)
				if (m->MAP_DATA[i][j] == 4) {
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { (j * 64) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&playerPos, &mapTile)) {
						// Sets the player position as what it was before collision
						position.x = oldX;
						position.y = oldY;
					}
				}

			}
		}
}

void Player::draw()
{
	// Renders the Player in the position stated by the position variable
	//SDL_RenderCopy(this->renderer, this->texture, 0, &this->position);
	SDL_Rect dest = { position.x, position.y, position.w, position.h };
	int animX = 128 * (animFrame % TILESHEET_WIDTH);
	SDL_Rect src = { animX, 0,128, 128 };
	SDL_RenderCopy(renderer, texture, &src, &dest);
}

void Player::clean()
{
	// Destorys the Player texture
	SDL_DestroyTexture(this->texture);

}
