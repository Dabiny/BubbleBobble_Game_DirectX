#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	map.Init();
	target.Init();
	monster1.Init();
	monster2.Init();
	monster3.Init();
	ghost1.Init();

	sound.Init();
	Gmanager.Init();
	
	//ghost2.Init();

	// ����Ÿ ���̽�///////////////////
	//sql.Init();
}

void Game::Draw()
{
	map.Draw();
	monster1.Draw(monster1.m_nowX, monster1.m_nowY);
	monster2.Draw(monster2.m_nowX, monster2.m_nowY);
	monster3.Draw(monster3.m_nowX, monster3.m_nowY);
	target.Draw();
	ghost1.Draw(ghost1.g_nowX, ghost1.g_nowY);

	Gmanager.Draw();
	//ghost2.Draw(ghost2.g_nowX, ghost2.g_nowY);

	// ����Ÿ ���̽�///////////////////
	//sql.Draw();

	//���ͷ����͸� �׷������
	if (target.GetBubble()->size() != 0)
	{
		for (auto iter = target.GetBubble()->begin(); iter != target.GetBubble()->end(); ++iter) {

			iter->Draw();
		}
	}
}

// Chap, ������ �Լ� ȣ��
void Game::Update(double frame)
{
	//static int a = 0;
	//if(a == 0) 
	//{
	//	GameTime = GetTickCount();
	//	a = 1;
	//}
	static DWORD a = 0;

	if (GetTickCount64() - a > frame)
	{
		key.Update();
		target.Update();
		ghost1.Update();
		monster1.Update();
		monster2.Update();
		monster3.Update();

		// �� ���� �°�
		map.Update(130);
		Gmanager.Update();
	
		// ����Ÿ ���̽�///////////////////
		// �� ���� �°� (���⼱ �Ⱦ���..������ ���� �ʿ� �Ҷ���.. �׳� �����...)
		//sql.Update(frame+3000);


		//���ͷ����͸� ������Ʈ�������.
		if (target.GetBubble()->size() != 0)
		{
			for (auto iter = target.GetBubble()->begin(); iter != target.GetBubble()->end(); ++iter) 
			{
				iter->Update();
			}
		}

		a = GetTickCount64();
	}


}

void Game::OnMessage(MSG* msg)
{

}