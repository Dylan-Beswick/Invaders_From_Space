#include "Player.h"
#include "SDL.h"
#include "Game.h"

bool Player::bPlayerFire = false;
float Player::Speed = 0.0f;

Player::Player(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	Tag = "Player";
	Speed = 0.0f;
	ShootTime = 0.0f;
	SetMovementAxis(Vector2(0.0f, 0.0f));
}

Player::~Player()
{

}

void Player::Update(float DeltaTime)
{
	Character::Update(DeltaTime);


}

void Player::ProcessInput(Input* UserInput)
{
	float MovementX = 0.0f;
	float MovementY = 0.0f;

	// check if A key is down
	if (UserInput->IsKeyDown(SDL_SCANCODE_A)) {
		MovementX = 1.0f;
	}

	// check if Left Arrow is down
	if (UserInput->IsKeyDown(SDL_SCANCODE_LEFT)) {
		MovementX = -1.0f;
	}

	// check if D key is down
	if (UserInput->IsKeyDown(SDL_SCANCODE_D)) {
		MovementX = 1.0f;
	}

	// check if Right Arrow is down
	if (UserInput->IsKeyDown(SDL_SCANCODE_RIGHT)) {
		MovementX = 1.0f;
	}

	// store the colliders overlapping out collider
	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	SFX_Enter = Mix_LoadWAV("Assets/EntryAudio.wav");

	if (UserInput->IsKeyDown(SDL_SCANCODE_SPACE)) {
		
		// limit how quickly the player is allowed to fire
		if (Game::GetGameInstance()->GameTimer >= (ShootTime + PFireRate)) {
			Player::bPlayerFire = true;
			// play a sound to confirm shoot
			if (SFX_Enter != nullptr) {
				Mix_PlayChannel(-1, SFX_Enter, 0);
			}
			// "reset" shoot cooldown
			ShootTime = Game::GetGameInstance()->GameTimer;
		}
	}
	if (UserInput->IsKeyDown(SDL_SCANCODE_UP)) {

		// limit how quickly the player is allowed to fire
		if (Game::GetGameInstance()->GameTimer >= (ShootTime + 1.5)) {
			Player::bPlayerFire = true;
			if (SFX_Enter != nullptr) {
				Mix_PlayChannel(-1, SFX_Enter, 0);
			}
			// "reset" shoot cooldown
			ShootTime = Game::GetGameInstance()->GameTimer;
		}
	}

	// this will run through all the colliders overlapping each frame
	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "Collectable") {
			(*it)->GetOwner()->DestroyGameObject();
		}
		else if ((*it)->GetOwner()->Tag == "EBullet") {
			// remove the enemy bullet object from the screen
				(*it)->GetOwner()->DestroyGameObject();
		}
		else if ((*it)->GetOwner()->Tag == "BorderL" && (UserInput->IsKeyDown(SDL_SCANCODE_A) || UserInput->IsKeyDown(SDL_SCANCODE_LEFT))) {
			// stop the player from moving Left when it reaches the border
			MovementX = 0.0f;
		}
		else if ((*it)->GetOwner()->Tag == "BorderR" && (UserInput->IsKeyDown(SDL_SCANCODE_D) || UserInput->IsKeyDown(SDL_SCANCODE_RIGHT))) {
			// stop the player from moving Right when it reaches the border
			MovementX = 0.0f;
		}
	}

	SetMovementAxis(Vector2(MovementX, MovementY));
}
