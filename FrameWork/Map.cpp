#include "Include.h"

Map map;


Map::Map()
{
    

}

Map::~Map()
{
}

void Map::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/map1/pink.png");
	block.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/map1/black.png");
	backGround.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));


}

void Map::Update(double frame)
{

}

void Map::Draw()
{

	if (Gmanager.m_GameStart == true)
	{
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if (mapArr[i][j] == 1)
				{
					block.RenderDraw(j * 40, i * 40, 0, 0, 40, 40, 0, 1, 1);
					SetRect(&b_rc[i][j], j * 40, i * 40, j * 40 + 40, i * 40 + 40);
                    
				} else if (mapArr[i][j] == 0)
				{
					backGround.RenderDraw(j * 40, i * 40, 0, 0, 40, 40, 0, 1, 1);
				}
			}
		}

	}


    if (Gmanager.m_GameStart == true)
    {
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if (mapArr[i][j] == 1)
                {
                    SetRect(&b_rcbubble[i][j], j * 40, i * 40, j * 40 + 40, i * 40 + 40);
                }
                else if (mapArr[i][j] == 0)
                {
                  
                }
            }
        }

    }
}

// ����[row][col]�� ���� 1�϶�

//Ÿ��(�÷��̾�)�� �簢�� ��(pl,pb)(pr,pb) �� ��ϻ簢��(bl,bt)(br,bt)���� ������
//�� ��ġ�� ������ ĳ����ġ (���ö��ִ� ���)�� ��
// 
// �̷��� ������������ rect[i][j] �� �浹���� �����ְ�, �÷��̾ �����ϴ����϶� rect�浹 false��ȯ
// �׷����ʰ� �����ϴ����� �ƴҶ�(��������������) rect �浹  true��ȯ 

BOOL Map::BlockCollision() //�÷��̾�� ����� �浹 �ߴ��� �˷��ִ� �Լ�
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (mapArr[i][j] == 1)
            {

                if (target.p_rc2.left >= map.b_rc[i][j].left &&
                    target.p_rc2.left <= map.b_rc[i][j].right &&
                    target.p_rc2.top >= map.b_rc[i][j].top &&
                    target.p_rc2.top <= map.b_rc[i][j].bottom)
                {

                    target.nowY++;
                  
                    return true;
                }
                
                   

                if (target.p_rc2.left >= map.b_rc[i][j].left &&
                    target.p_rc2.left <= map.b_rc[i][j].right &&
                    target.p_rc2.bottom >= map.b_rc[i][j].top &&
                    target.p_rc2.bottom <= map.b_rc[i][j].bottom)


                {
                    
                    return true;
                }

                if (target.p_rc2.right >= map.b_rc[i][j].left &&
                    target.p_rc2.right <= map.b_rc[i][j].right &&
                    target.p_rc2.top >= map.b_rc[i][j].top &&
                    target.p_rc2.top <= map.b_rc[i][j].bottom)

                   
                {
                 
                    return true;
                }

                if (target.p_rc2.right >= map.b_rc[i][j].left &&
                    target.p_rc2.right <= map.b_rc[i][j].right &&
                    target.p_rc2.bottom >= map.b_rc[i][j].top &&
                    target.p_rc2.bottom <= map.b_rc[i][j].bottom)

                {
                    
                    return true;
                }
            }
        }
    }


    return false;
}