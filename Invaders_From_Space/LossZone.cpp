#include "LossZone.h"
#include "Game.h"
#include "GSLoss.h"

LossZone::LossZone(Vector2 Position, Vector2 Dimensions)
{
	this->Position = Position;
	this->ObjectCenter = Position;

	SetCollision(this->Position, Dimensions);

}

void LossZone::Update(float DeltaTime)
{
	// Get overlapped colliders from the first collision
	vector<Collider*> OverCols = Collisions[0]->GetOverlappingColliders();

	// loop through the overlapped colliders and check if the player is within them
	// if so change the state to the menu state
	for (vector<Collider*>::iterator Col = OverCols.begin(); Col < OverCols.end(); Col++) {
		if ((*Col)->GetOwner()->Tag == "Player") {
			GSLoss* NewState = new GSLoss;
			Game::GetGameInstance()->ChangeGameState(NewState, 5);
		}
	}
}
