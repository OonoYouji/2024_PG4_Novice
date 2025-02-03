#pragma once

/// std
#include <list>
#include <memory>
#include <vector>

/// user
#include "../Command/Commands/StageScene/StageSceneInputHandler.h"
#include "IScene/IScene.h"

class GameScene final : public IScene {
public:
	GameScene();
	~GameScene();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	std::unique_ptr<StageSceneInputHandler>  inputHandler_;
	IStageSceneCommand*                      command_;
	std::list<IStageSceneCommand*>           commandHistory_;
	std::list<IStageSceneCommand*>::iterator commandHistoryItr_;

	Selector*                                selector_;
};
