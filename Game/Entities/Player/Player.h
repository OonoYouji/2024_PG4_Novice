#pragma once

/// std
#include <vector>
#include <memory>

#include "../IEntity/IEntity.h"

class Player : public IEntity {
public:

	Player();
	~Player();
	
	void Initialize() override;
	void Update()     override;
	void Draw()       override;


	void MoveLeft();
	void MoveRight();

private:

	float speed_;
	Vector2 size_;

};

