#pragma once

/// user
#include "IStageSceneCommand.h"
#include "UnitCommand.h"

/// ==================================================================================
/// select mode enum
/// ==================================================================================
enum SelectMode {
	SELECTOR, /// select mode
	UNIT      /// unit mode
};

/// ==================================================================================
/// selector
/// ==================================================================================
class Selector {
public:
	Selector() = default;
	~Selector() = default;

	void Initialize();
	void Update();
	void Draw();

	void Move(int _x, int _y);
	void SelectUnit();

private:
	int mapX_;
	int mapY_;
	int mapSize_;

	int selectMode_;

	Unit* unit_;
	Unit* selectedUnit_;

public:
	int GetSelectMode() { return selectMode_; }
	Unit* GetSelectedUnitAddress() { return unit_; }
};

/// ==================================================================================
/// move command
/// ==================================================================================
class SelectorMoveCommand : public IStageSceneCommand {
public:
	SelectorMoveCommand(Selector* _selector, int _x, int _y);
	void Execute() override;

private:
	Selector* selector_;
	int x_;
	int y_;
};

/// ==================================================================================
/// select unit command
/// ==================================================================================
class SelectUnitCommand : public IStageSceneCommand {
public:
	SelectUnitCommand(Selector* _selector);
	void Execute() override;

private:
	Selector* selector_;
};

/// ==================================================================================
/// unit move command
/// ==================================================================================
class UnitMoveCommand : public IStageSceneCommand {
public:
	UnitMoveCommand(Unit* _unit, int _x, int _y);
	void Execute() override;

private:
	Unit* unit_;
	int x_;
	int y_;
};

/// ==================================================================================
/// unit move end command
/// ==================================================================================
class UnitMoveEndCommand : public IStageSceneCommand {
public:
	UnitMoveEndCommand(Unit* _unit, Selector* _selector);
	void Execute() override;

private:
	Unit* unit_;
	Selector* selector_;
};