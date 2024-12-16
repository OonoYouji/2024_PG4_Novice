#pragma once

#include "IScene/IScene.h"

class ClearScene final : public IScene {
public:
	ClearScene();
	~ClearScene();
	
	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:

	int clearSpriteHandle_ = 0;

};