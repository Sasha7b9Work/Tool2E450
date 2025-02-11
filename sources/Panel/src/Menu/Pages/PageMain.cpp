// 2025/02/11 21:43:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Display/Primitives.h"
#include "Display/Display.h"
#include "Display/Text.h"


using namespace Primitives;


namespace PageMain
{
    static int d = 5;

    static int x1 = 0;
    static int x2 = 330;
    static int x3 = 550;
    static int x4 = 700;
    static int x5 = 900;

    static int y1 = 0;
    static int y2 = 100;
    static int y3 = 230;
    static int y4 = 360;

    static void DrawUppderZone()
    {
        Rect rect(x5 - x1 - d, y2 - y1 - d);

        rect.FillRounded(d, d, 1, Color::YELLOW, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("“Œ Œ¬¿ﬂ «¿Ÿ»“¿ »—“Œ◊Õ» ¿ œ»“¿Õ»ﬂ 24V").Write(rect.X() + d, rect.Y() + d, Color::BLACK);
    }

    static void DrawZoneX()
    {
        Rect rect(x3 - x1 - d, y3 - y2 - d);
        rect.FillRounded(d, d + y2, 1, Color::GRAY_75, Color::BLACK);

        Font::Set(TypeFont::GOSTB28B);

        Text("X:").Write(rect.X() + d, rect.Y() + d, Color::BLACK);

        Text("0.000").Write(rect.X() + 300, rect.Y() + d, Color::BLACK);
    }

    static void DrawZoneY()
    {
        Rect rect(x3 - x1 - d, y4 - y3 - d);
        rect.FillRounded(d, d + y3, 1, Color::GRAY_75, Color::BLACK);

        Font::Set(TypeFont::GOSTB28B);

        Text("Y:").Write(rect.X() + d, rect.Y() + d, Color::BLACK);

        Text("0.000").Write(rect.X() + 300, rect.Y() + d, Color::BLACK);
    }

    static void DrawSubzoneLoad(int x, int y, int width, pchar title, pchar value)
    {
        Rect rect(width, 25);
        rect.FillRounded(x, y, 1, Color::GRAY_75, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text(title).Write(x + d, y - 20, Color::BLACK);
        Text(value).Write(x + d, y + d);
    }


    // »Ì‰ËÍ‡ˆËˇ Ì‡„ÛÁÍË
    static void DrawZoneLoadIndication()
    {
        Rect rect(x2 - x1 - d, Display::PHYSICAL_HEIGHT - y4 - d * 2);
        rect.FillRounded(d, y4 + d, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("»Õƒ» ¿÷»ﬂ Õ¿√–”« »").Write(rect.X() + 30, rect.Y() + d, Color::BLACK);

        pchar titles[3] = { "ÿœ»Õƒ≈À‹", "Œ—‹ X", "Œ—‹ Y" };
        pchar values[3] = { "0 %", "0 %", "0 %" };

        for (int i = 0; i < 3; i++)
        {
            DrawSubzoneLoad(rect.X() + 50, rect.Y() + 65 + i * 60, 150, titles[i], values[i]);
        }
    }

    // ”Ô‡‚ÎÂÌËÂ ÔÓ‰‡˜ÂÈ
    static void DrawZoneFeedManagement()
    {
        Rect rect(x4 - x2 - d, Display::PHYSICAL_HEIGHT - y4 - d * 2);
        rect.FillRounded(d + x2, y4 + d, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("”œ–¿¬À≈Õ»≈ œŒƒ¿◊≈…").Write(rect.X() + 30, rect.Y() + d, Color::BLACK);

        Rect rect_gray(rect.Width() - d * 2, 85);
        rect_gray.FillRounded(rect.X() + d, rect.Y() + 135, 1, Color::GRAY_75, Color::BLACK);
    }

    // œÂ‰Ì‡·Ó ÍÓÓ‰ËÌ‡Ú˚ X
    static void DrawZonePresetX()
    {
        Rect rect(x5 - x3 - d, y3 - y2 - d);
        rect.FillRounded(d + x3, d + y2, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("œ–≈ƒÕ¿¡Œ–  ŒŒ–ƒ»Õ¿“€ X").Write(rect.X() + d, rect.Y() + d, Color::BLACK);

        Rect rect_gray(rect.Width() - d * 4, rect.Height() - 50);
        rect_gray.FillRounded(rect.X() + d * 2, rect.Y() + 40, 1, Color::GRAY_75, Color::BLACK);

        Font::Set(TypeFont::GOSTB28B);

        Text("0.000").Write(rect_gray.X() + d, rect_gray.Y() + d, Color::BLACK);
    }

    // œÂ‰Ì‡·Ó ÍÓÓ‰ËÌ‡Ú˚ Y
    static void DrawZonePresetY()
    {
        Rect rect(x5 - x3 - d, y3 - y2 - d);
        rect.FillRounded(d + x3, d + y3, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("œ–≈ƒÕ¿¡Œ–  ŒŒ–ƒ»Õ¿“€ Y").Write(rect.X() + d, rect.Y() + d, Color::BLACK);

        Rect rect_gray(rect.Width() - d * 4, rect.Height() - 50);
        rect_gray.FillRounded(rect.X() + d * 2, rect.Y() + 40, 1, Color::GRAY_75, Color::BLACK);

        Font::Set(TypeFont::GOSTB28B);

        Text("0.000").Write(rect_gray.X() + d, rect_gray.Y() + d, Color::BLACK);
    }

    // œÂ‰Ì‡·Ó
    static void DrawZonePreset()
    {
        Rect rect(x5 - x4 - d, Display::PHYSICAL_HEIGHT - y4 - d * 2);
        rect.FillRounded(d + x4, y4 + d, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("œ–≈ƒÕ¿¡Œ–").Write(rect.X() + d, rect.Y() + d, Color::BLACK);
    }


    static void Func_Draw()
    {
        DrawUppderZone();

        DrawZoneX();

        DrawZoneY();

        DrawZoneLoadIndication();       // »Ì‰ËÍ‡ˆËˇ Ì‡„ÛÁÍË

        DrawZoneFeedManagement();

        DrawZonePresetX();

        DrawZonePresetY();

        DrawZonePreset();
    }

    static Item *items[] =
    {
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
