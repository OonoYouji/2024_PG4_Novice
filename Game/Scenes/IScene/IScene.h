#pragma once

#include <Novice.h>
#include "../../InputManager/InputManager.h"
#include "../SceneManager/SceneManager.h"

/// <summary>
/// シーンのインターフェイスクラス
/// </summary>
class IScene {
public:

	virtual ~IScene() = default;

	virtual void Initialize() = 0;
	virtual void Update()     = 0;
	virtual void Draw()       = 0;

protected:
	InputManager* inputManager_ = InputManager::GetInstance();
	SceneManager* sceneManager_ = SceneManager::GetInstance();
};