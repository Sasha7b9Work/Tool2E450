// 2025/02/11 21:43:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"


namespace PageMain
{
    static Item *items[] =
    {
        nullptr
    };

    static void Func_Draw()
    {

    }

    static Page page(items, Func_Draw);

    Page *self = &page;
}
