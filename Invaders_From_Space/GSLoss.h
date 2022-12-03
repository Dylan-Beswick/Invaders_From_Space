#pragma once
#include "MenuState.h"
class GSLoss :
    public MenuState
{
public:
    virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window) override;
    virtual void ProcessInput(Input* UserInput) override;
};

