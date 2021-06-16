// Includes
#include <Windows.h>
#include<chrono>
#include "GameObjects.h"
#include"Game.h"

//TypeDefs
typedef std::chrono::steady_clock::time_point Time;
typedef std::chrono::high_resolution_clock HiResClock;
typedef std::chrono::duration<float> TimeDiff;








int main()
{

	Game gameInstance;
	// initialise our console window
	gameInstance.Initialise();
	
	// initialise variables
	float deltaTime = 0.0f;
	Time currentFrameTime = HiResClock::now();
	Time previousFrameTime = HiResClock::now();





	//Game Loop
	bool exitGame = false;
	while (!exitGame)
	{
		//calculate our delta time (time since last frame)
		Time currentFrameTime = HiResClock::now();
		TimeDiff diff = currentFrameTime - previousFrameTime;
		deltaTime = diff.count();
		

		if (deltaTime >= (1.0f / FRAME_RATE))
		{
			//update our application
			gameInstance.Update(deltaTime);


			// cashe the timestamp of this frame
			previousFrameTime = currentFrameTime;


		}	

		gameInstance.Draw();

	}

	return 0;
}




#pragma region UTILITY FUNCTIONS
int ClampInt(int intToClamp, int lowerLimit, int upperLimit)
{
	if (intToClamp <= lowerLimit)
	{
		return lowerLimit;
	}
	else if (intToClamp >= upperLimit)
	{
		return upperLimit;
	}
	else
	{
		return intToClamp;
	}
}

float ClampFLoat(float floatToCLamp, float lowerLimit, float upperLimit)
{
	return floatToCLamp <= lowerLimit ? lowerLimit : floatToCLamp >= upperLimit ? upperLimit : floatToCLamp;
}


void WriteImagetoBuffer(CHAR_INFO* consoleBuffer, const char* charsToPrint, const int colorsToPrint[], const int imageHeight, const int imageWidth, int imageXPos, int imageYPos)
{
	for (int y = 0; y < imageHeight; ++y)
	{
		for (int x = 0; x < imageWidth; ++x)
		{
			consoleBuffer[(imageXPos + x) + SCREEN_WIDTH * (imageYPos + y)].Char.AsciiChar = charsToPrint[x + imageWidth * y];
			if (colorsToPrint)
			{
				consoleBuffer[(imageXPos + x) + SCREEN_WIDTH * (imageYPos + y)].Attributes = colorsToPrint[x + imageWidth * y];
			}
			else
			{
				consoleBuffer[(imageXPos + x) + SCREEN_WIDTH * (imageYPos + y)].Attributes = 7;
			}
		}
	}
}
void ClearScreen(CHAR_INFO* consoleBuffer)
{
	for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); ++i)
	{
		consoleBuffer[i].Char.AsciiChar = 0;
		consoleBuffer[i].Attributes = 0;
	}
}

void WriteTextToBuffer(CHAR_INFO* consoleBuffer, std::string stringToPrint, int textXPos, int textYPos)
{
	for (int x = 0; x < stringToPrint.length(); ++x)
	{
		consoleBuffer[(textXPos + x) + SCREEN_WIDTH * textYPos].Char.AsciiChar = stringToPrint[x];
		consoleBuffer[(textXPos + x) + SCREEN_WIDTH * textYPos].Attributes = 0xF;
	}
}



