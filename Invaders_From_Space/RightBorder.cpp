#include "RightBorder.h"
#include "Game.h"
#include "Character.h"
#include "Game.h"
#include "Enemy.h";

RightBorder::RightBorder(Vector2 Position, Vector2 Dimensions)
{
	this->Position = Position;
	this->ObjectCenter = Position;
	Tag = "BorderR";

	SetCollision(this->Position, Dimensions);
}
