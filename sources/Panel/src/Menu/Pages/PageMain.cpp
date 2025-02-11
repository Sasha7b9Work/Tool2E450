// 2025/02/11 21:43:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Display/Primitives.h"
#include "Display/Display.h"


using namespace Primitives;


namespace PageMain
{
    static int d = 5;

    static int x1 = 0;
    static int x2 = 350;
    static int x3 = 700;
    static int x4 = 800;
    static int x5 = 900;

    static int y1 = 0;
    static int y2 = 120;
    static int y3 = 240;
    static int y4 = 360;

    static void DrawUppderZone()
    {
        Rect(x5 - x1 - d, y2 - y1 - d).FillRounded(d, d, 1, Color::YELLOW, Color::BLACK);
    }

    static void DrawZoneX()
    {
        Rect(x3 - x1 - d, y3 - y2 - d).FillRounded(d, d + y2, 1, Color::GRAY_75, Color::BLACK);
    }

    static void DrawZoneY()
    {
        Rect(x3 - x1 - d, y4 - y3 - d).FillRounded(d, d + y3, 1, Color::GRAY_75, Color::BLACK);
    }

    // Индикация нагрузки
    static void DrawZoneLoadIndication()
    {
        Rect(x2 - x1 - d, Display::PHYSICAL_HEIGHT - y4 - d * 2).FillRounded(d, y4 + d, 1, Color::WHITE, Color::BLACK);
    }

    // Управление подачей
    static void DrawZoneFeedManagement()
    {
        Rect(x4 - x2 - d, Display::PHYSICAL_HEIGHT - y4 - d * 2).FillRounded(d + x2, y4 + d, 1, Color::WHITE, Color::BLACK);
    }

    static void Func_Draw()
    {
        DrawUppderZone();

        DrawZoneX();

        DrawZoneY();

        DrawZoneLoadIndication();

        DrawZoneFeedManagement();
    }

    static Item *items[] =
    {
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
