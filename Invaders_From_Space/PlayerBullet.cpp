#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	MaxSpeed = 12.5;
	Tag = "PBullet";
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	SetMovementAxis(Vector2(0.0f, -1.0f));

	// store the colliders overlapping out collider
	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	// this will run through all the colliders overlapping each frame
	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "Enemy") {
			// remove the enemy object from the screen (was working, now isn't; no code was changed)
			(*it)->GetOwner()->DestroyGameObject();
		}
		else if ((*it)->GetOwner()->Tag == "EBullet") {
			// remove the enemy bullet object from the screen
			(*it)->GetOwner()->DestroyGameObject();
		}
	}
}
