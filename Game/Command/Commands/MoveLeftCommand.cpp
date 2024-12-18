#include "MoveLeftCommand.h"

#include "../../Entities/Player/Player.h"

void MoveLeftCommand::Execute(Player& _player) {
	_player.MoveLeft();
}
