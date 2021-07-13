#include "Game.h"
#include "Utility.h"
#include"Constants.h"

Game::Game()
{
	//constructor
}

void Game::Initialise()
{
	// set the title
	SetConsoleTitle(L"Title of my console");

	// set the screens buffer size
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	//set the window size
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
}

void Game::Update(float deltaTime)
{
	static bool exitGame = false;

	switch (currentGameState)
	{
		case SPLASH:
		{
			//create new splash screen
			static Splash splash;

			// calculate current splash duration
			splash.duration += deltaTime;

			if (splash.duration < 3.0f)
			{
				// draw splash image
				WriteImagetoBuffer(consoleBuffer, splash.CHARACTERS, splash.COLORS, splash.HEIGHT, splash.WIDTH,
					(SCREEN_WIDTH / 2) - (splash.WIDTH / 2), (SCREEN_HEIGHT / 2) - (splash.HEIGHT / 2));
			}
			else
			{
				// move to menu state
				splash.duration = 0.0f;
				currentGameState = MENU;
			}

			break;
		}
		case MENU:
		{
			//clear any previous images
			ClearScreen(consoleBuffer);

			//print out our text options
			WriteTextToBuffer(consoleBuffer, "1. PLAY", (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
			WriteTextToBuffer(consoleBuffer, "2. OPTIONS", (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) + 1);
			WriteTextToBuffer(consoleBuffer, "3. SCOREBOARD", (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) + 2);
			WriteTextToBuffer(consoleBuffer, "4. QUIT", (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) + 3);

			if (GetAsyncKeyState(KEY_1))
			{
				currentGameState = PLAY;
			}
			else if (GetAsyncKeyState(KEY_2))
			{
				// TODO: Options Menu

			}
			else if (GetAsyncKeyState(KEY_2))
			{
				//TODO: Scoreboard Menu
			}
			else if (GetAsyncKeyState(KEY_3))
			{
				exitGame = true;
			}
			break;
		}
		case PLAY:
		{
			if (GetAsyncKeyState(KEY_ESC))
			{
				exitGame = true;
			}
			if (GetAsyncKeyState(KEY_ENTER))
			{
				player.Reset();
				currentGameState = MENU;
			}
			if (!player.hasLanded && !player.hasCrashed)
			{
				if (GetAsyncKeyState(KEY_ESC))
				{
					exitGame = true;
				}
				if (GetAsyncKeyState(KEY_W) && player.fuel > 0.0f)
				{
					player.isAccelerating = true;
					//expend fuel
					player.fuel -= FUEL_CONSUMPTION_RATE;
				}
				if (GetAsyncKeyState(KEY_A))
				{
					--player.xPos;
				}
				if (GetAsyncKeyState(KEY_D))
				{
					++player.xPos;
				}

				// should we accelerate?
				if (player.isAccelerating)
				{
					player.Acceleration += (ACCELERATION_RATE * deltaTime);
				}
				else
				{
					player.Acceleration -= (DECELERATION_RATE * deltaTime);
				}

				//reset acceleration flag
				player.isAccelerating = false;

				//clamp our acceleration
				player.Acceleration = ClampFLoat(player.Acceleration, 0.0f, 1.5f);

				if (player.Acceleration >= 1.0f)
				{
					player.yPos--;
				}
				else if (player.Acceleration < 0.5f)
				{
					player.yPos++;
				}

				//clamp the input
				player.xPos = ClampInt(player.xPos, 0, (SCREEN_WIDTH - player.WIDTH));
				player.yPos = ClampInt(player.yPos, 0, (SCREEN_HEIGHT - player.HEIGHT));

				// get two characters under our landing gear
				char bottomLeftChar = background.CHARACTERS[player.xPos + SCREEN_WIDTH * (player.yPos + (player.HEIGHT - 1))];
				char bottomRightChar = background.CHARACTERS[(player.xPos + (player.WIDTH - 1)) + SCREEN_WIDTH * (player.yPos + (player.HEIGHT - 1))];



				//landed?
				if (bottomLeftChar == '_' && bottomRightChar == '_')
				{
					player.hasLanded = true;
				
				}
				else if (bottomLeftChar != ' ' || bottomRightChar != ' ')
				{
					player.hasCrashed = true;
				
				}
			}




			//clear the previous frame before we start the build for the next frame
			ClearScreen(consoleBuffer);

			// Draw Background image
			WriteImagetoBuffer(consoleBuffer, background.CHARACTERS, nullptr, SCREEN_HEIGHT, SCREEN_WIDTH, 0, 0);

			if (player.hasCrashed)
			{
				static float explosionFlashTimer = 0.0f;

				explosionFlashTimer += deltaTime;

				if (explosionFlashTimer >= 0.5f)
				{
					//draw image to buffer
					WriteImagetoBuffer(consoleBuffer, explosion.CHARACTERS, explosion.COLORS, explosion.HEIGHT, explosion.WIDTH, player.xPos, player.yPos);
					explosionFlashTimer = 0.0f;
				}
				else
				{
					//draw our empty characters
					WriteImagetoBuffer(consoleBuffer, explosion.EMPTY_CHARACTERS, explosion.COLORS, explosion.HEIGHT, explosion.WIDTH, player.xPos, player.yPos);
				}

				WriteTextToBuffer(consoleBuffer, " Houston, We have a problem!!!", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
				WriteTextToBuffer(consoleBuffer, "Press Enter to Return to the Menu!", SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 1);

			}
			else if (player.hasLanded)
			{
				WriteTextToBuffer(consoleBuffer, "The Eagle Has Landed!", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
				WriteTextToBuffer(consoleBuffer, "Press Enter to Return to the Menu!", SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 1);
			}
			else
			{
				// Draw Player Image
				WriteImagetoBuffer(consoleBuffer, player.Characters, player.Colors, player.HEIGHT, player.WIDTH, player.xPos, player.yPos);

			}

			// Draw UI Text
			WriteTextToBuffer(consoleBuffer, "SCORE: ", 1, 0);
			WriteTextToBuffer(consoleBuffer, "TIME: ", 1, 1);
			WriteTextToBuffer(consoleBuffer, "FUEL: " + std::to_string(player.fuel), 1, 2);

			break;
		}
		case OPTIONS:
		{
			//TODO: Options Menu

			break;
		}
		case SCOREBOARD:
		{
			//TODO: Scoreboard
			break;
		}
	
	}

}

void Game::Draw()
{
	// kick the draw
	WriteConsoleOutputA(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
}
