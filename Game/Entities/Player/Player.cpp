#include "Player.h"

#include "../../InputManager/InputManager.h"

#include "../PlayerBullet/PlayerBullet.h"


Player::Player() {}
Player::~Player() {}

void Player::Initialize() {
	SetTag("Player");


	inputManager_ = InputManager::GetInstance();

	position_ = Vector2(640.0f, 360.0f + 200.0f);
	radius_   = 20.0f;


	maxShootCTFrame_ = 4;
	shootCTFrame_    = maxShootCTFrame_;

}

void Player::Update() {

	shootCTFrame_--;

	/// 弾を撃つ
	if(inputManager_->PressKey(DIK_SPACE)) {
		if(shootCTFrame_ <= 0.0f) {
			shootCTFrame_ = maxShootCTFrame_;
			Fire();
		}
	}

	/// 移動する
	Move();

	/// 弾の更新処理
	BulletUpdate();

}

void Player::Draw() {

	/// 弾の描画処理
	BulletDraw();

	/// プレイヤーの描画
	Novice::DrawEllipse(
		static_cast<int>(position_.x),
		static_cast<int>(position_.y),
		static_cast<int>(radius_), 
		static_cast<int>(radius_), 
		0, 0xffffffff, kFillModeSolid
	);

}

void Player::Move() {

	velocity_.x = static_cast<float>(inputManager_->PressKey(DIK_D) - inputManager_->PressKey(DIK_A));
	velocity_.y = static_cast<float>(inputManager_->PressKey(DIK_S) - inputManager_->PressKey(DIK_W));

	velocity_ = Normalize(velocity_);
	position_ = position_ + velocity_ * 5.0f;

}

void Player::Fire() {
	PlayerBullet* newBullet = new PlayerBullet();
	newBullet->Initialize();
	newBullet->Startup(GetPosition(), Vector2(0.0f, -1.0f), 5.0f);

	bullets_.push_back(std::unique_ptr<PlayerBullet>(newBullet));
}

void Player::BulletUpdate() {

	for(auto& bullet : bullets_) {
		bullet->Update();
	}
	
	for(auto itr = bullets_.begin(); itr != bullets_.end();) {
		if(!(*itr)->GetIsAlive()) {
			itr = bullets_.erase(itr);
		} else {
			++itr;
		}
	}

}

void Player::BulletDraw() {
	for(auto& bullet : bullets_) {
		bullet->Draw();
	}
}
