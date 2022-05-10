#include "Include.h"

Bubble bubble;

Bubble::Bubble()
{
	bubble_x = target.nowX; //������ x��ġ. ĳ���� ������ ������ ���;��ϴϱ� bubble�� ��ġ�� ����
	bubble_y = target.nowY; //������ y��ġ. ĳ���� ������ ������ ���;��ϴϱ� bubble�� ��ġ�� ����
	sbubble_x = target.nowX; //ĳ������ġ�� ���� �浹 ��ġ�� ����
	sbubble_y = target.nowY;//ĳ������ġ�� ���� �浹 ��ġ�� ����
	m_BubbleCount = 0; // ���� �̹��� ���. �������������� 
	m_BmCount = 0; // ���� �̹��� ���. 
	pos = 0; //���� ����
	m_Life1 = true; // ������ �̹����� �����ϱ����� ���º���
	m_Life2 = true; // �������� �׸������� ���º���
	m_BubbleAniTime = 0; // ���� �ִϸ��̼�
	m_bubble.dx = sbubble_x + 30.0f; //���� �浹��
	m_bubble.dy = sbubble_y + 30.0f;//���� �浹��

	m_bubble.drx = bubble_x;
	m_bubble.dry = bubble_y;
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	Time3 = GetTickCount64();
}

Bubble::~Bubble()
{
}

void Bubble::Init()
{
}

void Bubble::Update()
{
	SetRect(&bub_rc, bubble_x, bubble_y, bubble_x + 41, bubble_y + 41);
	move();


	b_Left = m_bubble.drx;
	b_High = m_bubble.dry;


	if (m_Life2 == true) //���� ���°� true�϶�
	{

		if (pos == 2) //������ A��
		{
			Move(-60.0f, 0); //A�������� 10��ŭ ������ ��� �̵�
		}

		else if (pos == 4) //������ D��
		{
			Move(60.0f, 0); //10��ŭ ������ ��� �̵�
		}



		m_bubble.dx = sbubble_x + 40.0f; //������ �浹����
		m_bubble.dy = sbubble_y + 30.0f; //������ �浹����

		if (GetTickCount() - m_BubbleAniTime > 150)
		{
			if (m_BubbleCount >= 10) //���� �̹����� �������� ��
			{
				m_BubbleCount == 10; //������ ���� �̹������� �ٲ������� 
			}
			else
			{
				m_BubbleCount++; //���� �̹��� ����
			}
		}
	}
	else if (m_Life2 == false)
	{

		if (GetTickCount() - m_BmAniTime > 168)
		{
			if (m_BmCount >= 39)									//���� �̹����� �������϶� 
			{
				m_Life1 = false;									// ������ ���� �̹������� �ٲ��� ����

			}
			else
			{
				m_BmCount++;									// ���� �̹��� ����
			}

			m_BmAniTime = GetTickCount();
		}
	}

	BubblePlayerCol();
}

void Bubble::Draw() {



	if (m_Life2 == false)										// ������ false�϶� ū���� �̹��� Draw
	{
		Gmanager.bbpimg[m_BmCount].Render(bubble_x, bubble_y, 0, 0.6, 0.6);
	}
	else if (m_Life2 == true)									// ������ true�϶� �������� �̹��� Draw
	{
		Gmanager.bbimg[m_BubbleCount].Render(bubble_x + 10, bubble_y + 10, 0, 0.6, 0.6);
		
	}


	
}

BOOL Bubble::BubbleCollision() //����� ����� �浹 �ߴ��� �˷��ִ� �Լ�
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (mapArr[i][j] == 1)
			{
				if (IntersectRect(&temp, &bub_rc, &map.b_rcbubble[i][j]))
				{
					
					return true;
				}
			}
		}
	}

	return false;
}

void Bubble::BubblePlayerCol() //�����̶� �÷��̾�� �浹�Ǵ��� �Լ�
{
	if (bubble_x >= 640) { //�߾���ǥ 640���� �۰ų� ������ ����� Ÿ�� �����浹

		float distance = (float)sqrt((target.target.damgeX - bubble_x) * (target.target.damgeX - bubble_x) +
			(target.target.damgeY - bubble_y) * (target.target.damgeY - bubble_y));
		if (distance < 40) //�浹�Ÿ�
		{

			SetRect(&bub_rc2, b_Left, b_High, b_Left + 100, b_High + 100);
			sound.m_bb->Play(NULL);
			bubble_x += 10; //�浹�� x������ 10��ŭ ������ �о��
			bubblecol = true; //�������� true

		}
	}
	else if (bubble_x <= 1240) 
	{
		float distance = (float)sqrt((target.target.damgeX - bubble_x) * (target.target.damgeX - bubble_x) +
			(target.target.damgeY - bubble_y) * (target.target.damgeY - bubble_y));
		if (distance < 40)
		{

			SetRect(&bub_rc2, b_Left, b_High, b_Left + 100, b_High + 100);
			bubble_x -= 5;

			bubblecol = true;

		}
	}

	//if (bubblecol == true)
	//{
	//	if (GetTickCount64() >= Time3 + 1140)
	//	{
	//		//Gmanager.bbppimg[m_PopCount].Render(bubble_x-26, bubble_y-20, 0, 2.6,2.6);
	//	}

	//}
		
}

void Bubble::move()
{

	if (GetTickCount64() - aniTime2 >= 0)
	{


		if (BubbleCollision() == false)
		{						 //�����浹�� false���(�� �����׻�)

			float Yspeed = 0.9f;
			bubble_y -= Yspeed;

			if (bubble_y <= -50)
			{							 //õ��ʸӿ� ������
				bubble_y = 780; // �ٴڳʸ� 780��ǥ�� �����̵�
			}
		}
		else
		{ //������ ���� �浹��

			float Xspeed = 0.9f;

			if (bubble_x < 640)  //640
			{
				bubble_x += Xspeed;

				if (bubble_x == 300)
				{
					bubble_x = 300;
				}
			}

			if (bubble_x > 640) //640
			{
				bubble_x -= Xspeed;
			}
			/*	else
				{
					bubble_x += Xspeed;
				}*/

		}

		aniTime2 = GetTickCount64();
	}



}


#pragma region Set Get
void Bubble::SetPos(int _p)
{
	pos = _p;
}

int Bubble::GetPos()
{
	return pos;
}

void Bubble::Setm_Life1(bool _L)	// private�� �����ϱ� ���� Set�Լ�
{
	m_Life1 = _L;						// �Լ� ȣ��� ���� ���¿� ���� ����
}

bool Bubble::Getm_Life1()			// private�� ���� �������� ���� Get�Լ� 
{
	return m_Life1;						// �Լ� ȣ��� ���� ���¸� ������
}

void Bubble::Setm_Life2(bool _L)	// private�� �����ϱ� ���� Set�Լ�
{
	m_Life2 = _L;						// �Լ� ȣ��� ���� ���¿� ���� ����
}

bool Bubble::Getm_Life2()			// private�� ���� �������� ���� Get�Լ� 
{
	return m_Life2;						// �Լ� ȣ��� ���� ���¸� ������
}

float Bubble::GetX()				// private�� ���� �������� ���� Get�Լ� 
{
	return bubble_x;						// �Լ� ȣ��� ���� ��ġ���� ������
}

float Bubble::GetY()				// private�� ���� �������� ���� Get�Լ� 
{
	return bubble_y;						// �Լ� ȣ��� ���� ��ġ���� ������
}

float Bubble::GetstX()
{
	return sbubble_x;
}

float Bubble::GetstY()
{
	return sbubble_y;
}

void Bubble::Move(float _x, float _y)
{
	bubble_x += _x;
	bubble_y += _y;
}
#pragma endregion

