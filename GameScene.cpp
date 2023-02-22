#include "GameScene.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include "Collision.h"

using namespace DirectX;

GameScene::GameScene() {}

GameScene::~GameScene() {
	//3Dオブジェクト解放
	delete object3d;
	delete object3d_2;

	//3Dモデル解放
	delete model;
	delete model2;
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
	{
		sprite->Initialize(spriteCommon);
		position.x = 400.0f;
		position.y = 0.0f;
		sprite->SetPozition(position);
		sprite->SetSize(XMFLOAT2{ 500.0f,281.0f });

		sprite1->Initialize(spriteCommon);
		sprite1->SetPozition(position1);
		sprite1->SetSize(XMFLOAT2{ 200.0f,112.0f });

		sprite2->Initialize(spriteCommon);
		position2.x = 900.0f;
		sprite2->SetPozition(position2);
		sprite2->SetSize(XMFLOAT2{ 300.0f,170.0f });
	}
	//スプライトの画像指定
	{
		spriteCommon->LoadTexture(0, "eri.png");
		sprite->SetTextureIndex(0);
		spriteCommon->LoadTexture(1, "feri.png");
		sprite1->SetTextureIndex(1);
		spriteCommon->LoadTexture(2, "ynkm.png");
		sprite2->SetTextureIndex(2);
	}
	// OBJからモデルデータを読み込み
	{
		model = Model::LoadFromOBJ("maru");
		model2 = Model::LoadFromOBJ("as2");
		guro = Model::LoadFromOBJ("Gound");
	}
	//3Dオブジェクト生成
	{
		object3d = Object3d::Create();
		object3d_2 = Object3d::Create();
		guround = Object3d::Create();
	}
	// オブジェクトにモデルを紐づける
	{
		object3d->SetModel(model);
		object3d_2->SetModel(model2);
		guround->SetModel(guro);
	}
	//3Dオブジェクトの位置を指定
	{
		object3d->SetScale({ 1,1,1 });
		object3d->SetPosition({0,15,0});
		object3d_2->SetPosition({ -20,0,0 });
	
	}

	//球の初期値を設定
	sphere.center = XMVectorSet(0, 2, 0, 1); //中心点座標
	sphere.radius = 1.0f;//半径

	//平面の初期値を設定
	plane.normal = XMVectorSet(0, 1, 0, 0); //法線ベクトル
	plane.distance = 0.0;
	
}


void GameScene::Update() {
	object3d->Update();
	guround->Update();
	object3d->SetPosition({ sphere.center.m128_f32[0],sphere.center.m128_f32[1],sphere.center.m128_f32[2] });
	// オブジェクト移動
	if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT))
	{
		// 現在の座標を取得
		XMVECTOR moveY = XMVectorSet(0, 0.1f, 0, 0);

		// 移動後の座標を計算
		if (input->PushKey(DIK_UP)) { sphere.center += moveY; }
		else if (input->PushKey(DIK_DOWN)) { sphere.center -= moveY; }

		XMVECTOR moveX = XMVectorSet(0.1f, 0, 0, 0);
		if (input->PushKey(DIK_RIGHT)) { sphere.center += moveX; }
		else if (input->PushKey(DIK_LEFT)) { sphere.center -= moveX; }
	}
	//球と平面の当たり判定
	ischackFlag = 0;
	bool hit = Collision::CheckSphere2Plane(sphere, plane);
	if (hit) {
		ischackFlag = 1;
	}


	object3d_2->Update();

	//当たり判定
	
	XMFLOAT3 a = object3d_2->GetPosition();
	XMFLOAT3 b = object3d->GetPosition();
	float xyz = std::pow(a.x - b.x, 2.0f) + std::pow(a.y - b.y, 2.0f) + std::pow(a.z - b.z, 2.0f);
	float lenR = std::pow(1.0f + 1.0f, 2.0f);
	if (xyz <= lenR) {
		ischackFlag = 1;
	}

	

}

void GameScene::Draw() {
	sprite->Draw();

	if (ischackFlag == 0) {
		sprite1->Draw();
	}
	else {}

	sprite2->Draw();

	//3Dオブジェクト描画前処理
	Object3d::PreDraw(dxCommon->GetCommandList());
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// <summary>

	//3Dオブジェクトの描画
	object3d->Draw();
	object3d_2->Draw();
	guround->Draw();

	//3Dオブジェクト描画後処理
	Object3d::PostDraw();

}
