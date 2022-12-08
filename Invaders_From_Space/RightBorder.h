#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Player.h"
#include "Enemy.h"

class RightBorder :
    public GameObject
{
public:
    RightBorder(Vector2 Position, Vector2 Dimensions);

    virtual void Update(float DeltaTime) override;
private:
    float Speed;

    Player* PChara;

    Enemy* EChara;

    float DownTime;
}