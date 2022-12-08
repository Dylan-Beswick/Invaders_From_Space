#include "RightBorder.h"
#include "Game.h"
#include "Character.h"
#include "Game.h"

RightBorder::RightBorder(Vector2 Position, Vector2 Dimensions)
{
	this->Position = Position;
	this->ObjectCenter = Position;
	Speed = 0.0f;
	PChara = nullptr;
	EChara = nullptr;
	DownTime = 0.0f;

	SetCollision(this->Position, Dimensions);
}

void RightBorder::Update(float DeltaTime)
{
	// Get overlapped colliders from the first collision
	vector<Collider*> BorderCols = Collisions[0]->GetOverlappingColliders();

	// loop through the overlapped colliders and check if the player is within them
	// if so change the state to the menu state
	for (vector<Collider*>::iterator Col = BorderCols.begin(); Col < BorderCols.end(); Col++) {
		if ((*Col)->GetOwner()->Tag == "Player") {
			PChara->SetMaxSpeed(); //- Didn't work/Crashed program
			// PChara->SetMovementAxis(Vector2(0.0f, 0.0f)); - Didn't work/Crashed program
		}
		else if ((*Col)->GetOwner()->Tag == "Enemy") {
			DownTime = Game::GetGameInstance()->GameTimer;

			while (Game::GetGameInstance()->GameTimer != (DownTime + 0.5)) {
				EChara->SetMovementAxis(Vector2(0.0f, 1.0f));
			}

			EChara->SetMovementAxis(Vector2(-1.0f, 0.0f));
		}
	}
}
