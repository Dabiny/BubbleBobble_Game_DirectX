#include "Include.h"

Key key;

Key::Key(void)
{


}

Key::~Key(void)
{
}

void Key::Update()
{
	// �ý��ۿ� ����...GetTickCount/GetTickCount64

 #pragma region ����Ű
	if (KeyDown('1'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			//map.m_Stage = 1;
			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('2'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			//map.m_Stage = 2;
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('3'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision = true;
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('4'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			//monster.Reset();
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('5'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision = true;
			KeyTime = GetTickCount64();
		}

	}
#pragma endregion

	/*-----------------------------------SHOT---------------------------------------*/
	if (KeyDown(VK_SPACE)) //�����̽� ������ ����߻�
	{

		if (GetTickCount64() - KeyTime3 > 20)
		{

			if (Gmanager.m_GameStart == true && target.isAttack == FALSE && target.p_Count7 == 0)
			{
				target.isAttack = TRUE;
				sound.m_Shot->Play(NULL);


				if (target.isAttactDir == true) {

					target.BubbleCreate(2);
				}

				if (target.isAttactDir == false)
				{

					target.BubbleCreate(4);
				}
			}
			KeyTime3 = GetTickCount64();
		}
	} else if (KeyUp(VK_SPACE))
	{
		target.isAttack = false;
	}

	/*-----------------------------------LEFT---------------------------------------*/
	if (KeyDown(VK_LEFT))
	{
		if (GetTickCount64() - KeyTime1 > 10)
		{
			if (target.nowX <= 45) //-60
			{
				target.nowX = target.nowX;
				target.target.damgeX = target.target.damgeX;

				//if (target.nowX == -60)
				//{
				//	target.nowX = 1260; //�������� 1400
				//	target.nowY = 165; //������ܻ��� �ʱⰪ165
				//	//target.m_Target.dx = target.m_W +34; // player�� �� �ݴ��� ��Ÿ������ �浹�ڽ����� ����;��ϹǷ�
				//	//target.m_Target.dy = target.m_H +40;
				//	target.Reset();
				//}
			}
			else if (Gmanager.m_GameStart == true)
			{
				target.nowX -= 5;
				target.target.damgeX -= 5;
				target.isDir = true; //������ �޽�
				target.isMove = true;
				target.isAttactDir = true;

			}


			KeyTime1 = GetTickCount64();
		}

	} else if (KeyUp(VK_LEFT) && target.isMove && target.isDir == true)
	{
		target.isMove = false;
	}


	/*-----------------------------------RIGHT---------------------------------------*/
	if (KeyDown(VK_RIGHT))
	{

		if (GetTickCount64() - KeyTime1 > 10)
		{
			if (target.nowX >= 1180) //1260
			{
				target.nowY = target.nowY;
				target.target.damgeY = target.target.damgeY;

				//if (target.nowX == 1260) //1400
				//{
				//	target.nowX = -60; //0 ������ �ʱⰪ 0
				//	target.nowY = 650; // �����ϴܻ��� �ʱⰪ580
				//	//target.m_Target.dx = target.m_W + 34;
				//	//target.m_Target.dy = target.m_H + 40;
				//	target.Reset();
				//}
			}
			else if (Gmanager.m_GameStart == true)
			{
				target.nowX += 5;
				target.target.damgeX += 5;
				target.isDir = false;
				target.isMove = true;
				target.isAttactDir = false;


			}
			//Target.Tgimg
			KeyTime1 = GetTickCount64();

		}


	} else if (KeyUp(VK_RIGHT) && target.isMove && target.isDir == false)
	{
		target.isMove = false;
	}


	/*-----------------------------------JUMP---------------------------------------*/
	if (KeyDown(VK_UP))
	{
		if (GetTickCount64() - KeyTime4 > 350)
		{
			if (Gmanager.m_GameStart == true)
			{
				target.isJumping = TRUE;
				sound.m_Jump->Play(NULL);

				if (map.BlockCollision() == false) {
					target.isJumping = false;
				}


			}
			KeyTime4 = GetTickCount64();
		}

	}

 #pragma region DownŰ�� �߷����־ �̻��
	//if (KeyDown(VK_DOWN)) 
	//{

	//	if (GetTickCount64() - KeyTime3 > 10)
	//	{

	//		if (target.nowY >= 580) //580
	//		{
	//			target.nowY = target.nowY;
	//			target.target.damgeY = target.target.damgeY;
	//		}
	//		else if (Gmanager.m_GameStart == true)
	//		{
	//			target.nowY += 0;
	//			target.target.damgeY += 0;
	//		}

	//		KeyTime3 = GetTickCount64();
	//	}

	//}

#pragma endregion

 #pragma region ��Ÿ Ű

	if (KeyDown('C'))
	{
		if (GetTickCount64() - KeyTime1 > 200)
		{
			KeyTime1 = GetTickCount64();
		}
	}

	if (KeyDown('N'))
	{

		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('A'))
	{
		if (GetTickCount64() - KeyTime > 300)
		{

			if (Gmanager.m_GameStart == true)
			{
				//target.BubbleCreate(2);

				target.AniTime2 = GetTickCount64();
			}

			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('W'))
	{
		if (GetTickCount64() - KeyTime > 300)
		{

			if (Gmanager.m_GameStart == true)
			{
				//target.BubbleCreate(1);

				target.AniTime2 = GetTickCount64();
			}

			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('E'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('R'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('S'))
	{
		if (GetTickCount64() - KeyTime > 300)
		{

			if (Gmanager.m_GameStart == true)
			{
				//target.BubbleCreate(3);

				target.AniTime2 = GetTickCount64();
			}

			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('D'))
	{
		if (GetTickCount64() - KeyTime > 300)
		{

			if (Gmanager.m_GameStart == true)
			{
				//target.BubbleCreate(4);

				target.AniTime2 = GetTickCount64();
			}

			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown(VK_RETURN))
	{

		if (GetTickCount64() - KeyTime1 > 200)
		{

			KeyTime1 = GetTickCount64();
		}

	}

#pragma endregion

}