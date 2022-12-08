#pragma once
#include "Character.h"

class Barrier :
    public Character
{
public:
    Barrier(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
    ~Barrier();

    void Update(float DeltaTime) override;
};

