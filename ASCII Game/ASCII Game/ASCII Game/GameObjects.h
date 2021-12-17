#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

//headers
#include "Constants.h"


// Structs
struct Player
{
	//functions
	void Reset()
	{
		xPos = SCREEN_WIDTH / 2;
		yPos = 5;

		xPosF = xPos;
		yPosF = yPos;

		isAccelerating = false;
		Acceleration = -1.0f;
		hasLanded = false;
		hasCrashed = false;
	}
	//constants
	static const int WIDTH = 2;
	static const int HEIGHT = 3;
	const char* Characters =
	{
		R"(__)"
		R"(||)"
		R"(/\)"
	};
	const int Colors[WIDTH * HEIGHT] =
	{
		0xF,0xF,
		0xF,0xF,
		0xE,0xE,
	};

	

	// variables
	int xPos = SCREEN_WIDTH / 2;
	int yPos = 5;

	float xPosF = xPos;
	float yPosF = yPos;

	bool isAccelerating = false;
	float Acceleration = -1.0f;
	bool hasLanded = false;
	bool hasCrashed = false;
	float fuel = 100.0f;

};

struct Explosion
{
	static const int WIDTH = 3;
	static const int HEIGHT = 3;
	const char* CHARACTERS = {
		R"('\\','|', '/',)"
		R"('-',' ', '-',)"
		R"('/','|', '//',)"
	};
	const char* EMPTY_CHARACTERS = {
		R"(' ',' ', ' ',)"
		R"(' ',' ', ' ',)"
		R"(' ',' ', ' ',)"
	};
	const int COLORS[WIDTH * HEIGHT] = {
		0xE, 0xE, 0xE,
		0xE, 0xE, 0xE,
		0xE, 0xE, 0xE,
	};
};

struct Background
{
	// constants
	const char* CHARACTERS =
	{
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                                                                      )"
		R"(                                                                                                ______             ______                             )"
		R"(                                                                                               x      x           x      x                            )"
		R"(                                                                                              x   2x   x         x   2x   x                           )"
		R"(                                                                                             x          x       x          x                          )"
		R"(                                                                                            x            x     x            x                         )"
		R"(                                                                                           x              x   x              x                        )"
		R"(                                                                                          x                x x                x                       )"
		R"(                                                                                         x                  x                  x                      )"
		R"(                                                                                        x                                       x      __             )"
		R"(                                                                                       x                                         x    x  x            )"
		R"(                                                                                      x                                           x  x 5x x           )"
		R"(                                                                                     x                                             xx      x          )"
		R"(                                                                                    x                                               x       x         )"
		R"(                                                      ____                         x                                                 x       x        )"
		R"(                                                     x    x                       x                                                   x       x       )"
		R"(                                                    x  3x  x                     x                                                     x       x      )"
		R"(                                                   x        x                   x                                                       x      x      )"
		R"(               ________                           x          x                 x                                                         x     x      )"
		R"(              x        x                         x            x               x                                                           x    x      )"
		R"(             x    1x    x                       x              x             x                                                             x   x      )"
		R"(            x            x                     x                x           x                                                               x  x      )"
		R"(           x              x                   x                  x         x                                                                 x x      )"
		R"(          x                x                 x                    x       x                                                                   xx      )"
		R"(         x                  x               x                      x     x                                                                     x      )"
		R"(        x                    x             x                        x   x                                                                       x     )"
		R"(       x                      x           x                          x x                                                                         x    )"
		R"(      x                        x         x                            x                                                                           x   )"
		R"(     x                          x       x                              x                                                                           x  )"
		R"(    x                            x     x                                x                                                                           x )"
		R"(   x                              x   x                                  x                                                                           x)"
		R"(  x                                x x                                    x                                                                           )"
		R"( x                                  x                                      x                                                                          )"
	};
};

struct Splash
{
	static const int WIDTH = 92;
	static const int HEIGHT = 9;
	const char* CHARACTERS = {
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"
		R"(-----------------------------------------------)"

	};

	const int COLORS[WIDTH * HEIGHT] = {
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	};

	//Variables
	float duration = 0.0f;
};


#endif // GAME_OBJECTS_H
