#pragma once

#include "../IEntity/IEntity.h"


class PlayerBullet : public IEntity {
public:
	
	PlayerBullet();
	~PlayerBullet();
	
	void Initialize() override;
	void Update()     override;
	void Draw()       override;

	/// <summary>
	/// スタートアップ関数
	/// </summary>
	/// <param name="_position"> : 座標       </param>
	/// <param name="_velocity"> : 速度vector </param>
	/// <param name="_speed">    : 速度scaler </param>
	void Startup(const Vector2& _position, const Vector2& _velocity, float _speed);

private:

	Vector2 velocity_;  /// 速度vector
	float   speed_;     /// 速度scaler

	bool    isAlive_;   /// 生存フラグ

public:

	/// <summary>
	/// 生存フラグの取得
	/// </summary>
	/// <returns></returns>
	bool GetIsAlive() const {
		return isAlive_;
	}

};