#include "GameScene.h"
#include <cassert>
#include <sstream>
#include <iomanip>


using namespace DirectX;

GameScene::GameScene() {}

GameScene::~GameScene() {
	//3Dオブジェクト解放

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

	Model* player = Model::LoadFromOBJ("maru");
	Model* door = Model::LoadFromOBJ("door");
	
	playerObj->Create();
	doorObj->Create();

	playerObj->SetModel(player);
	doorObj->SetModel(door);

	playerObj->Update();
	doorObj->Update();

}


void GameScene::Update() {
	XMFLOAT3 move = playerObj->GetPosition();
	switch (phase_)
	{
	case GameScene::Phase::TITLE:
		// オブジェクト移動
		if (input->PushKey(DIK_UP))
		{
			move.z += 3;
		}
		else if (input->PushKey(DIK_DOWN))
		{
			move.z -= 3;
		}
		else if (input->PushKey(DIK_RIGHT)) {
			move.x += 3;
		}
		else if (input->PushKey(DIK_LEFT))
		{
			move.x += 3;
		}
		playerObj->SetPosition(move);

		playerObj->Update();

		if (collision->CircleCollision(playerObj->GetPosition(), doorObj->GetPosition(), 2.0f, 3.0f))
		{
			phase_ = Phase::GAMEOVER;
		}
		break;
	case GameScene::Phase::GAMEOVER:
		break;
	default:
		break;
	}
	
	

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
