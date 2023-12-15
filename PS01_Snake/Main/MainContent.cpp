#include "MainContent.h"
#include "../framework.h"

#include "Content/IntroContent.h"
#include "Content/TitleContent.h"
#include "Content/LoadContent.h"
#include "Content/SnakeContent.h"

void MainContent::OnInit()
{
	// _ECONTENT�� ���� Ŭ������ ��������ش�.
	SCENE->AddContent((int)_ECONTENT::INTRO, new IntroContent());
	SCENE->AddContent((int)_ECONTENT::TITLE, new TitleContent());
	SCENE->AddContent((int)_ECONTENT::LOAD, new LoadContent());
	SCENE->AddContent((int)_ECONTENT::SNAKE, new SnakeContent());

	// �������� �����Ѵ�.
	SCENE->ChangeContent((int)_ECONTENT::SNAKE);
}

void MainContent::OnUpdate()
{
	// ������ Ȯ���ϱ� ���� Ű �Է� 
	//if(INPUT->OnKeyDown('Z'))
	//	SCENE->ChangeContent((int)_ECONTENT::INTRO);
	//if(INPUT->OnKeyDown('X'))
	//	SCENE->ChangeContent((int)_ECONTENT::TITLE);


	// ���� �������� �������� ������Ʈ�� �ҷ��´�.
	if (SCENE->GetContent() != nullptr)
		SCENE->GetContent()->OnUpdate();
}

void MainContent::OnRender()
{

	// ���� �������� �������� ������ �ҷ��´�.
	if (SCENE->GetContent() != nullptr)
		SCENE->GetContent()->OnRender();

	// ���
	for (short y = 0; y < GAME_SIZE_Y; y++)
	{
		for (short x = 0; x < GAME_SIZE_X; x++)
		{
			if (x == 0 || y == 0 || x == GAME_SIZE_X - 1 || y == GAME_SIZE_Y - 1)
				SCREEN->OnDrawColor(x * 2, y, "��", GRAY);
		}
	}
}

void MainContent::OnRelease()
{
}
