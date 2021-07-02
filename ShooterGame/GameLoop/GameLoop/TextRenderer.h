// Some code and ideas collected from - https://www.youtube.com/watch?v=FIjj6UVXtXk
#pragma once
#include <string>
#include <SDL_ttf.h>
#include <SDL.h>


using namespace std;


// Defines the text class
class Text {
public:
	// Creates the parameters that contains the renderers location, file path to the fonts, the size, the text thats gonna be printed and the colour
	Text(SDL_Renderer * renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

	// Displays the text as a constant
	void display(int x, int y, SDL_Renderer *renderer) const;

	// loads the font with parameters (the same as above)
	static SDL_Texture *loadFont(SDL_Renderer * renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

private:
	// Creates a SDL Texture that has a NULL pointer
	SDL_Texture *_text_texture = nullptr;

	// Displays the text
	mutable SDL_Rect _text_rect;
};