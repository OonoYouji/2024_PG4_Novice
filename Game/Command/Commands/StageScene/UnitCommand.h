#pragma once

class Unit {
public:
	Unit() = default;
	~Unit() = default;

	void Initialize(int _idref);
	void Update();
	void Draw();

	void Move(int _x, int _y);
	void MoveEnd(class Selector* _selector);

private:

	int mapX_        = 0;
	int mapY_        = 0;
	int mapSize_     = 32;
	int id_          = 0;
	bool isSelected_ = false;

};