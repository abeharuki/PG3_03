#include "PlayerBullet.h"

void PlayerBullet::Initialize(const Vector2& pos, const Vector2& velocity){

	pos_ = pos;
	
	velocity_ = velocity;
};


void PlayerBullet::Update() {

	// 時間経過でデス
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}

	pos_.y -= velocity_.y;
	
};


void PlayerBullet::Draw() {
	Novice::DrawBox(int(pos_.x)+25, int(pos_.y), 50,50, 0.0f, BLUE, kFillModeSolid);
};

Vector2 PlayerBullet::GetWorldPosition() {
	// ワールド座標を入れる関数
	Vector2 worldPos;
	// ワールド行列の平行移動成分を取得（ワールド座標）
	worldPos.x = pos_.x;
	worldPos.y = pos_.y;
	
	return worldPos;
}

// 衝突を検出したら呼び出されるコールバック関数
void PlayerBullet::OnCollision() {
	isDead_ = true;
}