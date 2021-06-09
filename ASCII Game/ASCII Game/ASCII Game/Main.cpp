// Includes
#include <Windows.h>
#include<chrono>

//Defines
#define WIDTH 150
#define HEIGHT 40
#define FRAME_RATE 30

// console parameters
/////////////////////


#pragma region Buffers Parameters
// Window size coordinates 
SMALL_RECT windowSize = {0, 0, WIDTH - 1, HEIGHT - 1};

// A Coor Struct for specifying the consoles screen buffer dimensions 
COORD bufferSize = {WIDTH, HEIGHT};

COORD characterBufferSize = {WIDTH, HEIGHT};
COORD characterPosition{ 0,0 };
SMALL_RECT consoleWriteArea = {0, 0, WIDTH - 1, HEIGHT - 1};

//A Char_INFO array containing data about each character
CHAR_INFO consoleBuffer[WIDTH * HEIGHT];

//Initialize my handles
HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
#pragma endregion

//TypeDefs
typedef std::chrono::steady_clock::time_point Time;
typedef std::chrono::high_resolution_clock HiResClock;
typedef std::chrono::duration<float> TimeDiff;



// Game Constants

const int PlayerWidth = 2;
const int PlayerHeight = 3;
const int PlayerCharacters[PlayerWidth * PlayerHeight] =
{
	'_','_',
	'|','|',
	'/','\\'
};
const int PlayerColors[PlayerWidth * PlayerHeight] =
{
	0xF,0xF,
	0xF,0xF,
	0xE,0xE,
};

const int KeyEsc = VK_ESCAPE;
const int KeyW = 'W';
const int KeyA = 'A';
const int KeyS = 'S';
const int KeyD = 'D';

//Game Variables
int playerXPos = 0;
int playerYPos = 0;
bool exitGame = false;
float deltaTime = 0.0f;
int frameCounter = 0;
Time previousFrameTime = HiResClock::now();

//functions 
int ClampInt(int intToClamp, int lowerLimit, int upperLimit);

int main()
{
	//Boiler player console window
	//////////////////////////////
	// set the title
	SetConsoleTitle(L"Title of my console");

	// set the screens buffer size
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	//set the window size
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);





	//Game Loop
	while (!exitGame)
	{
		//calculate our delta time (time since last frame)
		Time currentFrameTime = HiResClock::now();
		TimeDiff diff = currentFrameTime - previousFrameTime;
		deltaTime = diff.count();
		frameCounter++;

		if (deltaTime >= (1.0f / FRAME_RATE))
		{
			// cashe the timestamp of this frame
			previousFrameTime = currentFrameTime;

			//Checking for input 
			if (GetAsyncKeyState(KeyEsc))
			{
				//set our exit game flag
				exitGame = true;
			}
			if (GetAsyncKeyState(KeyW))
			{
				--playerYPos;
			}
			if (GetAsyncKeyState(KeyA))
			{
				--playerXPos;
			}
			if (GetAsyncKeyState(KeyS))
			{
				++playerYPos;
			}
			if (GetAsyncKeyState(KeyD))
			{
				++playerXPos;
			}
			//clamp the input
			playerXPos = ClampInt(playerXPos, 0, (WIDTH - 1));
			playerYPos = ClampInt(playerYPos, 0, (HEIGHT - 1));


			//clear the previous frame before we start the build for the next frame
			for (int i = 0; i < (WIDTH * HEIGHT); ++i)
			{
				consoleBuffer[i].Char.AsciiChar = 0;
				consoleBuffer[i].Attributes = 0;
			}




			// Draw Player Image
			for (int y = 0; y < PlayerHeight; ++y)
			{
				for (int x = 0; x < PlayerWidth; ++x)
				{
					consoleBuffer[(playerXPos + x) + WIDTH * (playerYPos + y)].Char.AsciiChar = PlayerCharacters[x + PlayerWidth * y];
					consoleBuffer[(playerXPos + x) + WIDTH * (playerYPos + y)].Attributes = PlayerColors[x + PlayerWidth * y];
				}

			}
			// kick the draw
			WriteConsoleOutputA(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);



		}
		return 0;
	}
}
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