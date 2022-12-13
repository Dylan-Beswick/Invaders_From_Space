#include "PlayState.h"
#include "Player.h"
#include "Enemy.h"
#include "LossZone.h"
#include "Barrier.h"
#include <string>
#include "Game.h"
#include "LeftBorder.h"
#include "RightBorder.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"

PlayState::PlayState()
{
	DBColour = { 0, 0, 50, 255 };
	TXT_PPosition = nullptr;
	PChar = nullptr;
	EChar = nullptr;
	BChar = nullptr;
	Music_BG = nullptr;
	TXT_Score = nullptr;
	Player::bPlayerFire = false;
}

void PlayState::Update(float DeltaTime, SDL_Renderer* Renderer)
{
	GameState::Update(DeltaTime);

	// make sure the player character exist
	if (PChar != nullptr) {
		// initialise some integers to use for concatenation
		// use integers so that we don't display decimals
		int BulletX = 0;
		int BulletY = 0;
		float PlayerSpeed = 0.0f;

		// set the x and y to the players position
		// convert the floats into ingegers
		BulletX = static_cast<int>(PChar->GetPosition().x) + 7;
		BulletY = static_cast<int>(PChar->GetPosition().y) - 18;

		// when the Player has clicked the fire button, spawn a bullet entity
		if (Player::bPlayerFire) {
			//initiallised the Bullet texture
			Texture* PBulletImage = new Texture();
			// load the Bullet texture
			PBulletImage->LoadImageFromFile("Assets/pBullet.png", Renderer);
			// construct the Bullet as a character
			PlayerBullet* PlayBullet = new PlayerBullet(PBulletImage, Vector2(BulletX, BulletY), 1);
			GameObjectStack.push_back(PlayBullet);

			Player::bPlayerFire = false;
		}

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

	// when the Player clicks "ESCAPE", pause the game
	if (UserInput->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
			Game::GetGameInstance()->bIsGamePaused = true;
	}
	// when the Player clicks "GRAVE" (key above "TAB"), resume the game
	else if (UserInput->IsKeyDown(SDL_SCANCODE_GRAVE)) {
			Game::GetGameInstance()->bIsGamePaused = false;
	}
}

bool PlayState::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	int ECount = 0;

	SDL_Log("Entered PlayState...");

	//initiallised the Background texture
	Texture* BackgroundImage = new Texture();
	// load the Background texture
	BackgroundImage->LoadImageFromFile("Assets/PlayBackground.png", Renderer);
	// construct the Background as a character
	Character* Background = new Character(BackgroundImage, Vector2(0, 0), 1);
	GameObjectStack.push_back(Background);

	//initiallised the Background texture
	Texture* PBulletImage = new Texture();
	// load the Background texture
	PBulletImage->LoadImageFromFile("Assets/pBullet.png", Renderer);
	// construct the Background as a character
	PlayerBullet* PlayBullet = new PlayerBullet(PBulletImage, Vector2(270, 458), 1);
	GameObjectStack.push_back(PlayBullet);

	//initiallised the Background texture
	Texture* EBulletImage = new Texture();
	// load the Background texture
	EBulletImage->LoadImageFromFile("Assets/eBullet.png", Renderer);
	// construct the Background as a character
	EnemyBullet* EnBullet = new EnemyBullet(EBulletImage, Vector2(166, 198), 1);
	GameObjectStack.push_back(EnBullet);

	//initiallised the player texture
	Texture* PlayerTexture = new Texture();
	// load the player texture
	PlayerTexture->LoadImageFromFile("Assets/player.png", Renderer);
	// construct the player as a character
	PChar = new Player(PlayerTexture, Vector2(263, 566), 1);
	GameObjectStack.push_back(PChar);

	//initiallised the barrier texture
	Texture* BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier4.png", Renderer);
	// construct the Barrier as a entity
	BChar = new Barrier(BarrierTexture, Vector2(51, 502), 1);
	GameObjectStack.push_back(BChar);
	
	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier2.png", Renderer);
	// construct the Barrier as a entity
	BChar = new Barrier(BarrierTexture, Vector2(155, 490), 1);
	GameObjectStack.push_back(BChar);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier1.png", Renderer);
	// construct the Barrier as a entity
	BChar = new Barrier(BarrierTexture, Vector2(259, 490), 1);
	GameObjectStack.push_back(BChar);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier3.png", Renderer);
	// construct the Barrier as a entity
	BChar = new Barrier(BarrierTexture, Vector2(363, 494), 1);
	GameObjectStack.push_back(BChar);

	//initiallised the barrier texture
	BarrierTexture = new Texture();
	// load the Barrier texture
	BarrierTexture->LoadImageFromFile("Assets/barrier5.png", Renderer);
	// construct the Barrier as a entity
	BChar = new Barrier(BarrierTexture, Vector2(475, 512), 1);
	GameObjectStack.push_back(BChar);

	//initiallised the enemy texture
	Texture* EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct the second enemy as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(71, 71), 1);
	GameObjectStack.push_back(EChar);
	
	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(135, 71), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(199, 71), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(263, 71), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(327, 71), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(391, 71), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(465, 71), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct the second enemy as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(71, 112), 1);
	GameObjectStack.push_back(EChar);
	
	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(135, 112), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(199, 112), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(263, 112), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(327, 112), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(391, 112), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(465, 112), 1);
	GameObjectStack.push_back(EChar);
	
	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct the second enemy as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(71, 176), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(135, 176), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(199, 176), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(263, 176), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(327, 176), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(391, 176), 1);
	GameObjectStack.push_back(EChar);

	//initiallised the enemy texture
	EnemyTexture = new Texture();
	// load the enemy texture
	EnemyTexture->LoadImageFromFile("Assets/enemy.png", Renderer);
	// construct as an Enemy using the same enemy texture
	EChar = new Enemy(EnemyTexture, Vector2(465, 176), 1);
	GameObjectStack.push_back(EChar);

	// construct a Loss Zone
	LossZone* Lose = new LossZone(Vector2(0.0f, 487.0f), Vector2(544.0f, 50.0f));
	GameObjectStack.push_back(Lose);

	// construct a border on the left side of the screen
	LeftBorder* Left = new LeftBorder(Vector2(0.0f, 0.0f), Vector2(16.0f, 704.0f));
	GameObjectStack.push_back(Left);
	// above and below are different sized borders, despite being stated as the same size?
	// construct a border on the right side of the screen
	RightBorder* Right = new RightBorder(Vector2(528.0f, 0.0f), Vector2(16.0f, 704.0f));
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
