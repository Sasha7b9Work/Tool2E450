// 2025/02/12 08:58:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Menu/Menu.h"
#include "Display/Primitives.h"
#include "Display/Font/Font.h"
#include "Device/Messages.h"
#include "Display/Text.h"


using namespace Primitives;


namespace PageMessages
{
    static int d = 5;

    static int x1 = 0;
    static int x5 = 900;

    static void DrawWindowMessages()
    {
        Rect rect(x5 - x1 - d, 590);

        rect.FillRounded(d, d, 1, Color::YELLOW, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        int y = rect.Y() + d;

        for (int i = 0; i < Messages::GetCountMessages(); i++)
        {
            char buffer[256];

            Messages::GetMessage(i, buffer);

            Text(buffer).Write(rect.X() + d, y, Color::BLACK);

            y += 20;

            if (y > rect.Height())
            {
                break;
            }
        }
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
            Messages::Init();
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
