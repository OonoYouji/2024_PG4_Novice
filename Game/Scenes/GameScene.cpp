#include "GameScene.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {
	inputHandler_ = std::make_unique<StageSceneInputHandler>();

	//selector_->Initialize();
}

void GameScene::Update() {

	/// update key state
	inputHandler_->UpdateKeyState();

	/// get command type
	if (selector_->GetSelectMode() == SELECTOR) {
		command_ = inputHandler_->SelectHandleInput(selector_);
	} else if (selector_->GetSelectMode() == UNIT) {
		command_ = inputHandler_->UnitHandleInput(selector_->GetSelectedUnitAddress());
	}

}

void GameScene::Draw() {}
