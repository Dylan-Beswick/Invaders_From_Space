#include "Collectable.h"
#include "Game.h"
int Collectable::CollType = 0;

Collectable::Collectable(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	MaxSpeed = 12.5;
	Tag = "Collectable";
	PowTimer = 0.0f;
}

Collectable::~Collectable()
{
}

void Collectable::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	SetMovementAxis(Vector2(0.0f, 1.0f));

	// store the colliders overlapping out collider
	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "Player") {
			// reset the timer
			PowTimer = Game::GetGameInstance()->GameTimer;
			
			// SpeedCollectable
			if (CollType == 1) {
				while (Game::GetGameInstance()->GameTimer > (PowTimer + 1.5f)) {
					// speed up the Player by 20% for 1.5 seconds
					SetMaxSpeed(MaxSpeed * 1.2);
				}
			}
			// RFCollectable
			else if (CollType == 2) {
				while (Game::GetGameInstance()->GameTimer > (PowTimer + 1.5f)) {
					// reduce the delay between Player shots by 20% for 1.5 seconds
					PFireRate = PFireRate * 0.8f;
				}
			}
			// ShieldCollectable
			else if (CollType == 3) {
				while (Game::GetGameInstance()->GameTimer > (PowTimer + 1.0f)) {
					// protect the Player from Enemy shots for 1 second

				}
			}
		}
	}
}
