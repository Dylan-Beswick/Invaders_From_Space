#pragma once
#include "GameState.h"
#include "Text.h"
#include "SDL_mixer.h"


class BufferState :
    public GameState
{
public:
	BufferState();

	virtual void Update(float DeltaTime) override { GameState::Update(DeltaTime); }
	virtual void Draw(SDL_Renderer* Renderer) override { GameState::Draw(Renderer); }
	virtual void ProcessInput(Input* UserInput) override { GameState::ProcessInput(UserInput); }

	virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window) override;
	virtual bool OnExit() override;
};

