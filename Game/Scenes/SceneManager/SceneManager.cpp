#include "SceneManager.h"

void SceneManager::Initialize() {}

void SceneManager::Update() {

	if(nextScene_.get() != nullptr) {
		currentScene_ = std::move(nextScene_);
		currentScene_->Initialize();
		nextScene_.reset();
	}

	currentScene_->Update();
}

void SceneManager::Draw() {
	currentScene_->Draw();
}

void SceneManager::Finalize() {
	currentScene_.reset();
	nextScene_.reset();
}

void SceneManager::SetNextScene(IScene* _nextScene) {
	nextScene_ = std::unique_ptr<IScene>(_nextScene);
}
