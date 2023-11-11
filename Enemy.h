#pragma once
#include <Input.h>
#include <Novice.h>


class Enemy {
public:
	void Initialize();
	void Update();
	void Draw();

	Vector2 GetPos() { return pos_; }

	void OnCollision() {dead = true;}

	bool GetDead() { return dead; };
private:


	Input* input_;
	Vector2 pos_;

	float speed;
	bool dead;
};