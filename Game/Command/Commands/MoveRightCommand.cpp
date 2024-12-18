#include "MoveRightCommand.h"

#include "../../Entities/Player/Player.h"

void MoveRightCommand::Execute(Player& _player) {
	_player.MoveRight();
}
