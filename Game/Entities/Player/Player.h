#pragma once

#include "../IEntity/IEntity.h"

class Player : public IEntity {
public:

	Player();
	~Player();
	
	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:

	class InputManager* inputManager_ = nullptr;

	Vector2 velocity_;

};

