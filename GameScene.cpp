#include "GameScene.h"
#include <cassert>
#include <sstream>
#include <iomanip>


using namespace DirectX;

GameScene::GameScene() {}

GameScene::~GameScene() {
	//3D�I�u�W�F�N�g���

}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input) {
	// nullptr�`�F�b�N
	assert(dxCommon);
	assert(input);

	this->dxCommon = dxCommon;
	this->input = input;

	//�X�v���C�g���ʕ����̏�����
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
		// �I�u�W�F�N�g�ړ�
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
	
	//3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw(dxCommon->GetCommandList());
	/// <summary>
	/// ������3D�I�u�W�F�N�g�̕`�揈����ǉ��ł���
	/// <summary>

	//3D�I�u�W�F�N�g�̕`��
	

	//3D�I�u�W�F�N�g�`��㏈��
	Object3d::PostDraw();

}
