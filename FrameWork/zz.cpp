#include "Include.h"

ZZ zz;

ZZ::ZZ()
{


}

ZZ::~ZZ()
{
}

void ZZ::Init()
{
}

void ZZ::Update()
{
	move();
}

void ZZ::Draw() {

}

BOOL ZZ::BubbletoBubbleColiision() {

	if (bubble.bub_rc.left >= bubble.bub_rc.left &&
		bubble.bub_rc.left <= bubble.bub_rc.right &&
		bubble.bub_rc.top >= bubble.bub_rc.top &&
		bubble.bub_rc.top <= bubble.bub_rc.bottom)
	{
		return true;
	}



	if (bubble.bub_rc.left >= bubble.bub_rc.left &&
		bubble.bub_rc.left <= bubble.bub_rc.right &&
		bubble.bub_rc.bottom >= bubble.bub_rc.top &&
		bubble.bub_rc.bottom <= bubble.bub_rc.bottom)


	{
		return true;
	}

	if (bubble.bub_rc.right >= bubble.bub_rc.left &&
		bubble.bub_rc.right <= bubble.bub_rc.right &&
		bubble.bub_rc.top >= bubble.bub_rc.top &&
		bubble.bub_rc.top <= bubble.bub_rc.bottom)


	{
		return true;
	}

	if (bubble.bub_rc.right >= bubble.bub_rc.left &&
		bubble.bub_rc.right <= bubble.bub_rc.right &&
		bubble.bub_rc.bottom >= bubble.bub_rc.top &&
		bubble.bub_rc.bottom <= bubble.bub_rc.bottom)

	{

		return true;
	}

	return false;
}

void move() {

	if (zz.BubbletoBubbleColiision() == true) { //�����浹�� false���(�� �����׻�)
		
		MessageBox(NULL, "", "", 0);
	}
}