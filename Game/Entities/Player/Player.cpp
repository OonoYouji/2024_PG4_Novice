#include "Player.h"

#include "../../InputManager/InputManager.h"


Player::Player() {}
Player::~Player() {}

void Player::Initialize() {

	inputManager_ = InputManager::GetInstance();

	radius_ = 20.0f;

	position_ = Vector2(640.0f, 360.0f + 200.0f);


}

void Player::Update() {

	velocity_.x = static_cast<float>(inputManager_->PressKey(DIK_D) - inputManager_->PressKey(DIK_A));
	velocity_.y = static_cast<float>(inputManager_->PressKey(DIK_S) - inputManager_->PressKey(DIK_W));

	velocity_ = Normalize(velocity_);

	position_ = position_ + velocity_ * 5.0f;

}

void Player::Draw() {

	Novice::DrawEllipse(
		static_cast<int>(position_.x),
		static_cast<int>(position_.y),
		static_cast<int>(radius_), 
		static_cast<int>(radius_), 
		0, 0xffffffff, kFillModeSolid
	);

}
