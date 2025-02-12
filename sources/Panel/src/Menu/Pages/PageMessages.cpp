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
        "—ŒŒ¡Ÿ≈Õ»ﬂ",
        []()
        {

        }
    };


    static Item *items[] =
    {
        &bMessages,
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
