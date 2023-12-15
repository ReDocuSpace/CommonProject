#include "SceneManager.h"

void SceneManager::OnInit()
{
}

void SceneManager::OnRelease()
{
}

void SceneManager::AddContent(int key, IContent* content)
{
    // Ű�� ��á�� ��� �ʿ� ������ �߰��ϱ�
    if (contentMap.find(key) == contentMap.end())
        contentMap.insert(std::make_pair(key, content));  
}

void SceneManager::ChangeContent(int key)
{
    // ����� �������� ���� ��� ������ Release(����)�� ���ش�.
    if (curContent != nullptr)
        curContent->OnRelease();

    // 
    if (contentMap.find(key) != contentMap.end())
    {
        // ����� �������� �����ϱ�, �ʱ�ȭ�� �����Ѵ�.
        curContent = contentMap[key];
        curContent->OnInit();
    }
}
