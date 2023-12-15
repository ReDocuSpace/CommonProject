#include "TitleContent.h"
#include "../../framework.h"

void TitleContent::OnInit()
{
}

void TitleContent::OnRelease()
{
}

void TitleContent::OnUpdate()
{
	if (INPUT->OnKeyDown(VK_RETURN))
		SCENE->ChangeContent((int)_ECONTENT::LOAD);
}

void TitleContent::OnRender()
{
	short startPos = 16;

	SCREEN->OnDraw(startPos, 3, "������  ������  ������  ������  ");
	SCREEN->OnDraw(startPos, 4, "��          ��          ��          ��      ��  ");
	SCREEN->OnDraw(startPos, 5, "��          ��          ��          ��      ��  ");
	SCREEN->OnDraw(startPos, 6, "��          ������  ��  ����  ������  ");
	SCREEN->OnDraw(startPos, 7, "��                  ��  ��  ��  ��  ��          ");
	SCREEN->OnDraw(startPos, 8, "��                  ��  ��      ��  ��          ");
	SCREEN->OnDraw(startPos, 9, "������  ������  ������  ��          ");

	SCREEN->OnDraw(27, 11, "Console Game Pack ver 0.2");


	SCREEN->OnDraw(10, 14, "Ÿ��Ʋ ������ �Դϴ�. ");
	SCREEN->OnDraw(10, 15, "Enter Key�� ������ �ε�Scene���� �Ѿ�ϴ�. ");
}
