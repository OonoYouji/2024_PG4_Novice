#include "SceneManager.h"

void SceneManager::Initialize() {}

void SceneManager::Update() {}

void SceneManager::Draw() {}

void SceneManager::Finalize() {}

void SceneManager::SetNextScene(IScene* _nextScene) {
	nextScene_ = std::unique_ptr<IScene>(_nextScene);
}
