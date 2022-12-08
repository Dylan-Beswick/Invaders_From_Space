#include "Enemy.h"

Enemy::Enemy(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	MaxSpeed = 25.0f;
	Tag = "Enemy";
	EnemyCount = 0;
}

Enemy::~Enemy()
{

}

void Enemy::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	SetMovementAxis(Vector2(1.0f, 0.0f));
}

int Enemy::SetEnemyCount(int EnemyCount)
{
	this->EnemyCount == EnemyCount;

	return this->EnemyCount;
}
