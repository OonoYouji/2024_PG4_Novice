#include "GameScene.h"

/// std
#include <cassert>

/// user
#include "../CustomMath/LoadCSV.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {

	/// multi threadでの読み込みを行う
	std::vector<std::vector<int>> csvData = LoadCSV("./Resources/CSVData.csv");

	
}

void GameScene::Update() {


}

void GameScene::Draw() {

	
}

