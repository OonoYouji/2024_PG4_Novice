#include "Player.h"

#include "../../InputManager/InputManager.h"


Player::Player() {}
Player::~Player() {}

void Player::Initialize() {
	SetTag("Player");

	speed_ = 5.0f;

	size_ = { 12.0f, 12.0f };

	position_ = { 640.0f, 360.0f };

}

void Player::Update() {

	

}

void Player::Draw() {

	/// プレイヤーの描画
	Novice::DrawBox(
		static_cast<int>(position_.x - (size_.x / 0.5f)),
		static_cast<int>(position_.y - (size_.y / 0.5f)),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0, 0xffffffff, kFillModeSolid
	);

}


void Player::MoveLeft() {
	position_.x -= speed_;
}

void Player::MoveRight() {
	position_.x += speed_;
}