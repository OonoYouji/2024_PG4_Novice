#include "Enemy.h"

#include <Novice.h>


Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::Initialize() {
	SetTag("Enemy");

	maxHp_    = 100;
	hp_       = maxHp_;
	position_ = Vector2(640.0f, 360.0f - 200.0f);
	radius_   = 45.0f;
	velocity_ = Vector2(0.0f, 1.0f);
	speed_    = 2.0f;

	actionFrameTime_ = 0.0f;
}

void Enemy::Update() {

	/// 前フレームの座標を保存
	prevPosition_ = position_;

	/// delta timeの変わり
	actionFrameTime_ += 1.0f / 60.0f;

	position_ = {
		640.0f + 200.0f * std::cos(actionFrameTime_),
		160.0f + 50.0f * std::sin(actionFrameTime_)
	};


}

void Enemy::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(position_.x),
		static_cast<int>(position_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0, RED, kFillModeSolid
	);

	Novice::DrawEllipse(
		static_cast<int>(prevPosition_.x),
		static_cast<int>(prevPosition_.y),
		static_cast<int>(radius_ / 3.0f),
		static_cast<int>(radius_ / 3.0f),
		0, BLACK, kFillModeSolid
	);



	Novice::ScreenPrintf(
		static_cast<int>(prevPosition_.x - (radius_ * 0.5f)),
		static_cast<int>(prevPosition_.y - radius_),
		"HP: %d/%d", hp_, maxHp_
	);

}

void Enemy::OnCollision(IEntity* _other) {
	if(_other->GetTag() == "PlayerBullet") {
		hp_--;
		if(hp_ <= 0) {
			isAlive_ = false;
		}
	}
}
