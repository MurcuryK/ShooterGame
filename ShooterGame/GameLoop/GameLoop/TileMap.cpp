#include "pch.h"
#include "TileMap.h"


extern GameLoop * gameLoop;


// Initialisation that loads the image
void TileMap::init()
{
	// Calls the Tile Maps image
	SDL_Surface * surface = IMG_Load("Art/TileMap.png");

	// Points to the texture and renderer so the TileMap can be rendered to the surface
	this->mapTileset = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}

void TileMap::processInput(SDL_Event e)
{

}

void TileMap::update()
{

}


// Matchs the array of map data with the tiled image
void TileMap::draw()
{
	for (int i = 0; i < MAP_SIZE_Y; i++) {
		for (int j = 0; j < MAP_SIZE_X; j++) {
			// Calculate the area of the texture which needs to be drawn in the image file the tiles are 64x64px
			SDL_Rect srcRect = { (MAP_DATA[i][j] % 12)* 64, ((MAP_DATA[i][j] / 12)* 64)*64, 64, 64};

			// Calculate location it needs to be drawn to the screen
			SDL_Rect destRect = { (j*MAP_TILE_SIZE_PX)-camX, i*MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX };
			SDL_RenderCopy(renderer, mapTileset, &srcRect, &destRect);
		}
	}


}

void TileMap::clean()
{
	// Destorys the Tile Map texture
	SDL_DestroyTexture(this->mapTileset);

}
