#pragma once
#include "GameState.h"
#include "Text.h"
#include "SDL_mixer.h"
class SplashScreen1 :
    public GameState
{
public:
	SplashScreen1();

	virtual void Update(float DeltaTime) override { GameState::Update(DeltaTime); }
	virtual void Draw(SDL_Renderer* Renderer) override;
	virtual void ProcessInput(Input* UserInput) override { GameState::ProcessInput(UserInput); }

	virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window) override;
	virtual bool OnExit() override;

protected:
	Text* Splash1Title;
	Mix_Chunk* SFX_Enter;
};

