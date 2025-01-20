#pragma once

/// std
#include <memory>
#include <vector>

#include "IScene/IScene.h"

#include "../CustomMath/MultiThreadLoader.h"

class GameScene final : public IScene {
public:

	GameScene();
	~GameScene();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:

	std::unique_ptr<MultiThreadLoader> multiThreadLoader_;

	std::vector<std::vector<int>> csvData_;
	std::vector<unsigned int> colors_;
};
