#include "LeftBorder.h"
#include "Game.h"
#include "Character.h"

LeftBorder::LeftBorder(Vector2 Position, Vector2 Dimensions)
{
	this->Position = Position;
	this->ObjectCenter = Position;
	Tag = "BorderL";

	SetCollision(this->Position, Dimensions);
}
