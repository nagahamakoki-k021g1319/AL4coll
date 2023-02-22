#include "GameScene.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include "Collision.h"

using namespace DirectX;

GameScene::GameScene() {}

GameScene::~GameScene() {
	//3Dオブジェクト解放

	//3Dモデル解放
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input) {
	// nullptrチェック
	assert(dxCommon);
	assert(input);

	this->dxCommon = dxCommon;
	this->input = input;

	//スプライト共通部分の初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);

	//スプライトの初期化

	//スプライトの画像指定
	
	// OBJからモデルデータを読み込み
	
	//3Dオブジェクト生成
	
	// オブジェクトにモデルを紐づける
	
	//3Dオブジェクトの位置を指定
	
	//球の初期値を設定
	
	//平面の初期値を設定
	

}


void GameScene::Update() {
	

}

void GameScene::Draw() {

	//3Dオブジェクト描画前処理
	Object3d::PreDraw(dxCommon->GetCommandList());
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// <summary>

	//3Dオブジェクトの描画
	

	//3Dオブジェクト描画後処理
	Object3d::PostDraw();

}
