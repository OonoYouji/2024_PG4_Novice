#pragma once

/// std
#include <vector>
#include <list>
#include <memory>

#include "IScene/IScene.h"
#include "../Entities/Player/Player.h"

#include "../Command/InputHandler/InputHandler.h"

class GameScene final : public IScene {
public:

	GameScene();
	~GameScene();

	void Initialize() override;
	void Update()     override;
	void Draw()       override;

private:

	std::unique_ptr<Player>       player_;
	std::unique_ptr<InputHandler> inputHandler_;
	ICommand*                     iCommand_;

};
