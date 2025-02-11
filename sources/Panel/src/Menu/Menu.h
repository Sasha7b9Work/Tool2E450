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

    // Если сейчас открыта страница сигнала, то true
    bool OpenedPageIsSignal();

    namespace Input
    {
        // Эта функция вызывается главном цикле
        void Update();

        // Установка функции обработки ввода
        void SetFuncUpdate(void (*funcUpdate)());

        // Это функция обработки обработки по умолчанию
        void FuncUpdate();

        void FuncEmptyUpdate();
    };

    extern Primitives::Label labelMode;
};
