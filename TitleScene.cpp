#include "TitleScene.h"

void TitleScene::Initialize() {

	input_ = Input::GetInstance();
}

void TitleScene::Update() {

	if (input_->TriggerKey(DIK_P)) {
		sceneNo_ = GAME;
	}

}

void TitleScene::Draw() {

}