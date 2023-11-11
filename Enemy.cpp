#include "Enemy.h"



void Enemy::Initialize() {

	input_ = Input::GetInstance();
	pos_ = {0.0f,200.0f };
	speed = 5.0f;
	dead = false;
}

void Enemy::Update() {

	if (pos_.x >= 1180.0f) {
		speed = -5.0f;
	}
	

	if (pos_.x <=0) {
		speed = 5.0f;
	}
	
	pos_.x += speed;


}

void Enemy::Draw() {
	if (!dead) {
		Novice::DrawBox(int(pos_.x), int(pos_.y), 100, 100, 0.0f, RED, kFillModeSolid);
	}
	
}