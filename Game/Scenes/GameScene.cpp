#include "GameScene.h"

/// std
#include <cassert>

/// engine
#include <Novice.h>

/// user
#include "../CustomMath/LoadCSV.h"

GameScene::GameScene() {}
GameScene::~GameScene() {
	multiThreadLoader_->Finalize();
}

void GameScene::Initialize() {

	/// MultiThreadLoaderの初期化
	multiThreadLoader_ = std::make_unique<MultiThreadLoader>();
	multiThreadLoader_->Initialize();

	auto task = [&]() {
		csvData_ = LoadCSV("./Resources/CSVData.csv");
	};

	multiThreadLoader_->AddTask(task);


	colors_.push_back(0x000000FF);
	colors_.push_back(WHITE);
	colors_.push_back(RED);
	colors_.push_back(GREEN);
	colors_.push_back(BLUE);
	
}

void GameScene::Update() {

}

void GameScene::Draw() {

	for(int i = 0; i < csvData_.size(); ++i) {
		for(int j = 0; j < csvData_[i].size(); ++j) {

			Novice::DrawBox(
				j * 32, i * 32,
				32, 32, 0.0f,
				colors_[csvData_[i][j]], kFillModeSolid
			);

		}
	}
	
}

