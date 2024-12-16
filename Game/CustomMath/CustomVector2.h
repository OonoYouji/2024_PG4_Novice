#pragma once

#include <cmath>

#include <math/Vector2.h>
using namespace KamataEngine;


inline Vector2 operator+(const Vector2& _v1, const Vector2& _v2) {
	return Vector2{ _v1.x + _v2.x, _v1.y + _v2.y };
}

inline Vector2 operator-(const Vector2& _v1, const Vector2& _v2) {
	return Vector2{ _v1.x - _v2.x, _v1.y - _v2.y };
}

inline Vector2 operator*(const Vector2& _v, float _s) {
	return Vector2{ _v.x * _s, _v.y * _s };
}

inline Vector2 operator*(float _s, const Vector2& _v) {
	return Vector2{ _v.x * _s, _v.y * _s };
}

inline Vector2 operator/(const Vector2& _v, float _s) {
	return Vector2{ _v.x / _s, _v.y / _s };
}



/// <summary>
/// ベクトルの正規化
/// </summary>
/// <param name="_v"></param>
/// <returns></returns>
Vector2 Normalize(const Vector2& _v);


/// <summary>
/// ベクトルの長さ
/// </summary>
/// <param name="_v"></param>
/// <returns></returns>
float Lenght(const Vector2& _v);