#pragma once
#include "Character.h"
class Collectable :
	public Character
{
public:
	Collectable(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
	~Collectable();

	void Update(float DeltaTime) override;
	
	static int CollType;

private:

	float PowTimer;

};

