#include "Player.h"



void Player::Initialize() {
	
	input_ = Input::GetInstance();
	pos_ = { 1280.0f / 2.0f -100.0f,600.0f };
}

void Player::Update() {

	if (input_->PushKey(DIK_W)) {
		pos_.y -= 10.0f;
	}else if (input_->PushKey(DIK_S)) {
		pos_.y += 10.0f;
	}

	if (input_->PushKey(DIK_A)) {
		pos_.x -= 10.0f;
	}
	else if (input_->PushKey(DIK_D)) {
		pos_.x += 10.0f;
	}

	Attack();

	for (PlayerBullet* bullet : bullets_) {

		bullet->Update();
	}

	bullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

}

void Player::Draw() {
	Novice::DrawBox(int(pos_.x), int(pos_.y), 100, 100, 0.0f, WHITE, kFillModeSolid);
	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw();
	}
}

void Player::Attack() {
	if (input_->PushKey(DIK_SPACE)) {
		Vector2 velocity(0, 10.0f);
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(pos_,velocity);

		bullets_.push_back(newBullet);
	}
}