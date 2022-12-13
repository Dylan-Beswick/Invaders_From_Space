#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	MaxSpeed = 12.5f;
	Tag = "Enemy";
	EnemyCount = 0;
	DownTime = 0.0f;
	DirFlip = false;
	Direction = 0;
}

Enemy::~Enemy()
{

}

void Enemy::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	// change direction to Right after 1 second
	if (Game::GetGameInstance()->GameTimer >= (DownTime + 1.0f) && !DirFlip) {
		Direction = 0;
		SetDirection(Direction);
		// this runs fine if contact with BorderR sets DirFlip to false, causeing it to head left for one second before returning right
		// does not run if contact with BorderR sets Direction to 1, causeing it to travel down until it reaches the bottom
	}
	// change direction to Left after 1 second
	else if (Game::GetGameInstance()->GameTimer >= (DownTime + 1.0f) && DirFlip) {
		Direction = 2;
		SetDirection(Direction);
		// this runs fine if contact with BorderL sets DirFlip to true, causeing it to head right for one second before returning left
		// does not run if contact with BorderL sets Direction to 1, causeing it to travel down until it reaches the bottom
	}

	// store the colliders overlapping out collider
	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	// this will run through all the colliders overlapping each frame
	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "PBullet") {
			// remove the player bullet object from the screen
			(*it)->GetOwner()->DestroyGameObject();
		}
		else if ((*it)->GetOwner()->Tag == "EBullet") {
			// stop the enemy bullet object from spawning in that space
			(*it)->GetOwner()->DestroyGameObject();
		}
		else if ((*it)->GetOwner()->Tag == "BorderL") {
			// Direction = 1;
			Direction = 0;
			SetDirection(Direction);
			DirFlip = false;

			// reset the timer
			DownTime = Game::GetGameInstance()->GameTimer;
		}
		else if ((*it)->GetOwner()->Tag == "BorderR") {
			// Direction = 1;
			Direction = 2;
			SetDirection(Direction);
			DirFlip = true;

			// reset the timer
			DownTime = Game::GetGameInstance()->GameTimer;
		}
	}
}

int Enemy::SetDirection(int Direction)
{
	if (Direction == 0) {
		// set movement Right
		SetMovementAxis(Vector2(1.0f, 0.0f));
	}
	else if (Direction == 1) {
		// set movement Down	
		SetMovementAxis(Vector2(0.0f, 1.0f)); //- Doesn't allow for changing MovementAxis back to (x, 0)
	}
	else if (Direction == 2) {
		// set movement Left
		SetMovementAxis(Vector2(-1.0f, 0.0f));
	}

	return Direction;
}

int Enemy::SetEnemyCount(int EnemyCount)
{
	// Update the counter of remaining enemies
	this->EnemyCount == EnemyCount;

	return this->EnemyCount;
}
