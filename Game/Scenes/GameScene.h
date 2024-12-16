#pragma once

#include "IScene/IScene.h"

class GameScene final : public IScene {
public:

	GameScene();
	~GameScene();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:


};
