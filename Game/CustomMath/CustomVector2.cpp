#include "CustomVector2.h"

Vector2 Normalize(const Vector2& _v) {
	float length = Lenght(_v);

	/// 長さが0だと正規化できないのでそのまま返す
	if(length == 0.0f) {
		return _v;
	}

	return _v / length;
}

float Lenght(const Vector2& _v) {
	return std::sqrt(_v.x * _v.x + _v.y * _v.y);
}
