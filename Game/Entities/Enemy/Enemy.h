#pragma once

#include "../IEntity/IEntity.h"


class Enemy : public IEntity {
public:

	Enemy();
	~Enemy();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

	void OnCollision(IEntity* _other) override;

private:

	int hp_;
	int maxHp_;

	Vector2 prevPosition_;
	Vector2 velocity_;
	float   speed_;

	float actionFrameTime_;

	bool isAlive_ = true;

public:

	/// <summary>
	/// 生存フラグの取得
	/// </summary>
	/// <returns></returns>
	bool GetIsAlive() const {
		return isAlive_;
	}

};