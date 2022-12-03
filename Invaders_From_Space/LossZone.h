#pragma once
#include "GameObject.h"
#include "Vector2.h"

class LossZone :
    public GameObject
{
public:
    LossZone(Vector2 Position, Vector2 Dimensions);

    virtual void Update(float DeltaTime) override;
};

