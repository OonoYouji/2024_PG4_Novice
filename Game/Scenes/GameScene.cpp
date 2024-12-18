#include "GameScene.h"


GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {

	player_.reset(new Player());
	player_->Initialize();

	inputHandler_ = std::make_unique<InputHandler>();
	inputHandler_->AssingRightMoveCommandToPressKeyD();
	inputHandler_->AssingLeftMoveCommandToPressKeyA();

	iCommand_ = nullptr;
}

void GameScene::Update() {

	iCommand_ = inputHandler_->HandleInput();
	if(iCommand_ != nullptr) {
		iCommand_->Execute(*player_);
	}

	player_->Update();
}

void GameScene::Draw() {

	player_->Draw();
}

