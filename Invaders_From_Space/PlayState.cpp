#include "PlayState.h"
#include "Player.h"
#include "Enemy.h"
#include "LossZone.h"
#include "Barrier.h"
#include <string>
#include "Game.h"
#include "LeftBorder.h"
#include "RightBorder.h"

PlayState::PlayState()
{
	DBColour = { 0, 0, 50, 255 };
	TXT_PPosition = nullptr;
	PChar = nullptr;
	Music_BG = nullptr;
	TXT_Score = nullptr;
}

void PlayState::Update(float DeltaTime)
{
	GameState::Update(DeltaTime);

	// make sure the player character exist
	if (PChar != nullptr) {
		// initialise some integers to use for concatenation
		// use integers so that we don't display decimals
		int PlayerX = 0;
		float PlayerSpeed = 0.0f;

		// set the x and y to the players position
		// convert the floats into ingegers
		PlayerX = static_cast<int>(PChar->GetPosition().x);

		/*if (PlayerX <= 128) {
			PChar->SetMaxSpeed();
			PChar->SetMovementAxis(Vector2(0.0f, 0.0f));
		} - neither cause any effect*/

	}
}

void PlayState::Draw(SDL_Renderer* Renderer)
{
	GameState::Draw(Renderer);

	if (TXT_Score != nullptr) {
		TXT_Score->Draw(Renderer);
	}
}

void PlayState::ProcessInput(Input* UserInput)
{
	GameState::ProcessInput(UserInput);

	if (UserInput->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
			Game::GetGameInstance()->bIsGamePaused = true;
		}
	else if (UserInput->IsKeyDown(SDL_SCANCODE_GRAVE)) {
			Game::GetGameInstance()->bIsGamePaused = false;
		}
}

bool PlayState::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	int ECount = 0;

	SDL_Log("Entered PlayState...");

	//initiallised the player texture
	Texture* PlayerTexture = new Texture();
	// load the player texture
	PlayerTexture->LoadImageFromFile("Assets/player-spritesheet-32x32-22.png", Renderer);
	// construct the player as a character
	PChar = new Player(PlayerTexture, Vector2(256, 512), 22);
	GameObjectStack.push_back(PChar);

	//initiallised the barrier texture
	Texture* BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier1 = new Barrier(BarrierTexture, Vector2(32, 471), 5);
	GameObjectStack.push_back(Barrier1);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier2 = new Barrier(BarrierTexture, Vector2(98, 471), 5);
	GameObjectStack.push_back(Barrier2);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier3 = new Barrier(BarrierTexture, Vector2(162, 471), 5);
	GameObjectStack.push_back(Barrier3);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier4 = new Barrier(BarrierTexture, Vector2(226, 471), 5);
	GameObjectStack.push_back(Barrier4);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier5 = new Barrier(BarrierTexture, Vector2(290, 471), 5);
	GameObjectStack.push_back(Barrier5);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier6 = new Barrier(BarrierTexture, Vector2(354, 471), 5);
	GameObjectStack.push_back(Barrier6);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier7 = new Barrier(BarrierTexture, Vector2(418, 471), 5);
	GameObjectStack.push_back(Barrier7);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier8 = new Barrier(BarrierTexture, Vector2(482, 471), 5);
	GameObjectStack.push_back(Barrier8);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier9 = new Barrier(BarrierTexture, Vector2(546, 471), 5);
	GameObjectStack.push_back(Barrier9);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier-spritesheet-32x32-5.png", Renderer);
	// construct the Barrier as a entity
	Barrier* Barrier10 = new Barrier(BarrierTexture, Vector2(610, 471), 5);
	GameObjectStack.push_back(Barrier10);

	//initiallised the enemy texture
	Texture* EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
// construct the second enemy as an Enemy using the same enemy texture
	Enemy* EnemyCharacter1a = new Enemy(EnemyTexture, Vector2(64, 32), 22);
	GameObjectStack.push_back(EnemyCharacter1a);
	
	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter2a = new Enemy(EnemyTexture, Vector2(96, 32), 22);
	GameObjectStack.push_back(EnemyCharacter2a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter3a = new Enemy(EnemyTexture, Vector2(128, 32), 22);
	GameObjectStack.push_back(EnemyCharacter3a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter4a = new Enemy(EnemyTexture, Vector2(160, 32), 22);
	GameObjectStack.push_back(EnemyCharacter4a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter5a = new Enemy(EnemyTexture, Vector2(192, 32), 22);
	GameObjectStack.push_back(EnemyCharacter5a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter6a = new Enemy(EnemyTexture, Vector2(224, 32), 22);
	GameObjectStack.push_back(EnemyCharacter6a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter7a = new Enemy(EnemyTexture, Vector2(256, 32), 22);
	GameObjectStack.push_back(EnemyCharacter7a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter8a = new Enemy(EnemyTexture, Vector2(288, 32), 22);
	GameObjectStack.push_back(EnemyCharacter8a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter9a = new Enemy(EnemyTexture, Vector2(320, 32), 22);
	GameObjectStack.push_back(EnemyCharacter9a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter10a = new Enemy(EnemyTexture, Vector2(352, 32), 22);
	GameObjectStack.push_back(EnemyCharacter10a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter11a = new Enemy(EnemyTexture, Vector2(384, 32), 22);
	GameObjectStack.push_back(EnemyCharacter11a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter12a = new Enemy(EnemyTexture, Vector2(416, 32), 22);
	GameObjectStack.push_back(EnemyCharacter12a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter13a = new Enemy(EnemyTexture, Vector2(448, 32), 22);
	GameObjectStack.push_back(EnemyCharacter13a);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter1b = new Enemy(EnemyTexture, Vector2(64, 96), 22);
	GameObjectStack.push_back(EnemyCharacter1b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter2b = new Enemy(EnemyTexture, Vector2(96, 96), 22);
	GameObjectStack.push_back(EnemyCharacter2b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter3b = new Enemy(EnemyTexture, Vector2(128, 96), 22);
	GameObjectStack.push_back(EnemyCharacter3b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter4b = new Enemy(EnemyTexture, Vector2(160, 96), 22);
	GameObjectStack.push_back(EnemyCharacter4b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter5b = new Enemy(EnemyTexture, Vector2(192, 96), 22);
	GameObjectStack.push_back(EnemyCharacter5b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter6b = new Enemy(EnemyTexture, Vector2(224, 96), 22);
	GameObjectStack.push_back(EnemyCharacter6b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter7b = new Enemy(EnemyTexture, Vector2(256, 96), 22);
	GameObjectStack.push_back(EnemyCharacter7b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter8b = new Enemy(EnemyTexture, Vector2(288, 96), 22);
	GameObjectStack.push_back(EnemyCharacter8b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter9b = new Enemy(EnemyTexture, Vector2(320, 96), 22);
	GameObjectStack.push_back(EnemyCharacter9b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter10b = new Enemy(EnemyTexture, Vector2(352, 96), 22);
	GameObjectStack.push_back(EnemyCharacter10b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter11b = new Enemy(EnemyTexture, Vector2(384, 96), 22);
	GameObjectStack.push_back(EnemyCharacter11b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter12b = new Enemy(EnemyTexture, Vector2(416, 96), 22);
	GameObjectStack.push_back(EnemyCharacter12b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter13b = new Enemy(EnemyTexture, Vector2(448, 96), 22);
	GameObjectStack.push_back(EnemyCharacter13b);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter1c = new Enemy(EnemyTexture, Vector2(64, 160), 22);
	GameObjectStack.push_back(EnemyCharacter1c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter2c = new Enemy(EnemyTexture, Vector2(96, 160), 22);
	GameObjectStack.push_back(EnemyCharacter2c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter3c = new Enemy(EnemyTexture, Vector2(128, 160), 22);
	GameObjectStack.push_back(EnemyCharacter3c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter4c = new Enemy(EnemyTexture, Vector2(160, 160), 22);
	GameObjectStack.push_back(EnemyCharacter4c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter5c = new Enemy(EnemyTexture, Vector2(192, 160), 22);
	GameObjectStack.push_back(EnemyCharacter5c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter6c = new Enemy(EnemyTexture, Vector2(224, 160), 22);
	GameObjectStack.push_back(EnemyCharacter6c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter7c = new Enemy(EnemyTexture, Vector2(256, 160), 22);
	GameObjectStack.push_back(EnemyCharacter7c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter8c = new Enemy(EnemyTexture, Vector2(288, 160), 22);
	GameObjectStack.push_back(EnemyCharacter8c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter9c = new Enemy(EnemyTexture, Vector2(320, 160), 22);
	GameObjectStack.push_back(EnemyCharacter9c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter10c = new Enemy(EnemyTexture, Vector2(352, 160), 22);
	GameObjectStack.push_back(EnemyCharacter10c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter11c = new Enemy(EnemyTexture, Vector2(384, 160), 22);
	GameObjectStack.push_back(EnemyCharacter11c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter12c = new Enemy(EnemyTexture, Vector2(416, 160), 22);
	GameObjectStack.push_back(EnemyCharacter12c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter13c = new Enemy(EnemyTexture, Vector2(448, 160), 22);
	GameObjectStack.push_back(EnemyCharacter13c);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter1d = new Enemy(EnemyTexture, Vector2(64, 224), 22);
	GameObjectStack.push_back(EnemyCharacter1d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter2d = new Enemy(EnemyTexture, Vector2(96, 224), 22);
	GameObjectStack.push_back(EnemyCharacter2d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter3d = new Enemy(EnemyTexture, Vector2(128, 224), 22);
	GameObjectStack.push_back(EnemyCharacter3d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter4d = new Enemy(EnemyTexture, Vector2(160, 224), 22);
	GameObjectStack.push_back(EnemyCharacter4d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter5d = new Enemy(EnemyTexture, Vector2(192, 224), 22);
	GameObjectStack.push_back(EnemyCharacter5d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter6d = new Enemy(EnemyTexture, Vector2(224, 224), 22);
	GameObjectStack.push_back(EnemyCharacter6d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter7d = new Enemy(EnemyTexture, Vector2(256, 224), 22);
	GameObjectStack.push_back(EnemyCharacter7d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter8d = new Enemy(EnemyTexture, Vector2(288, 224), 22);
	GameObjectStack.push_back(EnemyCharacter8d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter9d = new Enemy(EnemyTexture, Vector2(320, 224), 22);
	GameObjectStack.push_back(EnemyCharacter9d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter10d = new Enemy(EnemyTexture, Vector2(352, 224), 22);
	GameObjectStack.push_back(EnemyCharacter10d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter11d = new Enemy(EnemyTexture, Vector2(384, 224), 22);
	GameObjectStack.push_back(EnemyCharacter11d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter12d = new Enemy(EnemyTexture, Vector2(416, 224), 22);
	GameObjectStack.push_back(EnemyCharacter12d);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy-spritesheet-32x32-22.png", Renderer);
	// construct as an Enemy using the same enemy texture
	Enemy* EnemyCharacter13d = new Enemy(EnemyTexture, Vector2(448, 224), 22);
	GameObjectStack.push_back(EnemyCharacter13d);

	// construct a Loss Zone
	LossZone* Lose = new LossZone(Vector2(0.0f, 462.0f), Vector2(544.0f, 50.0f));
	GameObjectStack.push_back(Lose);

	// construct a border on the left side of the screen
	LeftBorder* Left = new LeftBorder(Vector2(0.0f, 0.0f), Vector2(16.0f, 704.0f));
	GameObjectStack.push_back(Left);

	// construct a border on the right side of the screen
	RightBorder* Right = new RightBorder(Vector2(0.0f, 0.0f), Vector2(528.0f, 704.0f));
	GameObjectStack.push_back(Right);

	// find the music and load it
	Music_BG = Mix_LoadMUS("Assets/BackgoundMusic.wav");

	// play the music
	if (Music_BG != nullptr) {
		Mix_PlayMusic(Music_BG, -1);
	}

	return true;
}

bool PlayState::OnExit()
{
	SDL_Log("Exited PlayState...");

	if (PChar != nullptr) {
		PChar = nullptr;
	}

	// deallocate the text
	if (TXT_PPosition != nullptr) {
		delete TXT_PPosition;
		TXT_PPosition = nullptr;
	}
	// deallocate the score text
	if (TXT_Score != nullptr) {
		delete TXT_Score;
		TXT_Score = nullptr;
	}

	if (Music_BG != nullptr) {
		Mix_FreeMusic(Music_BG);
		Music_BG = nullptr;

	}

	return true;
}
