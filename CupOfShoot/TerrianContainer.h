#pragma once
#include <map>
#include <string>
#include "DxLib.h"

using namespace std;
class TerrianContainer
{
public:
	TerrianContainer();
	~TerrianContainer();

	TerrianContainer(const TerrianContainer&) = delete;
	TerrianContainer& operator=(const TerrianContainer&) = delete; // �R�s�[�֎~

	void Add(string terrianName);
	int GetTerrianHandle(string terrianName);

	void DeleteAll();

	void SetGraphic(int width, int height);

private:
	int width, height;
	map<string, int> terrian;
};

/*
*
* �n�`�R���e�i�\
*
* ���I�ɃX�e�[�W�ǂݍ��݂������ۂɁC�X�e�[�W�f�[�^�t�@�C������
* �X�e�[�W�ƒn�`�`�b�v��ǂݍ��݁C���̒n�`��string�ƈ�v������̂������Ŋ֐��ɂ��
* �ǉ�����B
* �X�e�[�W�I�����ɑS�J��
*
* ������string�`�ȗ��R�F�������������ɑΏ����₷��
* 
* �Ăяo������ClearDrawScreen()�ƒn�`�`��C�摜�̃p�^�[���`�悷��
*
*/

