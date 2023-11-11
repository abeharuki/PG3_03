#include "ClearScene.h"


void ClearScene::Initialize() {

	input_ = Input::GetInstance();
}

void ClearScene::Update() {

	if (input_->TriggerKey(DIK_P)) {
		sceneNo_ = TITLE;
	}

}

void ClearScene::Draw() {

}