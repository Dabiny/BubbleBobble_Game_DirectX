#include "Include.h"

Monster monster1(640.0f, -10.0f);
Monster monster2(640.0f, -100.0f);
Monster monster3(640.0f, -500.0f);

//double tempPosition;

Monster::Monster()
{

}

Monster::Monster(double _mX, double _mY)
{
	m_nowX = _mX;
	m_nowY = _mY;

	m_jumpH = 23.0f;
	m_nowH = m_nowY;

	m_speed = 2.0f;

	tempPositionX = 40;

	Point a = { m_nowX, m_nowY };
	Point b = { target.nowX, target.nowY };

	isAlive = true;
	isPlayerCol = false;
	isBubbleCol = false;
	isJumping = false;
	isWall = false;
	isDir = true; //����
	isTimeOut = false;
	

	//Time = GetTickCount64();
}

Monster::~Monster()
{

}

void Monster::Init()
{
	char FileName[256];

	for (int i = 0; i < 4; i++)
	{
		sprintf_s(FileName, "./resource/Img/monster/%02d.png", i);
		m_img[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(FileName, "./resource/Img/monster/capture/%02d.png", i);
		m_capture[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int i = 0; i < 11; i++)
	{
		sprintf_s(FileName, "./resource/Img/monster/death/%02d.png", i);
		m_die[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int i = 0; i < 6; i++)
	{
		sprintf_s(FileName, "./resource/Img/monster/capture/timeout/%02d.png", i);
		m_timeout[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Monster::Update()
{
	SetRect(&m_rc, m_nowX, m_nowY, m_nowX + 57, m_nowY + 57); // �浹���� ������ֱ�
	//TarMonCollision();

	mon.damgeX = m_nowX + 20.0f;	//��Ʈ�� �浹����		
	mon.damgeY = m_nowY + 20.0f;

	if (isBubbleCol == false)
	{
		if (GetTickCount64() - m_AniTime1 > 100.0f) //��� �̹��� ������
		{
			m_Count1++;
			if (m_Count1 > 1) m_Count1 = 0;
			m_AniTime1 = GetTickCount64();
		}
		//SearchMove();
		Move();
		//Jump();
	}
	
	if (isBubbleCol == true)
	{
		if (GetTickCount64() - m_AniTime2 > 300.0f) //�ʷ� ���� �̹���
		{
			m_Count2++;
			if (m_Count2 > 2) m_Count2 = 0;
			m_AniTime2 = GetTickCount64();
		}

		if (GetTickCount64() - m_AniTime4 > 300.0f) //���� �������� �̹���
		{
			m_Count4++;
			if (m_Count2 > 5) m_Count4 = 0;
			m_AniTime4 = GetTickCount64();
		}

		if (GetTickCount64() - m_AniTime5 > 300.0f) //�ʷ� ���� �̹���
		{
			m_Count5++;
			if (m_Count5 > 10) m_Count5 = 0;
			m_AniTime5 = GetTickCount64();
		}
		//Time = GetTickCount64();
		CaptureMove();
	}

	if (TarMonCollision() == true)
	{
		if (GetTickCount64() - m_AniTime3 > 300.0f) //��� �̹��� ������
		{
			m_Count3++;
			if (m_Count3 > 10) m_Count3 = 0;
			m_AniTime3 = GetTickCount64();
		}
	}

	//���� ��Ÿ� �ȿ� ������ ������������ ����
	for (auto iter = target.GetBubble()->begin(); iter != target.GetBubble()->end(); ++iter) //ù������� ��������� ã���鼭
	{
		for (int i = 0; i < 1; i++)
		{

			heat[i] = (float)sqrt((mon.damgeX - iter->bubble_x) * (mon.damgeX - iter->bubble_x) +	// ����� ������ �浹����
				(mon.damgeY - iter->bubble_y) * (mon.damgeY - iter->bubble_y));

			if (heat[i] < 40)	//�浹�Ÿ�								
			{

				if (iter->Getm_Life2() == true) //�������(������)�� ���̶�� (��������)
				{
				
				}
				iter->Setm_Life2(true);

				if (iter->Getm_Life1() == true)
				{
					isBubbleCol = true;
					sound.m_death->Play(NULL);
					iter = target.GetBubble()->erase(iter);
					//MessageBox(NULL, "����� Ÿ���浹", "asd", 0);
					break;
				}
			}
		}
		break;			//break
	}
}

void Monster::Draw(double _mX, double _mY)
{

	if (isAlive == true && isDir == true && isBubbleCol == false) //���ʷ���
	{
		m_img[m_Count1].Render(_mX , _mY, 0, 0.7, 0.7);
	}

	if (isAlive == true &&  isDir == false && isBubbleCol == false) //�����ʷ���
	{
		//MessageBox(NULL, "00", "��", 0);
		m_img[m_Count1].Render(_mX + 60, _mY, 0, -0.7, 0.7);
	}

	if (isBubbleCol == true)
	{
		m_capture[m_Count2].Render(_mX, _mY, 0, 0.5, 0.5);
	}

	if (isBubbleCol == true && isTimeOut == false)
	{
		m_capture[m_Count2].Render(_mX, _mY, 0, 0.5, 0.5);
	}

	if (TarMonCollision() == true)
	{
		m_die[m_Count3].Render(_mX, _mY, 0, 0.5, 0.5);
	}

	if (isBubbleCol == true && isTimeOut == true )
	{
		m_timeout[m_Count4].Render(_mX, _mY, 0, 0.5, 0.5);
	}
}

void Monster::Gravity()
{
	if (m_nowY >= 800) //650 ����ġ
	{
		m_nowX = 640; //0 ������ �ʱⰪ 0
		m_nowY = -20; // �����ϴܻ��� �ʱⰪ580
		//Reset();
	}
	else
	{
		m_nowY += 3;
	}
}

void Monster::Jump()
{
	if (m_nowY >= 0) {

		if (isJumping == TRUE)
		{
			m_jumpH--;
			m_nowY -= m_jumpH;
			//Reset();

			if (m_jumpH < 0)
			{
				m_jumpH = 23;
				m_nowH = m_nowY;
				isJumping = FALSE;
			}
		}
	}
}

//�⺻ ������ �Լ� 
void Monster::Move()
{
	double m_speed = 3.0f;
	

	if (BlockCollision() == false) //������ �� �׷���Ƽ
	{
		Gravity();
	}
	else if (BlockCollision() == true && Wall() == false && isDir == true) //������ ���� (���̾ƴҶ�)
	{
		m_nowX -= m_speed;
	}
	else if (BlockCollision() == true && Wall() == false && isDir == false)//�������� ���� (���� �ƴҶ�)
	{
		m_nowX += m_speed;
	}
	else if (BlockCollision() == true && Wall() == true && isDir == true) //���ʹ����ε� ���� �������
	{
		m_nowX += m_speed; //�ٽ� ���Ƽ� ��!
		
	}
	else if (BlockCollision() == true && Wall() == true && isDir == false) //�����ʹ����ε� ���� �������
	{
		m_nowX -= m_speed; //�ٽ� ���Ƽ� ��!
	}
	
}


//��ϰ� ���Ͱ� �浹�ߴ��� �˷��ִ� �Լ�
BOOL Monster::BlockCollision()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (mapArr[i][j] == 1)
			{
				if (m_rc.left >= map.b_rc[i][j].left &&
					m_rc.left <= map.b_rc[i][j].right &&
					m_rc.top >= map.b_rc[i][j].top &&
					m_rc.top <= map.b_rc[i][j].bottom)
				{

					//m_nowY++;

					return true;
				}



				if (m_rc.left >= map.b_rc[i][j].left &&
					m_rc.left <= map.b_rc[i][j].right &&
					m_rc.bottom >= map.b_rc[i][j].top &&
					m_rc.bottom <= map.b_rc[i][j].bottom)


				{
					return true;
				}

				if (m_rc.right >= map.b_rc[i][j].left &&
					m_rc.right <= map.b_rc[i][j].right &&
					m_rc.top >= map.b_rc[i][j].top &&
					m_rc.top <= map.b_rc[i][j].bottom)


				{
					return true;
				}

				if (m_rc.right >= map.b_rc[i][j].left &&
					m_rc.right <= map.b_rc[i][j].right &&
					m_rc.bottom >= map.b_rc[i][j].top &&
					m_rc.bottom <= map.b_rc[i][j].bottom)

				{
					return true;
				}
				
				
			}
		}
	}


	return false;
}

//ĸ�ĵ� ����� ����׵θ��� �浹 �ߴ��� �˷��ִ� �Լ�
BOOL Monster::BubbleWallCollision()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (mapArr[i][j] == 1)
			{
				if (IntersectRect(&temp, &map.b_rc[i][0], &m_rc))
				{
					
					return true;
					break;
				}
				else if (IntersectRect(&temp, &map.b_rc[i][31], &m_rc))
				{
					
					return true;
					break;
				}
				else if (IntersectRect(&temp, &map.b_rc[0][j], &m_rc))
				{
					//MessageBox(NULL, "00", "��", 0);
					
					return true;
					break;
				}
				else if (IntersectRect(&temp, &map.b_rc[18][j], &m_rc))
				{
					//MessageBox(NULL, "00", "��", 0);
					
					return true;
					break;
				}
				
			}
			else
			{
				return false;
			}
		}
	}

	
}


//���Ͱ� ��(����׵θ�) �����ƴ��� �˾�ä�� �Լ�
BOOL Monster::Wall()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{

			if (IntersectRect(&temp, &map.b_rc[i][0], &m_rc)) //�� ��� ��ù���׵θ��� �� �ݴ��� ������ ��������
			{
				isDir = false; //��ġ�ٲ�� 
				break; //��� ������Ҵٰ� ȣ��Ǹ� �ȵǴϱ� �극��ũ �ɱ�
				return true; //��Ҵٰ� Ʈ��
			}

			else if (IntersectRect(&temp, &map.b_rc[i][31], &m_rc)) //�� ��� �ǳ����׵θ��� �� �ݴ��� ������ ��������
			{
				isDir = true; //��ġ �ٲ��
				break; //��� ���� ��Ҵٰ� ȣ��Ǹ� �ȵǴϱ� �극��ũ �ɱ�
				return true;
				
			}

		}
	}

	return false;
}

//Ÿ��(����)�� ã�ƴٴϴ� �Լ�  �̿ϼ�
void Monster::SearchMove() 
{
	double m_speed = 3.0f;

	if (target.nowY == m_nowY)
	{
		if (target.nowX <= m_nowX)
		{
			m_nowX -= m_speed;

			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 32; j++)
				{
					if (IntersectRect(&temp, &map.b_rc[18][j], &m_rc) == false)
					{
						Jump();
					}
				}
			}
				
		}
		else if (target.nowX >= m_nowX)
		{
			//MessageBox(NULL, "c", "", 0);
			m_nowX += m_speed;
		}
	}
	if (target.nowY != m_nowY)
	{
		
	}
}

//���Ͱ� ���� ���������� �����̴� �Լ�
void Monster::CaptureMove() //���� ���� (�ð��Ǹ� �������°� ���ϰ���)
{
	double m_speed = 1.0f;

	
	if (BubbleWallCollision() == false) //�����̵� ���Ϳ� �ʺ��浹�� false���
	{

		m_nowY -= m_speed;

		if (m_nowY <= -50)
		{							 //õ��ʸӿ� ������
			m_nowY = 780;			 //�ٴڳʸ� 780��ǥ�� �����̵�
		}

		//isTimeOut = true;
	}

	else if (BubbleWallCollision() == true)
	{

		m_nowX += m_speed;

		if (m_nowX > 640) //640
		{
			m_nowX -= m_speed;
		}

		//isTimeOut = true;

	}

}

//if (BubbleWallCollision() == true)
//{
//	m_nowX += m_speed;
//
//	if (m_nowX > 640) //640
//	{
//		m_nowX -= m_speed;
//	}
//
//	Time = GetTickCount64();
//	isTimeOut = true;
//}
//���Ͱ� Ÿ���̶� �ε����� ���º�ȯ���ִ� �Լ�
BOOL Monster::TarMonCollision() //Ÿ���̶� ���Ͷ� �浹�Ǵ��� 
{
	if (isBubbleCol == true) //���� �¾�����
	{
		if (IntersectRect(&temp, &m_rc, &target.p_rc2) == true) //Ÿ���̶� ����ȸ��Ͷ� �浹�Ǹ�
		{
			isBubbleCol = false; //������� ����
			isAlive = false; //����
			return true;
		}
	}
	
}

//else if (GetTickCount64() >= (Time + 15000))
		//{
		//	MessageBox(NULL, "00", "��", 0);
		//	m_nowY -= m_speed;

		//	if (m_nowY <= -50)
		//	{							 //õ��ʸӿ� ������
		//		m_nowY = 780;			 //�ٴڳʸ� 780��ǥ�� �����̵�
		//	}

		//	isTimeOut = true;
		//	
		//}


//m_nowY -= m_speed;
//
//
//if (m_nowY <= -50)
//{							 //õ��ʸӿ� ������
//	m_nowY = 780;			 //�ٴڳʸ� 780��ǥ�� �����̵�
//}
//
//if (GetTickCount64() >= (Time + 10000)) //5�ʵ�
//{
//	//MessageBox(NULL, "", "", 0);
//
//
//	//if (BubbleWallCollision() == false) //�����̵� ���Ϳ� �ʺ��浹�� false���
//	//{
//
//	//	m_nowY -= m_speed;
//
//	//	if (m_nowY <= -50)
//	//	{							 //õ��ʸӿ� ������
//	//		m_nowY = 780;			 //�ٴڳʸ� 780��ǥ�� �����̵�
//	//	}
//
//	//	isTimeOut = true;
//	//}
//
//	//else if (BubbleWallCollision() == true)
//	//{
//
//	//	m_nowX += m_speed;
//
//	//	if (m_nowX > 640) //640
//	//	{
//	//		m_nowX -= m_speed;
//	//	}
//
//	//	isTimeOut = true;
//	//	
//	//}
//
//	isTimeOut = true;
//	Time = GetTickCount64();
//}
//
//}
//	else
//	{
//	m_nowX += m_speed;
//
//	if (m_nowX > 640) //640
//	{
//		m_nowX -= m_speed;
//	}
//
//	if (GetTickCount64() >= (Time + 10000)) //5�ʵ�
//	{
//		//MessageBox(NULL, "", "", 0);
//
//
//		//if (BubbleWallCollision() == false) //�����̵� ���Ϳ� �ʺ��浹�� false���
//		//{
//
//		//	m_nowY -= m_speed;
//
//		//	if (m_nowY <= -50)
//		//	{							 //õ��ʸӿ� ������
//		//		m_nowY = 780;			 //�ٴڳʸ� 780��ǥ�� �����̵�
//		//	}
//
//		//	isTimeOut = true;
//		//}
//
//		//else if (BubbleWallCollision() == true)
//		//{
//
//		//	m_nowX += m_speed;
//
//		//	if (m_nowX > 640) //640
//		//	{
//		//		m_nowX -= m_speed;
//		//	}
//
//		//	isTimeOut = true;
//		//	
//		//}
//
//		isTimeOut = true;
//		Time = GetTickCount64();
//	}
//	}

//if (BubbleWallCollision() == false && isBubbleCol == true) //�����̵� ���Ϳ� �ʺ��浹�� false��� && isTimeOut�� false���
//{
//	captureTickCount = GetTickCount64();
//
//	if (captureTickCount - startTickCount >= 0) //�ٷ� ������ ����
//	{
//		m_nowY -= m_speed;
//
//		if (m_nowY <= -50)
//		{
//			m_nowY = 780;
//		}
//	}
//	if (captureTickCount - startTickCount >= 5000)
//	{
//		MessageBox(NULL, "00", "5", 0);
//		changeTickCount = GetTickCount64();
//
//		if (startTickCount - changeTickCount >= 20000)
//		{
//			MessageBox(NULL, "00", "20", 0);
//			isTimeOut = true;
//
//			m_nowY -= m_speed;
//
//			if (m_nowY <= -50)
//			{
//				m_nowY = 780;
//			}
//			Time = GetTickCount64();
//		}
//	}
//
//}