#include "SelectorCommand.h"

void Selector::Initialize() {

}

void Selector::Update() {
	
}

void Selector::Draw() {

}



void Selector::Move(int _x, int _y) {

}

void Selector::SelectUnit() {

}


/// ==================================================================================
/// move command
/// ==================================================================================

SelectorMoveCommand::SelectorMoveCommand(Selector* _selector, int _x, int _y) {

}

void SelectorMoveCommand::Execute() {

}


/// ==================================================================================
/// select unit command
/// ==================================================================================

SelectUnitCommand::SelectUnitCommand(Selector* _selector) {

}

void SelectUnitCommand::Execute() {

}


/// ==================================================================================
/// unit move command
/// ==================================================================================

UnitMoveCommand::UnitMoveCommand(Unit* _unit, int _x, int _y) {}

void UnitMoveCommand::Execute() {}


/// ==================================================================================
/// unit move end command
/// ==================================================================================

UnitMoveEndCommand::UnitMoveEndCommand(Unit* _unit, Selector* _selector) {}

void UnitMoveEndCommand::Execute() {}
