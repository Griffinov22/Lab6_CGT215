// Lab6_CGT215.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;

	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();
	
	//foreground will be the manipulated image
	Color greenScreen;
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			//if pixel is not totally green use background pixel
			if (y == 0 && x == 0) {
				greenScreen = foregroundImage.getPixel(x, y);
			}
			Color currPixelBackground = backgroundImage.getPixel(x,y);
			Color currPixelForeground = foregroundImage.getPixel(x, y);

			if (currPixelForeground == greenScreen) {
				//use background pixel
				foregroundImage.setPixel(x, y, currPixelBackground);
			}
			//else keep foreground pixels that show yoda

		}
	}
	
	// By default, just show the foreground image
	
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}