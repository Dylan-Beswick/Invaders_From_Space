#include "BufferState.h"

BufferState::BufferState()
{
	DBColour = { 5, 5, 5, 255 };
}

bool BufferState::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	SDL_Log("BufferState Entered...");

	return true;
}

bool BufferState::OnExit()
{
	SDL_Log("Exited BufferState...");

	return true;
}
