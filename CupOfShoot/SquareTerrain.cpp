#include "SquareTerrain.h"

SquareTerrain::SquareTerrain(int maskNum, Vector2 vec1, Vector2 vec2, Vector2 vec3, Vector2 vec4)
	:TerrainUnit(maskNum)
{
	vec.push_back(vec1);
	vec.push_back(vec2);
	vec.push_back(vec3);
	vec.push_back(vec4);
}

void SquareTerrain::Update()
{

}

void SquareTerrain::Draw()
{
	// �O�p�`��2��`��
	// mask��ʂ�terrainStack�ŊǗ����āC�\�߃n���h���̃|�C���^�z���n���̂�����
}
