#include "InputHandler.h"

#include "../../InputManager/InputManager.h"

#include "../Commands/MoveRightCommand.h"
#include "../Commands/MoveLeftCommand.h"


InputHandler::InputHandler() {
	inputManager_ = InputManager::GetInstance();
}

InputHandler::~InputHandler() {}

ICommand* InputHandler::HandleInput() {

	/// 左へ移動する
	if(inputManager_->PressKey(DIK_A)) {
		return leftMoveCommand_.get();
	}
	
	/// 右へ移動する
	if(inputManager_->PressKey(DIK_D)) {
		return rightMoveCommand_.get();
	}

	///　何もしない
	return nullptr;
}

void InputHandler::AssingRightMoveCommandToPressKeyD() {
	rightMoveCommand_.reset(new MoveRightCommand());

}

void InputHandler::AssingLeftMoveCommandToPressKeyA() {
	leftMoveCommand_.reset(new MoveLeftCommand());
}
