#include "GameScene.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include "Collision.h"

using namespace DirectX;

GameScene::GameScene() {}

GameScene::~GameScene() {
	//3D�I�u�W�F�N�g���

	//3D���f�����
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

	//�X�v���C�g�̏�����

	//�X�v���C�g�̉摜�w��
	
	// OBJ���烂�f���f�[�^��ǂݍ���
	
	//3D�I�u�W�F�N�g����
	
	// �I�u�W�F�N�g�Ƀ��f����R�Â���
	
	//3D�I�u�W�F�N�g�̈ʒu���w��
	
	//���̏����l��ݒ�
	
	//���ʂ̏����l��ݒ�
	

}


void GameScene::Update() {
	

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
