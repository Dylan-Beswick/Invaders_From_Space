#pragma once
#include "Character.h"
class PlayerBullet :
    public Character
{
public:
    PlayerBullet(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
    ~PlayerBullet();

    void Update(float DeltaTime) override;
};

