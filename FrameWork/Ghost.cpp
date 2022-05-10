//#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"


Ghost ghost1(650.0f, 20.0f);




Ghost::Ghost()
{

	

}

Ghost::Ghost(double _nowX, double _nowY)
{
	g_nowX = _nowX;
	g_nowY = _nowY;

	m_GhostLife = true;

	Time = GetTickCount64();
	Time2 = GetTickCount64();
	
	nowH = g_nowY; // target.m_H
	jumpH = 23; //���� ���� �ʱ�
}

Ghost::~Ghost()
{

}

void Ghost::Init()
{
	char FileName[256];

	for (int i = 0; i < 2; i++)
	{
		sprintf_s (FileName, "./resource/Img/ghost/%02d.png", i);
		Ghoimg[i].Create (FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

}

void Ghost::Update()
{
	SetRect(&Ghost_rc2, g_nowX, g_nowY, g_nowX + 57, g_nowY + 57);
	Move(g_nowX, g_nowY);

	if (GetTickCount64() - m_GhostAniTime1 > 100.0f)
	{
		m_GhostCount++;
		if (m_GhostCount > 1) m_GhostCount = 0;
		m_GhostAniTime1 = GetTickCount64();
	}

}


void Ghost::Draw(double _nowX, double _nowY)
{
	if (Gmanager.m_GameStart == true)
	{
		if (m_GhostLife == true)
		{
			if (g_nowX > 640 )
			{
				Ghoimg[m_GhostCount].Render(g_nowX + 60, g_nowY, 0, -0.7, 0.7);
			}
			else if (g_nowX < 640 || g_nowY )
			{
				Ghoimg[m_GhostCount].Render(g_nowX , g_nowY, 0, 0.7, 0.7);
			}
		}
		
	}
	
}

void Ghost::GhostCreate(int _pos)
{

}

BOOL Ghost::GhostCol() //���̶� �浹�ϴ���
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (mapArr[i][j] == 1)
			{
				if (IntersectRect(&temp, &Ghost_rc2, &map.b_rc[i][j]))
				{
					return true;
				}
			}
		}
	}
}

BOOL Ghost::GhostPlayerCol() //��Ʈ�� �÷��̾�� �浹�ϴ���
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (mapArr[i][j] == 1)
			{
				if (IntersectRect(&temp, &target.p_rc2, &Ghost_rc2))
				{
					target.isAlive = false;
					target.isMonCol = true;
					sound.m_col->Play(NULL);
					
					return true;
				}
			}
		}
	}
}

void Ghost::Jump()
{

	if (g_nowY >= 0) {

		if (g_isJumping == TRUE)
		{
			jumpH--;
			g_nowY -= jumpH;

			if (jumpH < 0)
			{
				jumpH = 23;
				nowH = g_nowY;
				g_isJumping = FALSE;
			}
		}
		/*playerJR.Render(nowX, nowY, 0, 0.7, 0.7);*/
	}

}


void Ghost::Gravity()
{
	////isJumping = false;

	//if (gho.damgeY >= 700) //650 ����ġ
	//{
	//	g_nowY = g_nowY;
	//	gho.damgeY = gho.damgeY;
	//}
	//else
	//{
	//	g_nowY += 6;
	//	gho.damgeY += 6;
	//}
}

void Ghost::Move(double _x, double _y) // ��Ʈ �����̴� �Լ�
{
	static bool arrivedX = true;
	static bool arrivedY = true;

	double stop = 500.0f;

	if (m_GhostLife == true && g_nowX > 640)
	{

		if (g_nowX == 650.0f && arrivedX == true)
		{
			arrivedY = false;
			if (GetTickCount64() >= (Time + 3000)) //5�ʵڿ� ������ ����
			{
				g_nowY += 3.0f; //��ӳ�������

				if (g_nowY > stop) // ���� y��ǥ�� ��ž���� ũ�ٸ� ���� (��ž�� �����)
				{
					g_nowY = stop;
					arrivedY = true;
					Time = GetTickCount64();
				}
			}
		}

		if (g_nowY == stop && arrivedY == true) //y��ǥ�� ��ž���̶� ���ٸ�
		{
			arrivedX = false;
			if (GetTickCount64() >= (Time + 3000)) //9�ʵ�
			{
				g_nowX += 3.0f; // x��ǥ �̵�

				if (g_nowX > stop + 640) //���� x��ǥ�� ��ž+640(�ݰ��󼭿����̱⋚���� 640 �������ε�) ���� ũ�ٸ�
				{
					g_nowX = stop + 640; // �װ��������� ����
					arrivedX = true;
					Time = GetTickCount64();
				}
			}
		}

		if (g_nowX == stop + 640 && arrivedX == true) //����  ����x��ǥ�� stop+640���̶� ���ٸ�
		{
			arrivedY = false;
			if (GetTickCount64() >= (Time + 3000)) //13�ʵ�
			{
				g_nowY -= 5.0f; //�ٽ� �ö�

				if (20 > g_nowY) //���� ����y��ǥ�� 20���� �۾�����
				{
					g_nowY = 20; //20�� �ӹ�������
					arrivedY = true;
					Time = GetTickCount64();
				}
			}
		}

		if (g_nowY == 20 && arrivedY == true) //���� nowY�� 20�̶� ���ٸ�
		{
			arrivedX = false;
			if (GetTickCount64() >= (Time + 3000)) //17�ʵ�
			{
				g_nowX -= 5.0f; //x��ǥ�� �ٽ� �پ��

				if (650 > g_nowX) //x��ǥ�� 650���� �۾����ٸ�
				{
					g_nowX = 650; //����  x��ǥ�� 650���� ����
					arrivedX = true;
					Time = GetTickCount64(); //���⼭ Ÿ�� �ʱ�ȭ ��ƾ�� �������ڸ�
				}
			}
		}
		m_GhostAniTime = GetTickCount64();
	}

	/* ��Ʈ�� 3���� Ÿ���� nowX,nowY �� ��ǥ�� ���� */

}






