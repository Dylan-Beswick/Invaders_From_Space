#include "EnemyBullet.h"
#include "GSLoss.h"
#include "Game.h"

EnemyBullet::EnemyBullet(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	MaxSpeed = 12.5;
	Tag = "EBullet";
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	SetMovementAxis(Vector2(0.0f, 1.0f));

	// store the colliders overlapping out collider
	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	// this will run through all the colliders overlapping each frame
	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "Player") {
			// remove the player object from the screen
			(*it)->GetOwner()->DestroyGameObject();

			// move to the Loss screen (don't have lives implemented yet)
			GSLoss* NewState = new GSLoss;
			Game::GetGameInstance()->ChangeGameState(NewState, 9);
		}
		else if ((*it)->GetOwner()->Tag == "PBullet") {
			// remove the player bullet object from the screen
			(*it)->GetOwner()->DestroyGameObject();
		}
		else if ((*it)->GetOwner()->Tag == "Barrier") {
			// remove the barrier object from the screen (don't have Texture shifting yet)
			(*it)->GetOwner()->DestroyGameObject();
		}
	}
}
