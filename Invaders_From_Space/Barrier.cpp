#include "Barrier.h"

Barrier::Barrier(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	Tag = "Barrier";
}

Barrier::~Barrier()
{
}

void Barrier::Update(float DeltaTime)
{
	// this will make sure the gameobject Update code runs first
	Character::Update(DeltaTime);
}
