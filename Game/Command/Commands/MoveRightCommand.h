#pragma once

#include "../ICommand/ICommand.h"


/// <summary>
/// 右に移動するコマンド
/// </summary>
class MoveRightCommand : public ICommand {
public:

	MoveRightCommand() {}
	~MoveRightCommand() {}

	void Execute(class Player& _player) override;

};