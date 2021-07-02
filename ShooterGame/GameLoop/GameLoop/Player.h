#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "GameLoop.h"
#include "TileMap.h"

class TileMap;

class Player {
public:

	// Called when new player object is constructed
	Player(SDL_Renderer*, TileMap*);
	// Called at the start of the program
	void init();
	// Called for each input event which event which occurs in a frame
	void processInput(SDL_Event e);
	// Called every frame
	void update(bool * keys);
	// Called every frame
	void draw();
	// Called once on program shutdown
	void clean();

	SDL_Rect getAngle() const{
		return position;
	}


private:
	SDL_Texture * texture; // This is the players sprite
	SDL_Renderer * renderer; // Allows rendering from class

	TileMap * m;	// The tile map

	float rotationAngle;

	SDL_Rect position;	// Defines the Players position


	// Animation
	const int FRAME_COUNT = 8;
	const int TILESHEET_WIDTH = 8;
	int animFrame = 0;
	int ANIMATION_SPEED = 1000;	//  1S between frames
	long int lastAnimChange = 0;

};