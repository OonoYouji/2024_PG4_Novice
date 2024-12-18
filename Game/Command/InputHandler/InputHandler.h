#pragma once

/// std
#include <memory>

#include "../ICommand/ICommand.h"


/// <summary>
/// 入力まとめたクラス
/// </summary>
class InputHandler {
public:

	InputHandler();
	~InputHandler();


	ICommand* HandleInput();


	void AssingRightMoveCommandToPressKeyD();
	void AssingLeftMoveCommandToPressKeyA();

private:

	class InputManager* inputManager_;

	std::unique_ptr<ICommand> rightMoveCommand_;
	std::unique_ptr<ICommand> leftMoveCommand_;

};