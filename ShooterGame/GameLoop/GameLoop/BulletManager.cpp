#include "pch.h"
#include "BulletManager.h"


void BulletManager::init() {
	// Load the Texture for the lazer
	SDL_Surface * surface = IMG_Load("Art/Lazer.png");
	this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);


	this->m = m;

}

void BulletManager::processInput(bool * keyDown) {
	// Checks if the Space Bar has been pressed
	if (keyDown[SDL_SCANCODE_SPACE]) {
		// Is a timer that stops the lazer from shotting constantly
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			// Contains the bullet objects and adds an element to the vector
			bullets.push_back(Bullet{(float)player->getAngle().x + 32,(float)player->getAngle().y + 32, 0, 90.0f });
			lastShot = SDL_GetTicks();
		}
	}
}


void BulletManager::update() {
	for (auto &b : bullets) {
		b.x += sin(b.rotation * PI / 180.0f)* BULLET_VELOCITY;
		b.y -= cos(b.rotation * PI / 180.0f)* BULLET_VELOCITY;
		b.distance += BULLET_VELOCITY;
	}


	// Check Y axis
	for (int i = 0; i < 12; i++) {
		// Check X axis
		for (int j = 0; j < 100; j++) {
			// for each bullet thats shot
			for (auto &b : bullets) {


				// For tile 4 (Ramp 1)
				if (m->MAP_DATA[i][j] == 4) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						b.rotation = 0;
					}
				}


				// For tile 5 (Ramp 2)
				if (m->MAP_DATA[i][j] == 5) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						b.rotation = 180;
					}
				}


				// For tile 6 (Ramp 3)
				if (m->MAP_DATA[i][j] == 6) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32)- m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						b.rotation = 180;
					}
				}


				// For tile 7 (Ramp 4)
				if (m->MAP_DATA[i][j] == 7) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						b.rotation = 90;
					}
				}


				// For tile 8 (Button up)
				if (m->MAP_DATA[i][j] == 8) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						// Remove bullet after they have travelled approx 1 pixels
						auto remove = std::remove_if(bullets.begin(), bullets.end(),
							[](const Bullet& b) {return b.distance > 1; });
						bullets.erase(remove, bullets.end());
					}
				}


				// For tile 9 (Button Left)
				if (m->MAP_DATA[i][j] == 9) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						// Remove bullet after they have travelled approx 1 pixels
						auto remove = std::remove_if(bullets.begin(), bullets.end(),
							[](const Bullet& b) {return b.distance > 1; });
						bullets.erase(remove, bullets.end());
					}
				}


				// For tile 10 (Button Down)
				if (m->MAP_DATA[i][j] == 10) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						// Remove bullet after they have travelled approx 1 pixels
						auto remove = std::remove_if(bullets.begin(), bullets.end(),
							[](const Bullet& b) {return b.distance > 1; });
						bullets.erase(remove, bullets.end());
					}
				}


				// For tile 11 (Button Right)
				if (m->MAP_DATA[i][j] == 11) {
					SDL_Rect dest = { b.x, b.y, 10, 10 };
					// Sets the tiles as 64x64
					SDL_Rect mapTile = { ((j * 64) + 32) - m->camX,i * 64,64,64 };
					// Collect the player position and tilemap
					if (SDL_HasIntersection(&dest, &mapTile)) {
						// Remove bullet after they have travelled approx 1 pixels
						auto remove = std::remove_if(bullets.begin(), bullets.end(),
							[](const Bullet& b) {return b.distance > 1; });
						bullets.erase(remove, bullets.end());
					}
				}
			}
		}
	}



	// Remove bullet after they have travelled approx 1000 pixels
	auto remove = std::remove_if(bullets.begin(), bullets.end(),
		[](const Bullet& b) {return b.distance > 10000; });
	bullets.erase(remove, bullets.end());


}

void BulletManager::draw() {
	SDL_Point center = { 5,5 };
	for (auto &b : bullets) {
		SDL_Rect dest = { b.x, b.y, 10, 10 };
		SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);
	}
}

void BulletManager::clean() {
	SDL_DestroyTexture(this->bulletTexture);
}