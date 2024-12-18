#pragma once


/// <summary>
/// コマンドのinterface class
/// </summary>
class ICommand {
public:
	
	virtual ~ICommand() = default;

	virtual void Execute(class Player& _player) = 0;
	//virtual void Undo()                         = 0;

};