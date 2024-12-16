#include "GameScene.h"

#include "ClearScene.h"

#include "../Entities/Player/Player.h"
#include "../Entities/Enemy/Enemy.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {

	entities_.push_back(std::make_unique<Player>());
	entities_.push_back(std::make_unique<Enemy>());
	entities_.push_back(std::make_unique<Enemy>());


	for(auto& entity : entities_) {
		entity->Initialize();
	}

}

void GameScene::Update() {
	if(inputManager_->TriggerKey(DIK_RIGHTARROW)) {
		sceneManager_->SetNextScene(new ClearScene());
	}



	for(auto& entity : entities_) {
		entity->Update();
	}

}

void GameScene::Draw() {

	Novice::ScreenPrintf(0, 0, "GameScene");


	for(auto& entity : entities_) {
		entity->Draw();
	}
}