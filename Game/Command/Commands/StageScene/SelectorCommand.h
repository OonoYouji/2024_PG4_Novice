#pragma once

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


};