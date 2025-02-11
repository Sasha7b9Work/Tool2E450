// 2025/02/11 21:43:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Display/Primitives.h"


using namespace Primitives;


namespace PageMain
{
    static void DrawUppderZone()
    {
        Rect(800, 100).FillRounded(10, 10, 1, Color::YELLOW, Color::BLACK);
    }

    static void Func_Draw()
    {
        DrawUppderZone();
    }

    static Item *items[] =
    {
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
