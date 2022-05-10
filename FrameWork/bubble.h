#include "Include.h"

/* ���ͷ�����, �����̳� ���� ����������� ����!
�纹�� �ҽ��� �Ϻμ����־ �ɷ�������!
bubble.h
bubble.cpp
game.cpp
game.h
gamemanager.h
gamemanager.cpp
target.h
target.cpp�� ���õȰ� ����
*/


class Bubble
{
public:
	typedef struct bubble //���߿� ���Ϳ� �浹������ �����ϴ� ��������.. target.damageXó�� �����صδ�, private������������ �Ʒ� get,set�Լ����� �����Ҽ�����
	{
		float dx, dy, dz, drx, dry, drz;
	};

	float bubble_x, bubble_y; //ū���� �̵��� ��ġ 
	int pos; //���� ����.. ���� AWSD ������ ������ ������

	bool m_Life1; //���� ���� Ȯ��1 �ε����� �Ⱥε�����
	bool m_Life2; //���� ���� Ȯ��2
	

	float sbubble_x, sbubble_y; //ĳ������ġ

	Bubble(); //������
	~Bubble(); //�Ҹ���
	bubble m_bubble; //�� private�� ����� ����ü bubble �浹���� ����(m_bubble.dx..�̷���)

	DWORD m_BubbleAniTime; //��������� ���� �ִϸ��̼�
	int m_BubbleCount; //��������Ʈ ī��Ʈ���ִ°�


	DWORD m_BmAniTime; 
	int m_BmCount; //�̰͵� ��������Ʈ ī��Ʈ���ִ°�
	DWORD  aniTime2;

	DWORD m_PopAniTime;
	int m_PopCount;


	BOOL BubbleCollision(); //����� ���浹
	RECT bub_rc; //������ Rect
	RECT bub_rc2;
	RECT temp;

	void BubblePlayerCol();
	double b_Left; //Ÿ�ٰ� ������ �����浹
	double b_High;
	BOOL bubblecol = false; //Ÿ�ٰ� ��������浹�� true

	void Init();
	void Update();
	void Draw();
	void move();
	

	void Move(float _x, float _y); //private ���� ���е� bubble_x, bubble_y�� �����ϴ� �Լ�
	void SetPos(int _p); //���� ���� private ���� ���е� pos�� �����ϴ� �Լ�
	int GetPos();		//���� ���� private ���� ���е� pos�� �����ϴ� �Լ�

	void Setm_Life1(bool _L); // private ���� ���е� �������1�� �����ϴ� �Լ�
	bool Getm_Life1(); // private ���� ���е� �������1�� �����ϴ� �Լ�

	void Setm_Life2(bool _L); // private ���� ���е� �������2�� �����ϴ� �Լ�
	bool Getm_Life2();// private ���� ���е� �������2�� �����ϴ� �Լ�

	float GetX(); //  private ���� ���е� ������ġ���� �����ϴ� �Լ� 
	float GetY();  //  private ���� ���е� ������ġ���� �����ϴ� �Լ� 

	float GetstX(); //private ���� ���е� sbubble_x�浹���� �����ϴ� �Լ� 
	float GetstY();//private ���� ���е� sbubble_y�浹���� �����ϴ� �Լ� 

	unsigned __int64 Time;//���������Ÿ�������� unsigend����. int�� �ƴ������� �ڷ����� ��Ӻ��ϴ� geticktime�� ���������⶧��..
	unsigned __int64 Time2;//���������Ÿ�������� unsigend����
	unsigned __int64 Time3;//��������� pop��������Ʈ������ unsigend����
};

extern Bubble bubble;