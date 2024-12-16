#pragma once

#include "IScene/IScene.h"

class TitleScene final : public IScene {
public:

	TitleScene();
	~TitleScene();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:
	int titleSpriteHandle_ = 0;
};