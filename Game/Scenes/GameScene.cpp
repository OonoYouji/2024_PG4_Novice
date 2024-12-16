#include "GameScene.h"

#include <cassert>

#include "ClearScene.h"

#include "../Entities/Player/Player.h"
#include "../Entities/Enemy/Enemy.h"
#include "../Entities/PlayerBullet/PlayerBullet.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {

	entities_.push_back(std::make_unique<Player>());
	entities_.push_back(std::make_unique<Enemy>());

	player_ = dynamic_cast<Player*>(entities_[0].get());
	enemy_  = dynamic_cast<Enemy*>(entities_[1].get());

	/// nullptrチェック
	assert(player_);
	assert(enemy_);


	for(auto& entity : entities_) {
		entity->Initialize();
		collisionEntities_.push_back(entity.get());
	}

}

void GameScene::Update() {
	if(inputManager_->TriggerKey(DIK_RIGHTARROW)) {
		sceneManager_->SetNextScene(new ClearScene());
	}

	collisionEntities_.clear();

	for(auto& entity : entities_) {
		entity->Update();
		collisionEntities_.push_back(entity.get());
	}

	if(player_) {
		for(auto& bullet : player_->GetBullets()) {
			collisionEntities_.push_back(bullet.get());
		}
	}

	CollisionALL();


	if(!enemy_->GetIsAlive()) {
		sceneManager_->SetNextScene(new ClearScene());
	}


}

void GameScene::Draw() {

	Novice::ScreenPrintf(0, 0, "GameScene");


	for(auto& entity : entities_) {
		entity->Draw();
	}
}

void GameScene::CollisionALL() {


	for(auto& entityA : collisionEntities_) {
		for(auto& entityB : collisionEntities_) {

			/// 同じエンティティ同士は判定しない
			if(entityA == entityB) {
				continue;
			}

			Vector2 distance  = entityA->GetPosition() - entityB->GetPosition();
			float   addRadius = entityA->GetRadius() + entityB->GetRadius();

			/// 当たり判定のチェック
			if(Lenght(distance) < addRadius) {
				entityA->OnCollision(entityB);
				entityB->OnCollision(entityA);
			}

		}
	}
}
