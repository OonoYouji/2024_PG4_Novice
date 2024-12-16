#include "PlayerBullet.h"

#include <Novice.h>

PlayerBullet::PlayerBullet() {}
PlayerBullet::~PlayerBullet() {}

void PlayerBullet::Initialize() {

	radius_ = 2.0f;

	isAlive_ = true;

	SetTag("PlayerBullet");
}

void PlayerBullet::Update() {

	position_ = position_ + velocity_ * speed_;

	/// 弾が画面外に出たら消す
	if(position_.y < 0.0f - radius_) {
		isAlive_ = false;
	}

}

void PlayerBullet::Draw() {

	Novice::DrawEllipse(
		static_cast<int>(position_.x),
		static_cast<int>(position_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0, 0xffffffff, kFillModeSolid
	);

}

void PlayerBullet::OnCollision(IEntity* _other) {
	if(_other->GetTag() == "Enemy") {
		isAlive_ = false;
	}
}


void PlayerBullet::Startup(const Vector2& _position, const Vector2& _velocity, float _speed) {
	position_ = _position;
	velocity_ = _velocity;
	speed_    = _speed;
}
