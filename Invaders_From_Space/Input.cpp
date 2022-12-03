#include "Input.h"
#include "SDL_syswm.h"
#include "resource.h"
#include "Game.h"

Input::Input(Game* MyGame)
{
	KeyboardState = nullptr;
	this->MyGame = MyGame;
	// all SDL to detect menu input events
	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
}

Input::~Input()
{
}

void Input::UpdateInput(bool& bIsGameOver, vector<SDL_Window*> SdlWindows)
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event)) {
		// detect the type of input that was input
		switch (Event.type) {
		case SDL_KEYDOWN:
			KeyboardState = SDL_GetKeyboardState(NULL);
			break;
		case SDL_KEYUP:
			KeyboardState = SDL_GetKeyboardState(NULL);
			break;
		case SDL_SYSWMEVENT:
			HandleMenuEvents(&Event, SdlWindows, bIsGameOver);
			break;
		default:
			break;
		}

		// when you hit the cross button on the app, close the game
		if (Event.window.event == SDL_WINDOWEVENT_CLOSE) {
			// if the main window close is pressed - end the game
			if (Event.window.windowID == SDL_GetWindowID(SdlWindows[0])) {
				bIsGameOver = true;
			}
			else {
				// if the secondary window close was pressed then hide the secondary window
				SDL_HideWindow(SdlWindows[1]);
			}
		}
	}
}

bool Input::IsKeyDown(SDL_Scancode Key)
{
	if (KeyboardState != nullptr && KeyboardState[Key] == true) {
		return true;
	}

	return false;
}

bool Input::IsKeyUp(SDL_Scancode Key)
{
	if (KeyboardState != nullptr && KeyboardState[Key] == true) {
		return false;
	}

	return true;
}

void Input::HandleMenuEvents(SDL_Event* Event, vector<SDL_Window*> SdlWindows, bool& bIsGameOver)
{
	// Detect a menu button was pressed
	switch (Event->syswm.msg->msg.win.wParam) {
	case ID_FILE_CONTROLS: // If we push the controls button
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "CONTROLS:", "Left - 'A'/'Left Arrow' \nRight - 'D'/'Right Arrow' \nShoot - 'W'/'Space Bar'", SdlWindows[0]);
		break;
	case ID_FILE_PAUSE: // If we push the pause button
		if (!IsGamePaused) {
			system("pause"); // kills program
		}
		else {
			system("unpause"); // doesn't work
		}
		break;
	case ID_FILE_EXIT: // if we push the exit game button
		bIsGameOver = true; // end the game/program
		break;
	case ID_ABOUT_GAMEINFO: // if we push the Game Info button
		// create a simple dialoge box that will display information then close when we push a button
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "About Invaders From Space", "This game is basically a rip of Space Invaders, with a little bit of Breakout thrown in the mix to make it unique. \n \nIt was made in full the morning of the presentation submittion cutoff day because I got too distracted with \nmoving houses and work, and everytime I had a break to start working I gor stuck in Executive Dysfunction", SdlWindows[0]);
		break;
	default:
		break;
	}
}
