#pragma once

/// std
#include <vector>
#include <list>
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

	void CollisionALL();

private:

	class Player* player_ = nullptr;
	class Enemy*  enemy_  = nullptr;

	std::vector<std::unique_ptr<IEntity>> entities_;

	std::list<IEntity*> collisionEntities_;


};
