#pragma once
#include <memory>
#include "IScene.h"
#include <Input.h>
#include <Player.h>
#include "Enemy.h"

class PlayScene :public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

	//当たり判定
	void CheckAllCollision();

private:
	Input* input_;

	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
};