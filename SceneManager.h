#pragma once

#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ClearScene.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	int Run();
private:
	//シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[SCENEMAX];

	int currentsceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン


};