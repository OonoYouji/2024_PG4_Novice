#include "GameScene.h"

#include "ClearScene.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {

}

void GameScene::Update() {
	if(inputManager_->TriggerKey(DIK_RIGHTARROW)) {
		sceneManager_->SetNextScene(new ClearScene());
	}

}

void GameScene::Draw() {

	Novice::ScreenPrintf(0, 0, "GameScene");

}