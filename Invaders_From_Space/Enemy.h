#pragma once
#include "Character.h"
#include "Vector2.h"

class Enemy :
    public Character
{
public:
    Enemy(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
    ~Enemy();

    void Update(float DeltaTime) override;

    int SetDirection(int Direction);

    int SetEnemyCount(int EnemyCount);

    int EnemyCount;

    float DownTime;

    int Direction;

    bool DirFlip;
};

