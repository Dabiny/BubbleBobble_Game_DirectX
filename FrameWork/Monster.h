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

class Monster
{
public:
	
	struct Point
	{
		double damgeX, damgeY;
	};

	double m_nowX;
	double m_nowY;

	double m_jumpH;
	double m_nowH;

	double m_speed;

	double tempPositionX;
	double tempPositionY;

	float heat[1];

	DWORD aniTime2;

	Point a;
	Point b;
	Point mon;

	RECT m_rc;
	RECT temp;

	Sprite m_img[4]; //���� �̹���
	int m_Count1;
	DWORD m_AniTime1;

	Sprite m_capture[3]; //ĸ�ĵ� �̹���
	int m_Count2;
	DWORD m_AniTime2;

	Sprite m_die[11]; //�״� �̹���
	int m_Count3;
	DWORD m_AniTime3;

	Sprite m_timeout[6]; //������ �̹���
	int m_Count4;
	DWORD m_AniTime4;

	int m_Count5;
	DWORD m_AniTime5;

	bool isAlive;
	bool isPlayerCol;
	bool isBubbleCol;
	bool isJumping;
	bool isTimeOut;
	bool isWall;
	bool isDir;

	unsigned __int64 Time;
	
public:

	Monster();
	Monster(double _mX, double _mY);
	~Monster();

	void Init();
	void Update();
	void Draw(double _mX, double _mY);

	void Jump();
	void Gravity();
	void Move();
	
	//double Distance(Point& p1, Point& p2);
	BOOL BlockCollision();
	BOOL Wall();
	BOOL BubbleWallCollision();
	BOOL TarMonCollision();

	void SearchMove();
	void CaptureMove();
	//void Reset();
};

extern Monster monster1;
extern Monster monster2;
extern Monster monster3;