#pragma once

/// engine
#include <Novice.h>


/// <summary>
/// 入力の管理クラス
/// </summary>
class InputManager final {
	InputManager() = default;
	~InputManager() = default;

	InputManager(const InputManager&) = delete;
	InputManager(InputManager&&) = delete;
	InputManager& operator= (const InputManager&) = delete;
	InputManager& operator= (InputManager&&) = delete;

public:

	/// <summary>
	/// インスタンスの確保関数
	/// </summary>
	/// <returns> return : instance </returns>
	static InputManager* GetInstance() {
		static InputManager instance;
		return &instance;
	}


	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理関数
	/// </summary>
	void Update();

	/// <summary>
	/// 終了処理関数
	/// </summary>
	void Finalize();


	/// <summary>
	/// 押した瞬間の判定
	/// </summary>
	/// <param name="_key"></param>
	/// <returns></returns>
	bool TriggerKey(int _key) {
		return keys_[_key] && !preKeys_[_key];
	}

	/// <summary>
	/// 押した判定
	/// </summary>
	/// <param name="_key"></param>
	/// <returns></returns>
	bool PressKey(int _key) {
		return keys_[_key];
	}

	/// <summary>
	/// 離した瞬間の判定
	/// </summary>
	/// <param name="_key"></param>
	/// <returns></returns>
	bool ReleaseKey(int _key) {
		return !keys_[_key] && preKeys_[_key];
	}



private:

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

};