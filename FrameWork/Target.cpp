#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"


Target target;


Target::Target()
{
	nowX = 200; //����ĳ��X��ġ
	nowY = 580; //����ĳ�� y��ġ
	target.damgeX = 220; //�������� (struct tar target) �� x��ġ
	target.damgeY = 600; //�������� (strcut tar target) �� y��ġ

	nowH = nowY; // target.m_H
	jumpH = 23; //���� ���� �ʱ�ȭ
	
}

Target::~Target()
{
}

void Target::Init()
{
	char FileName[256];
	/* ���ʿ����� */
	for (int i = 0; i < 7; i++)
	{
		sprintf_s(FileName, "./resource/Img/taget/left_%02d.png", i + 1);
		playerL[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	}

	/* ������ ������*/
	for (int i = 0; i < 7; i++)
	{
		sprintf_s(FileName, "./resource/Img/taget/right_%02d.png", i + 1);
		playerR[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	}
	/*����*/
	player.Create("./resource/Img/stand/01.png", false, D3DCOLOR_XRGB(0, 0, 0));

	/*����*/
	playerJR.Create("./resource/Img/jump/00.png", false, D3DCOLOR_XRGB(0, 0, 0));

	/*��*/
	for (int i = 0; i < 2; i++)
	{
		sprintf_s(FileName, "./resource/Img/shot/%02d.png", i + 1);
		playerSR[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Target::Update()
{
	SetRect(&p_rc2, nowX, nowY, nowX + 57, nowY + 57);
	Move();
	Jump();
	EraseBubble();
	TouchEraseBubble();
}

void Target::EraseBubble() {

	tg.damgeX = nowX + 30.0f; //ĳ���� �浹��
	tg.damgeY = nowY + 30.0f;


	if (GetBubble()->size() != 0) //������ �����Ұ��
	{
		for (auto iter = GetBubble()->begin(); iter != GetBubble()->end(); ++iter) //ù������� ��������� ������ �ִ��� Ȯ��
		{
			#pragma region Y�����
			//if (iter->GetY() < -1/*iter->GetstY() - 500*/ || iter->GetY() > iter->GetstY() + 500) //������������ �浹���������� �ϴ��� -1�� �ϸ� �ʹ����� ������ ��û����Ѵ�.
			//{

			//	iter->Setm_Life2(false);
			//
			//	if (GetTickCount64() >= iter->Time + 10000) {
			//		iter->Time = GetTickCount64();
			//		GetBubble()->erase(iter);
			//		break;
			//	}
			//}
			#pragma endregion
			if (iter->GetX() < iter->GetstX() - 200 || iter->GetX() > iter->GetstX() + 200 ) //X������ ���� �Ÿ� �̻� �Ѿ��
			{
				iter->Setm_Life2(false);

				if (GetTickCount64() >= iter->Time + 7000) {

					iter->Time = GetTickCount64();
					GetBubble()->erase(iter);
					break;
				}
			}

			if (GetTickCount64() >= iter->Time + 7100) {
				GetBubble()->erase(iter);
				break;
			}
		}
	}
}


void Target::TouchEraseBubble() {

	for (auto iter = GetBubble()->begin(); iter != GetBubble()->end(); ++iter) {
		if (GetTickCount64() >= iter->Time2 + 1200) {
			if (iter->bubblecol == true)
			{

				GetBubble()->erase(iter);
				break;
			}
		}
	}
}



void Target::Draw()
{



#pragma region Stop

	if (isMove == false && isAttack == false && isJumping == false && isDir == true)  //left �������� ����
	{
		player.Render(nowX, nowY, 0, 0.7, 0.7);
	}

	if (isMove == false && isAttack == false && isJumping == false && isDir == false) //right ���������� ���� 
	{
		player.Render(nowX + 60, nowY, 0, -0.7, 0.7);
	}

#pragma endregion

#pragma region move Left Right
	if (isMove == true && isAttack == false && isJumping == false && isDir == true) //���ʿ�����
	{
		playerL[p_Count2].Render(nowX, nowY, 0, 0.7, 0.7);
	}

	if (isMove == true && isAttack == false && isJumping == false && isDir == false) //�����ʿ�����
	{
		playerR[p_Count1].Render(nowX, nowY, 0, 0.7, 0.7);
	}
#pragma endregion 

#pragma region jump Left Right
	if (isAttack == false && isJumping == true && isDir == false) //�������� ������
	{
		playerJR.Render(nowX + 60, nowY, 0, -0.7, 0.7);
	}

	if (isAttack == false && isJumping == true && isDir == true)//�������� ����
	{
		playerJR.Render(nowX, nowY, 0, 0.7, 0.7);
	}

#pragma endregion

#pragma region shot Left Right
	if (isDir == false && isAttack == true && isJumping == false && isMove == true) //�� ������
	{
		playerSR[p_Count7].Render(nowX, nowY, 0, 0.7, 0.7);

	}

	if (isDir == true && isAttack == true && isJumping == false && isMove == true) //�� ����
	{
		playerSR[p_Count7].Render(nowX + 60, nowY, 0, -0.7, 0.7);
	}
#pragma endregion

#pragma region stop shot Left Right 
	if (isDir == false && isAttack == true && isJumping == false && isMove == false) //������ �� ������
	{
		playerSR[p_Count7].Render(nowX, nowY, 0, 0.7, 0.7);
	}

	if (isDir == true && isAttack == true && isJumping == false && isMove == false) //������ �� ����
	{
		playerSR[p_Count7].Render(nowX + 60, nowY, 0, -0.7, 0.7);
	}

#pragma endregion

#pragma region stop shot jump Left right 

	if (isDir == false && isAttack == true && isJumping == true && isMove == false) //������ �� ���� ������
	{
		playerSR[p_Count7].Render(nowX, nowY, 0, 0.7, 0.7);
	}

	if (isDir == true && isAttack == true && isJumping == true && isMove == false) //������ �� ���� ����
	{
		playerSR[p_Count7].Render(nowX + 60, nowY, 0, -0.7, 0.7);
	}

	if (isDir == false && isAttack == true && isJumping == true && isMove == true) //���鼭 �� ���� ������ 
	{
		playerSR[p_Count7].Render(nowX, nowY, 0, 0.7, 0.7);
	}

	if (isDir == true && isAttack == true && isJumping == true && isMove == true) //���鼭 �� ���� ���� 
	{
		playerSR[p_Count7].Render(nowX + 60, nowY, 0, -0.7, 0.7);
	}

#pragma endregion


	if (Gmanager.m_Collision == true)
	{
		SetRect(&p_rc, target.damgeX, target.damgeY, target.damgeX + 140, target.damgeY + 160);
		dv_font.Fonts->DrawTextA(NULL, "C", -1, &p_rc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));
	}

	if ( ghost1.GhostPlayerCol() == true )
	{
		dv_font.Fonts->DrawTextA(NULL, "D", -1, &p_rc2, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));
	}


	itoa(GetBubble()->size(), test, 10); //����ȭ�鿡 �����̳� �뷮ǥ��
	dv_font.DrawString(test, 0, 0);

}


void Target::BubbleCreate(int _pos)
{

	bubble.push_front(Bubble()); //�Լ��� ȣ���ϸ� ���� �����̳ʿ� ������ �����Ѵ�
	auto iter = GetBubble()->begin(); //ù��° ����
	iter->SetPos(_pos); //���Ⱚ�� �ִ´�

	if (GetBubble()->size() >= 11) //�����̳� �� 15�� ����
	{
		bubble.resize(10); //15���� �Ѿ�� ����
	}
}

void Target::Reset()
{
	target.damgeX = nowX + 20;
	target.damgeY = nowY + 20;
}

void Target::Jump()
{
	if (nowY >= 0) {

		if (isJumping == TRUE)
		{
			jumpH--;
			nowY -= jumpH;
			Reset();

			if (jumpH < 0)
			{
				jumpH = 23;
				nowH = nowY;
				isJumping = FALSE;
			}
		}
		playerJR.Render(nowX, nowY, 0, 0.7, 0.7);
	}
}


void Target::Gravity()
{
	if (target.damgeY >= 800) //650 ����ġ
	{
			nowX = 640; //0 ������ �ʱⰪ 0
			nowY = -20; // �����ϴܻ��� �ʱⰪ580
			Reset();
	}
	else
	{
		nowY += 6;
		target.damgeY += 6;
	}
}

void Target::Move()
{

	if (map.BlockCollision() == false) //������ �� �׷���Ƽ
	{
		Gravity();

	}
	else
	{
		if (GetTickCount64() - aniTime7 > 100) //��
		{
			p_Count7++;
			if (p_Count7 > 1) p_Count7 = 0;
			aniTime7 = GetTickCount64();
		}
		if (GetTickCount64() - aniTime2 > 100) //������ ��
		{
			p_Count2++;
			if (p_Count2 > 6) p_Count2 = 0;
			aniTime2 = GetTickCount64();
		}
		if (GetTickCount64() - aniTime1 > 100) //������ ����
		{
			p_Count1++;
			if (p_Count1 > 6) p_Count1 = 0;
			aniTime1 = GetTickCount64();
		}

	}
}

