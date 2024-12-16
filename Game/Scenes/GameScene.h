#pragma once

/// std
#include <vector>
#include <memory>

#include "IScene/IScene.h"
#include "../Entities/IEntity/IEntity.h"

class GameScene final : public IScene {
public:

	GameScene();
	~GameScene();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:

	std::vector<std::unique_ptr<IEntity>> entities_;

};
