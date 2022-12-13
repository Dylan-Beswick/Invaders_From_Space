#pragma once
#include "Character.h"
#include "Vector2.h"
#include "SDL_mixer.h"

class Player :
    public Character
{
public:
    Player(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
    ~Player();

    void Update(float DeltaTime) override;
    void ProcessInput(Input* UserInput) override;
    static void SetSpeed(float NewSpeed);
    static bool bPlayerFire;
    static float Speed;

private:

    // cooldown for when the player can fire
    float ShootTime;

protected:
    // shoot sound
    Mix_Chunk* SFX_Enter;
};

