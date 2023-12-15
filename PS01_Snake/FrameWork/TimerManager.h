#pragma once
#include "singleton.h"
#include <map>

class TimerManager : public singleton<TimerManager>
{
private:

	unsigned long long startTime = 0;	// ���α׷��� ���۽�Ų ���۽ð� Ȯ��
	unsigned long long contentTime = 0;	// ������ ���۽�Ų ���۽��� Ȯ��

	std::map<float, unsigned long long> timerMap;	// �ð��� ������ ���� map �ڷᱸ�� ����

public:
	void OnInit();
	void OnRelease();

	// Ÿ�̸� ���� �Լ�
	void AddTimer(float timer);
	void StartContent();

	bool GetTickTimer(float timer);

	float GetProgramTime();
	float GetContentTime();

	

	// ������ �ʿ��� ��Ȳ frame�� ȭ�� ���Ź��
	void SetFrame(float frame);
};

