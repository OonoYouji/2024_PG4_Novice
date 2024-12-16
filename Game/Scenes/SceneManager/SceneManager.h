#pragma once

/// std
#include <memory>
#include <vector>


/// user
#include "../IScene/IScene.h"

/// <summary>
/// シーンの管理クラス
/// </summary>
class SceneManager final {
	SceneManager() = default;
	~SceneManager() = default;

	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager& operator= (const SceneManager&) = delete;
	SceneManager& operator= (SceneManager&&) = delete;
public:
	
	/// <summary>
	/// インスタンスの確保
	/// </summary>
	/// <returns> return : instance </returns>
	static SceneManager* GetInstance() {
		static SceneManager instance;
		return &instance;
	}



	/// <summary>
	/// 初期化関数
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理関数
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理関数
	/// </summary>
	void Draw();
	
	/// <summary>
	/// 終了処理関数
	/// </summary>
	void Finalize();



	/// <summary>
	/// 次のシーンを設定する
	/// </summary>
	/// <param name="_nextScene"> : 次のシーン </param>
	void SetNextScene(IScene* _nextScene);

private:

	std::unique_ptr<IScene> currentScene_;
	std::unique_ptr<IScene> nextScene_;

};