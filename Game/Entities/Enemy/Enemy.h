#pragma once

#include "../IEntity/IEntity.h"


class Enemy : public IEntity {
public:

	Enemy();
	~Enemy();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:

	int hp_;
	int maxHp_;

	Vector2 prevPosition_;
	Vector2 velocity_;
	float   speed_;

	float actionFrameTime_;

};