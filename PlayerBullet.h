#pragma once
#include "Input.h"
#include <Novice.h>
class PlayerBullet {
public:
	
	void Initialize(const Vector2& pos,const Vector2& velocity);

	
	void Update();

	
	void Draw();

	bool IsDead() const { return isDead_; }

	// ワールド座標を取得
	Vector2 GetWorldPosition();

	// 衝突を検出したら呼び出されるコールバック関数
	void OnCollision();




private:
	Vector2 pos_;
	// 速度
	Vector2 velocity_;

	// 寿命
	static const int32_t kLifeTime = 60 * 5;
	// デスタイマー
	int32_t deathTimer_ = kLifeTime;
	// デスフラグ
	bool isDead_ = false;

};