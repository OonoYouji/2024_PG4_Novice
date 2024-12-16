#include <Novice.h>

/// user
#include "Game/Scenes/SceneManager/SceneManager.h"
#include "Game/InputManager/InputManager.h"

const char kWindowTitle[] = "LE2A_04_オオノ_ヨウジ_PG3_04_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	SceneManager* sceneManager = SceneManager::GetInstance();
	InputManager* inputManager = InputManager::GetInstance();

	sceneManager->Initialize();
	inputManager->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		/// ↓更新処理ここから
		inputManager->Update();
		sceneManager->Update();

		
		/// ↓描画処理ここから
		sceneManager->Draw();


		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if(inputManager->TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}


	sceneManager->Finalize();
	inputManager->Finalize();

	sceneManager = nullptr;
	inputManager = nullptr;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
