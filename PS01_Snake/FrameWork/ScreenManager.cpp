#include "ScreenManager.h"

#include <iostream>

void ScreenManager::OnInit()
{
	CONSOLE_SCREEN_BUFFER_INFO buff;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);

	defaultTextColor = buff.wAttributes & 0xf;	// �ؽ�Ʈ ���� ��������
	defaultBGColor = buff.wAttributes & 0xf0;	// ��� ���� ��������

	CreateBuffer();
}

void ScreenManager::OnRelease()
{
	DeleteBuffer();
}

void ScreenManager::OnDraw(short x, short y, const char* msg)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], pos);

	DWORD dw;
	WriteFile(hBuffer[nScreenIndex], msg, (DWORD)strlen(msg), &dw, NULL);
}

void ScreenManager::OnDrawColor(short x, short y, const char* msg, unsigned short color, unsigned short bgColor)
{
	// Ŀ���� ��ġ�� �����Ѵ�.
	COORD pos = { x,y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], pos);

	// ���� ��ũ���� ��µǴ� ������ ������ �����´�.
	CONSOLE_SCREEN_BUFFER_INFO buff;
	GetConsoleScreenBufferInfo(hBuffer[nScreenIndex], &buff);
	
	// ������ �����Ѵ�.
	if (bgColor > 15)	// ������ �״�� �����Ѵ�.
		SetConsoleTextAttribute(hBuffer[nScreenIndex],(buff.wAttributes & 0xf0) | (color & 0xf));
	else				// ���޹��� ������ ��� ������ �����Ѵ�.
		SetConsoleTextAttribute(hBuffer[nScreenIndex],((bgColor & 0xf) << 4) | (color & 0xf));

	// ����Ѵ�.
	DWORD dw;
	WriteFile(hBuffer[nScreenIndex], msg, (DWORD)strlen(msg), &dw, NULL);

	// ���� �ʱ�ȭ
	SetColor(defaultTextColor, defaultBGColor);
}

void ScreenManager::CreateBuffer()
{
	COORD size = { SCREEN_SIZE_X , SCREEN_SIZE_Y };
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect;
	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = SCREEN_SIZE_X - 1;
	rect.Top = SCREEN_SIZE_Y - 1;

	// Double Buffering
	// Screen Buffer Setting
	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	// sub Screen Buffer Setting
	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);

	nScreenIndex = 0;
}

void ScreenManager::ClearBuffer()
{

	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', SCREEN_SIZE_X * SCREEN_SIZE_Y, Coor, &dw);
}

void ScreenManager::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);

	if (nScreenIndex == 0)
		nScreenIndex = 1;
	else
		nScreenIndex = 0;

	// ��� ������ �� �𸣰ڴ�.
	//nScreenIndex = !nScreenIndex;
}

void ScreenManager::DeleteBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

void ScreenManager::gotoxy(short x, short y)
{
	//COORD pos = { x,y };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	COORD pos = { x,y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], pos);
}

void ScreenManager::SetColor(unsigned short color, unsigned short bgColor)
{
	/*CONSOLE_SCREEN_BUFFER_INFO buff;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgColor & 0xf) << 4) | (color & 0xf));*/

	CONSOLE_SCREEN_BUFFER_INFO buff;
	GetConsoleScreenBufferInfo(hBuffer[nScreenIndex], &buff);

	SetConsoleTextAttribute(hBuffer[nScreenIndex], ((bgColor & 0xf) << 4) | (color & 0xf));
}
