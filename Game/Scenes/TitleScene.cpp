#include "TitleScene.h"

#include "GameScene.h"

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::Initialize() {
	titleSpriteHandle_ = Novice::LoadTexture("./Resources/Title.png");
}

void TitleScene::Update() {
	if(inputManager_->TriggerKey(DIK_SPACE)) {
		sceneManager_->SetNextScene(new GameScene());
	}
}

void TitleScene::Draw() {

	Novice::DrawSprite(0, 0, titleSpriteHandle_, 1.0f, 1.0f, 0.0f, 0xffffffff);

}