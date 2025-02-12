// 2025/02/12 08:58:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Menu/Menu.h"


namespace PageMessages
{
    static void DrawWindowMessages()
    {

    }

    static void Func_Draw()
    {
        DrawWindowMessages();
    }

    static const int x_button1 = 905;

    static Button bReset
    {
        TypeButton::_1,
        x_button1, 5,
        "—¡–Œ—",
        []()
        {

        }
    };

    static Button bMainScreen
    {
        TypeButton::_1,
        x_button1, 490,
        "√À¿¬Õ€… › –¿Õ",
        []()
        {
            Menu::SetOpenedPage(PageMain::self);
        }
    };

    static Item *items[] =
    {
        &bReset,
        &bMainScreen,
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
