// 2025/02/11 19:58:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Menu/MenuItems.h"
#include "Display/Primitives.h"


namespace Menu
{
    void Init();

    void Draw();

    Page *OpenedPage();

    void SetOpenedPage(Page *page);

    // ���� ������ ������� �������� �������, �� true
    bool OpenedPageIsSignal();

    namespace Input
    {
        // ��� ������� ���������� ������� �����
        void Update();

        // ��������� ������� ��������� �����
        void SetFuncUpdate(void (*funcUpdate)());

        // ��� ������� ��������� ��������� �� ���������
        void FuncUpdate();

        void FuncEmptyUpdate();
    };

    extern Primitives::Label labelMode;
};
