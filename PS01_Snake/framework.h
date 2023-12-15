#pragma once

// �������� Ȱ��Ǵ� ���
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>

// �̱������� ���۵� ���
#include "FrameWork/ScreenManager.h"
#include "FrameWork/TimerManager.h"
#include "FrameWork/InputManager.h"
#include "FrameWork/SceneManager.h"

// �̱��� ���� ��ũ��
#define SCREEN ScreenManager::GetSingleton()
#define TIMER TimerManager::GetSingleton()
#define INPUT InputManager::GetSingleton()
#define SCENE SceneManager::GetSingleton()

// ���� ȭ�� ������ ����
// �ػ� 40X25  [������ ��� 80X25]
#define GAME_SIZE_X 40	// �ѱ��� 2Byte ����� 1Byte�̹Ƿ� �������� �� ��� 80���� �����Ѵ�.
#define GAME_SIZE_Y 25	//

// ���� ����
#define BLACK		0
#define DARKBLUE	1
#define DARKGREEN	2
#define DARKSKYBLUE 3
#define DARKRED		4
#define DARKPURPLE	5
#define DARKYELLOW	6
#define GRAY		7
#define DARKGRAY	8
#define BLUE		9
#define GREEN		10
#define SKYBLUE		11
#define RED			12
#define PURPLE		13
#define YELLOW 		14
#define WHITE		15

enum class _ECONTENT {
	INTRO,
	TITLE,
	LOAD,
	SNAKE
};