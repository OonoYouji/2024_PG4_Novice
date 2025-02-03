#include "StageSceneInputHandler.h"

void StageSceneInputHandler::UpdateKeyState() {}

IStageSceneCommand* StageSceneInputHandler::SelectHandleInput(Selector* _selector) { return nullptr; }

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* _unit) { return nullptr; }

bool StageSceneInputHandler::CheckUndoStatus() { return false; }
