#pragma once
#include "singleton.h"
#include <Windows.h>

class ScreenManager : public singleton<ScreenManager>
{
#define SCREEN_SIZE_X 80
#define SCREEN_SIZE_Y 50

	unsigned short defaultTextColor = 0;
	unsigned short defaultBGColor = 0;

	HANDLE hBuffer[2];		// ��ũ�� ȭ���� ����ϴ� ���� [2���� �غ��Ѵ�]
	short nScreenIndex;		// 2���� ���۸� ��ȯ�� �� �ִ� index�� �غ��Ѵ�.

public:
	void OnInit();
	void OnRelease();

	// ��� �Լ�
	void OnDraw(short x, short y, const char* msg);
	void OnDrawColor(short x, short y, const char* msg, unsigned short color, unsigned short bgColor = 255);


	// ������۸�
	void CreateBuffer();		// ����(��ũ��)�� �����Ѵ�.
	void ClearBuffer();			// ���۸� �����Ѵ�.
	void FlippingBuffer();		// ������ ��ȯ�Ѵ�.
	void DeleteBuffer();		// ����(��ũ��)�� �����Ѵ�.


	// �н��� �Լ�
	void gotoxy(short x, short y);
	void SetColor(unsigned short color, unsigned short bgColor);
};