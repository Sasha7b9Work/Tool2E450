// 2025/02/12 10:21:40 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once


namespace Messages
{
    void Init();

    void AppendMessage(pchar);

    int GetCountMessages();

    // ���� buffer == nullptr, �� ����������� ������ ������ ����������� ������
    int GetMessage(int, char *buffer);
}
