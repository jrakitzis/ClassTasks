// Includes
#include <Windows.h>

//Defines
#define WIDTH 150
#define HEIGHT 40

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

//Game Parameters
/////////////////////
const unsigned char characterToPrint = 176;

// Game Constants
const int playerCharacter = '@';
const int playerColor = 7;

const int KeyEsc = VK_ESCAPE;
const int KeyW = 'W';
const int KeyA = 'A';
const int KeyS = 'S';
const int KeyD = 'D';

//Game Variables
int playerXPos = 0;
int PlayerYPos = 0;

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
	//////////////////////////////////////////////

	// Exit game flag
	bool exitGame = false;

	//Game Loop
	while (!exitGame)
	{
		//Checking for input 
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			//set our exit game flag
			exitGame = true;
		}

		//Nested loop to set each character to a random color 
		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				consoleBuffer[x + WIDTH * y].Char.AsciiChar = characterToPrint;
				consoleBuffer[x + WIDTH * y].Attributes = rand() % 128;
			}
		}

		WriteConsoleOutputA(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);

	}

}