#pragma once
#include "Include.h"
/* ���� ��ä Ư¡

 1. ÷ ������ ������ ��ġ���� ����
 2. �ð��� ���� �ӵ��� ������
 3. ���� ���� ��� ������
 4. ���� ����, �����Ҷ� �������� ������
 5. ����ĸ�Ļ���
 6. ������ ����ĸ�Ļ��¸� �����ð����� �浹���� ������ �ٽ� ������ Ʈ�簡��

 5. �츮�� ������ ������ ������ ������� ��
 6. �ð������� �Ǹ� (��1��) �ޱ׸����� �ٲ�鼭 �������°� �����ؾ���
 7. ���� �����Ÿ��� (��������) ������ �ٷ� ����ĸ�Ļ��°� �Ǿ� ����ȭ��
 8. ����(������ ����⿡ �������ϱ�)�� ��Ʈ���� �߷¿����� ���������� �����
 9. ����� �浹�ϸ� ������ ���� �� ����

 �� Ư¡������ �����ֻ� ���� �E�� ������ �����ϱ� ��

 */

//typedef struct Gho
//{
//	double  damgeX; //dx
//	double	damgeY; //dy
//};

class Ghost
{
public:

	bool m_GhostLife;
	bool m_GhostDeath;
	bool m_BubbleCapture;
	int m_Heart;
	int m_GhostCount;
	float heat[1];

	double g_nowX;//
	double g_nowY;
	int nowH; //NowH; ĳ���� ���� ����
	int jumpH;//JumpH; ĳ���� ���� ����

public:
	Ghost();
	~Ghost();

	Ghost(double _nowX,double _nowY);

	Sprite Ghoimg[2];

	DWORD m_GhostAniTime;
	DWORD m_GhostAniTime1;

	//Gho gho;
	BOOL g_isJumping;

	
	void Init();
	void Update();
	void Draw(double _nowX, double _nowY);

	void Jump();
	void Gravity();
	void Move(double _x, double _y);
	void GhostCreate(int _pos);

	BOOL GhostCol();
	BOOL GhostPlayerCol();

	RECT Ghost_rc2;
	RECT temp;

	unsigned __int64 Time;
	unsigned __int64 Time2;

};

extern Ghost ghost1;
