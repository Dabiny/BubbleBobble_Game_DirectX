#pragma once
#include "Include.h"

/* ���� ���̸��� �ҹ��ڷ� ����!
	AniTime -> aniTime
	�Լ� �̸��� �빮�ڷ� ����
	Target();
*/

/*
*
	������ ����

1. ���� ��������ġ�� ������
2. �������� �ƴ�
3. Ű�� ������������ �������(�ɾ�� ���� x)

	������ �ɷ�

1. ���� �߻� �����̽� �ѹ��� ���� �ѹ��� ����(��������)
2. ���� �߻� ������ ���Ͱ� ������ ĸ�� x���� �̿��� ��������
3. ĸ���� ������ ��Ʈ����
3. ����Ű �ѹ��� �ѹ�����
4. �������� �ƹ��͵����� ���ϰ� ������ �¿츸 ����
4. ������ ȹ��

*/

typedef struct Tar //������ strcutb
{
	//2d�����̱� ������ xy�� �ϴ� ���°ɷ� ������ �߰��Ұ� ������ �߰��ϻ�
	double  damgeX; //dx
	double	damgeY; //dy
		/*, drx, dry, drz*/	// �������� 
};

class Target //�÷��̾�ξ��� Ÿ��Ŭ���� 
{

	char test[256];
	Tar tg;
	list<Bubble> bubble;

public:
	//�迭���� ��������Ʈ ��������� ������
	// p_count -> ��������Ʈ �Ѱ��ִ� ����, ��������Ʈ�� �߰��Ҷ� 9->10���ڸ� �ٲٱ�
	// anitime -> �ִϸ��̼� Ÿ�� ���� , �ִ�Ÿ���� ������� �س����� �߰��� �����Ÿ� ���ڸ��ٲٰ��ϸ��
	// �ΰ��� �̸� �״�� �� !
#pragma region Sprite
	Sprite line;
	int l_count;
	DWORD linetime;

	Sprite playerR[7]; //Tgimg_right[7] ����������
	int p_Count1;  //����������
	DWORD aniTime1; //����������

	Sprite playerL[7];//Tgimg_left[7] �޿�����
	int p_Count2; //�޿�����
	DWORD aniTime2; //�޿�����

	Sprite player; //Tgimg_stand; ������
	int p_Count0; //������
	int p_Count;
	DWORD aniTime0; //������
	DWORD aniTime0_1;

	Sprite playerJR; //���� ����
	int p_Count3; //��������
	DWORD aniTime3; //��������

	Sprite playerJL[1]; //���� ��
	int p_Count4; //���� ��
	DWORD aniTime4; //���� ��

	Sprite playerSR[2]; //��(����߻�) ����
	int p_Count7; //��(����߻�) ����
	DWORD aniTime7; //��(����߻�) ����

	Sprite playerSL[10]; //��(����) ��
	int p_Count8; //��(����) ��
	DWORD aniTime8; //��(����) ��

	Sprite playerD[6]; //���� //����ȿ���� �����̶� ���� �浹�� �ڿ� ����� ����
	int p_Count9;
	DWORD aniTime9;
 #pragma endregion

	DWORD AniTime2;

	 //�Կ��� �֤����� Ʈ�� �ƴϸ� �޽�
	BOOL isAlive = true; //m_Life; ��������� Ʈ��
	BOOL isMove = false; //target_move; �����̰� ������ Ʈ��
	BOOL isDir = false; //target_move_dir; �ٶ󺸴� ���� false->����,true-> ������
	BOOL isJumping = false; //isJump; ������ �ϴ������� �ϴ����̸� true
	BOOL JumpState; //�̰� ���� ���� �� ���� 

	BOOL isAttack = false; //�����ϴ��� �����ϸ� Ʈ�� ���ϸ� �޽�
	BOOL isAttactDir = false;
	BOOL isMonCol = false; //���Ϳ� �浹�ߴ��� ������ Ʈ�� ���ϸ� �޽�
	BOOL GravityState = true;



	double nowX;//m_W; ĳ���� ���� ��ġ x
	double nowY;//m_H; ĳ���� ���� ��ġ y

	int nowH; //NowH; ĳ���� ���� ����
	int jumpH;//JumpH; ĳ���� ���� ����

	Tar target; //Ÿ����ġ ��Ʈ��Ʈ 

	RECT p_rc; //m_rc; �÷��̾�q���� �浹���� �浹��Ÿ��� �����ϴ°� ����
	RECT p_rc2; //�÷��̾��� �浹ũ��


	Target();
	~Target();

	void Move();
	void Gravity();
	void Init();
	void Update();
	void Draw();
	void Reset();
	void Jump();
	void EraseBubble();
	void TouchEraseBubble();

	///////////////////////
	void BubbleCreate(int _pos);

	list<Bubble>* GetBubble()
	{
		return &bubble;
	}


};


extern Target target;