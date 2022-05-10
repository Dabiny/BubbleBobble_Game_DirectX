#pragma once
#include "Include.h"

/*�� �迭�� define��� ���Ͽ� ���� ! �� Ŭ���� �ȿ� �־ �����ҰͰ����*/
class Map
{
	/* �� �浹ó��
	1. ����1�� �迭�� ũ�⸦ �������� �浹�� ����
	2. �÷��̾�, ����, ������ ��� �浹�� ���� �ö� �� �ְ� ����
	3. ������ ��� �浹 ����
	4. �߷��� ���Ϳ� ������ �÷��̾ ���� ���־��� ������ �߷¼��� x

	�ʿ��� �Լ���

	1. ������ �Ҹ���
	2. �ʱ�ȭ �Լ�  init
	3. �浹���� �Լ� collision

	�ʿ��� ������

	1. ���xyũ�⸸ŭ�� �浹����
	2.

	*/

	/*

		�⺻ �浿ó��

		= �簢�� �⵿ ���� ó��
		�÷��̾���� �浹 ���� ��ǥ�� (ML, MT) ~ (MR, MB), ź�� �浹 ���� ��ǥ�� (BL, BT) ~ (BR, BB)��� �غ���.
		(ML, MT), (BL, BT)�� ������ �簢���� ���� �� ��ǥ�̰� (MR. MB), (BR, BB)�� �簢���� ������ �Ʒ� ��ǥ�̴�.
		�� ���, �÷��̾�⿡ ź�� �浹 ������ ������ ����.
		* ML < BR && BL < MR && MT < BB && BT < MB

		= ���� �̿��� �浹 ���� ó��
		���� �̿��� �浹 ���� ó���� ������ ����.
		�÷��̾���� �߽���ǥ�� (MX, MY), ź�� �߽���ǥ�� (BX, BY)��� �ϰ�, �÷��̾���� �浹 ���� �ݰ��� MR,
		ź�� �浹 ���� �ݰ��� BR�̶�� ����. �̶� �÷��̾��� ź�� �浹 ������ �Ʒ��� ����.
		* (MX-BX)*(MX-BX) + (MY-BY)*(MY-BY) < (MR+BR)*(MR+BR)

	*/
	//list<Ghost> ghost;
public:
	Map();
	~Map();

	Sprite block; //��ũ���
	Sprite blockRect;
	Sprite backGround; //�޹�������

	int x; //�� x
	int y; //�� y

	
	int m_Stage;

	RECT b_rc[19][32]; //�浹 ��� �簢������� ����

	RECT b_rcbubble[19][32];

	void Init();
	void Update(double frame);
	void Draw();
	BOOL BlockCollision(); //�浹���� ���� �۵��Ǵ��� �����ϴ� �Լ�


	BOOL MonsterCollision();
	
	/*list<Ghost>* GetGhost()
	{
		return &ghost;
	}*/

	
};

extern Map map;
