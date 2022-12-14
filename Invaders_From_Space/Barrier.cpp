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

	// store the colliders overlapping out collider
	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	// this will run through all the colliders overlapping each frame
	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "EBullet") {
			// remove the enemy bullet object from the screen
			(*it)->GetOwner()->DestroyGameObject();
		}
	}
}
