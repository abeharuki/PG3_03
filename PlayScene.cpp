#include "PlayScene.h"



void PlayScene::Initialize() {

	input_ = Input::GetInstance();
	player_ = std::make_unique<Player>();
	player_->Initialize();

	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void PlayScene::Update() {

	player_->Update();
	enemy_->Update();

	CheckAllCollision();

	if (enemy_->GetDead()) {
		sceneNo_ = CLEAR;
	}

}

void PlayScene::Draw() {
	player_->Draw();
	enemy_->Draw();
}

void PlayScene::CheckAllCollision(){
	if (input_->TriggerKey(DIK_P)) {
		enemy_->OnCollision();
	}
	// 判定対象AとBの座標
	Vector2 posA, posB;

	// 自弾リスト取得
	const std::list<PlayerBullet*>& playerBullets = player_->GetBullets();

#pragma region 自弾と敵キャラの当たり判定
	
	// 自弾と敵キャラの当たり判定
	for (PlayerBullet* bullet : playerBullets) {
		// 敵座標
		posA = enemy_->GetPos();
		// 自キャラの弾の座標
		posB = bullet->GetWorldPosition();

		// 距離
		if (posA.x + 100 >= posB.x &&
			posB.x+50 >= posA.x &&
			posA.y +100 >= posB.y &&
			posB.y +50>= posA.y) {
			// 敵の衝突時コールバックを呼び出す
			enemy_->OnCollision();
			// 自キャラ弾の衝突時コールバックを呼び出す
			bullet->OnCollision();
		}
	}

	


#pragma endregion

}