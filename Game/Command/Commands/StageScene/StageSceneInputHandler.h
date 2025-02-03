#pragma once

/// user
#include "IStageSceneCommand.h"
#include "SelectorCommand.h"


class StageSceneInputHandler {
public:
	StageSceneInputHandler() = default;
	~StageSceneInputHandler() = default;

	void UpdateKeyState();

	IStageSceneCommand* SelectHandleInput(Selector* _selector);
	IStageSceneCommand* UnitHandleInput(Unit* _unit);

	bool CheckUndoStatus();

private:
	char keys_[256];
	char prevKeys_[256];

	Selector* selector_;
	Unit* selectedUnit_;
};