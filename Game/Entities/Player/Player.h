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


	/// <summary>
	/// 移動
	/// </summary>
	void Move();


	/// <summary>
	/// 弾を撃つ
	/// </summary>
	void Fire();


	/// <summary>
	/// 弾の更新処理
	/// </summary>
	void BulletUpdate();

	/// <summary>
	/// 弾の描画処理
	/// </summary>
	void BulletDraw();

private:

	class InputManager* inputManager_ = nullptr;

	Vector2 velocity_;


	/// bullet parameters
	std::vector<std::unique_ptr<class PlayerBullet>> bullets_;
	int shootCTFrame_;
	int maxShootCTFrame_;


};

