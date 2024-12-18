#pragma once

#include "../ICommand/ICommand.h"


/// <summary>
/// 右に移動するコマンド
/// </summary>
class MoveLeftCommand : public ICommand {
public:

	MoveLeftCommand() {}
	~MoveLeftCommand() {}

	void Execute(class Player& _player) override;

};