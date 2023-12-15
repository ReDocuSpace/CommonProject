#include "Main/MainContent.h"
#include "framework.h"

int main() {

	srand(time(NULL));

	SCREEN->OnInit();
	TIMER->OnInit();
	INPUT->OnInit();
	SCENE->OnInit();

	MainContent* main = new MainContent();
	main->OnInit();

	bool gameState = true;	// ���� ����� ����

	while (gameState)
	{
		SCREEN->ClearBuffer();

		if (INPUT->OnKeyDown(VK_ESCAPE))
		{
			break;
		}

		// Update ����
		main->OnUpdate();

		// Render ����
		main->OnRender();

		SCREEN->FlippingBuffer();

		// 1�ʿ� 60 ������
		TIMER->SetFrame(1000 / 60);
	}
	main->OnRelease();
	delete main;

	SCENE->OnRelease();
	SCENE->ReleaseSingleton();

	INPUT->OnRelease();
	INPUT->ReleaseSingleton();

	TIMER->OnRelease();
	TIMER->ReleaseSingleton();

	SCREEN->OnRelease();
	SCREEN->ReleaseSingleton();


	return 0;
}
