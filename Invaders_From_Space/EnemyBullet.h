#pragma once
#include "Character.h"
class EnemyBullet :
    public Character
{
public:
    EnemyBullet(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
    ~EnemyBullet();

    void Update(float DeltaTime) override;
};

