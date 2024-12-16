#include "ClearScene.h"

#include "TitleScene.h"


ClearScene::ClearScene() {}
ClearScene::~ClearScene() {}


void ClearScene::Initialize() {

}

void ClearScene::Update() {
	if(inputManager_->TriggerKey(DIK_RIGHTARROW)) {
		sceneManager_->SetNextScene(new TitleScene());
	}

}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "ClearScene");

}