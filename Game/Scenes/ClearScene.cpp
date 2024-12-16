#include "ClearScene.h"

#include "TitleScene.h"


ClearScene::ClearScene() {}
ClearScene::~ClearScene() {}


void ClearScene::Initialize() {

	clearSpriteHandle_ = Novice::LoadTexture("./Resources/Clear.png");

}

void ClearScene::Update() {
	if(inputManager_->TriggerKey(DIK_SPACE)) {
		sceneManager_->SetNextScene(new TitleScene());
	}

}

void ClearScene::Draw() {

	Novice::DrawSprite(0, 0, clearSpriteHandle_, 1.0f, 1.0f, 0.0f, 0xffffffff);

}