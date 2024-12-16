#include "TitleScene.h"

#include "GameScene.h"

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::Initialize() {

}

void TitleScene::Update() {
	if(inputManager_->TriggerKey(DIK_RIGHTARROW)) {
		sceneManager_->SetNextScene(new GameScene());
	}
}

void TitleScene::Draw() {

	Novice::ScreenPrintf(0, 0, "TitleScene");

}