// 2025/02/12 08:58:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"


namespace PageMessages
{
    static void Func_Draw()
    {

    }

    static const int x_button1 = 905;

    static Button bMessages
    {
        TypeButton::_1,
        x_button1, 5,
        "���������",
        []()
        {

        }
    };

    static Button bSignals
    {
        TypeButton::_1,
        x_button1, bMessages.Y() + bMessages.Height() + 5,
        "������� ���",
        []()
        {

        }
    };

    static Button bPrev
    {
        TypeButton::_1,
        x_button1, 490,
        "�����",
        []()
        {

        }
    };

    static Button bNext
    {
        TypeButton::_1,
        x_button1, bPrev.Y() - 5 - bPrev.Height(),
        "���Ш�",
        []()
        {

        }
    };

    static Item *items[] =
    {
        &bMessages,
        &bSignals,
        &bPrev,
        &bNext,
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
