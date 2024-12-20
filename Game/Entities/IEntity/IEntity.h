#pragma once

/// std
#include <string>

#include "../../CustomMath/CustomVector2.h"

/// <summary>
/// 各エンティティのインターフェイスクラス
/// </summary>
class IEntity {
public:
	
	virtual ~IEntity() = default;

	virtual void Initialize() = 0;
	virtual void Update()     = 0;
	virtual void Draw()       = 0;

	virtual void OnCollision(IEntity*) {}

protected:

	std::string tag_ = "none";

	Vector2     position_;
	float       radius_;

public:

	/// <summary>
	/// 位置の設定
	/// </summary>
	/// <param name="_position"></param>
	void SetPosition(const Vector2& _position) {
		position_ = _position;
	}


	/// <summary>
	/// 位置の取得
	/// </summary>
	/// <returns></returns>
	const Vector2& GetPosition() const {
		return position_;
	}


	/// <summary>
	/// 半径の設定
	/// </summary>
	/// <param name="_radius"></param>
	void SetRadius(float _radius) {
		radius_ = _radius;
	}

	/// <summary>
	/// 半径の取得
	/// </summary>
	/// <returns></returns>
	float GetRadius() const {
		return radius_;
	}



	/// <summary>
	/// タグの設定
	/// </summary>
	/// <param name="_tag"></param>
	void SetTag(const std::string& _tag) {
		tag_ = _tag;
	}

	/// <summary>
	/// タグの取得
	/// </summary>
	/// <returns></returns>
	const std::string& GetTag() const {
		return tag_;
	}



};