#pragma once
#include <Input.h>
#include <Novice.h>
#include <list>
#include "PlayerBullet.h"

class Player {
public:
	void Initialize();
	void Update();
	void Draw();

	void Attack();

	const std::list<PlayerBullet*>& GetBullets()const { return bullets_; }
private:
	

	Input* input_;
	Vector2 pos_;
	
	std::list<PlayerBullet*> bullets_;
};