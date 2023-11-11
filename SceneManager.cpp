#include "SceneManager.h"
#include "ImGuiManager.h"
#include <Novice.h>
const char kWindowTitle[] = "LE2A_02_アベ_ハルキ";


SceneManager::SceneManager() {
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[GAME] = std::make_unique<PlayScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	

}

SceneManager::~SceneManager() {}

int SceneManager::Run() {

	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		prevSceneNo_ = currentsceneNo_;

		currentsceneNo_ = IScene::sceneNo_;

		if (prevSceneNo_ != currentsceneNo_) {
			sceneArr_[currentsceneNo_]->Initialize();
		}

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		
		//更新処理
		sceneArr_[currentsceneNo_]->Update();//シーンごとの更新

		ImGui::Begin("Scene");

		if (currentsceneNo_ == 0) {
			ImGui::Text("Scene::Title");
			ImGui::Text("State PushKey(P)");
		}

		if (currentsceneNo_ == 1) {
			ImGui::Text("Scene::Game");
		}

		if (currentsceneNo_ == 2) {
			ImGui::Text("Scene::Clear");
			ImGui::Text("Title PushKey(P)");
		}

		ImGui::End();

		//描画処理
		sceneArr_[currentsceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	

	return 0;
}