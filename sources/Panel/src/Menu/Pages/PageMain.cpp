// 2025/02/11 21:43:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Display/Primitives.h"
#include "Display/Display.h"
#include "Display/Text.h"
#include "Menu/Menu.h"
#include "Device/Messages.h"
#include "Menu/Pages/InputKeyboard.h"


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

    static void DrawWindowMessages()
    {
        Rect rect(x5 - x1 - d, y2 - y1 - d);

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

        Font::Set(TypeFont::GOSTB28B);

        Text("0    ÃÃ/Ã»Õ").Write(rect_gray.X() + 30, rect_gray.Y() + 10, Color::BLACK);
    }

    // œÂ‰Ì‡·Ó ÍÓÓ‰ËÌ‡Ú˚ X
    static void DrawZonePresetX()
    {
        Rect rect(x5 - x3 - d, y3 - y2 - d);
        rect.FillRounded(d + x3, d + y2, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("œ–≈ƒÕ¿¡Œ–  ŒŒ–ƒ»Õ¿“€ X").Write(rect.X() + d, rect.Y() + d, Color::BLACK);

        {
            Rect rect_gray(rect.Width() - d * 4, rect.Height() - 50);
            rect_gray.FillRounded(rect.X() + d * 2, rect.Y() + 40, 1, Color::GRAY_75, Color::BLACK);

            Font::Set(TypeFont::GOSTB28B);

            Text("0.000").Write(rect_gray.X() + d, rect_gray.Y() + d, Color::BLACK);
        }
    }

    // œÂ‰Ì‡·Ó ÍÓÓ‰ËÌ‡Ú˚ Y
    static void DrawZonePresetY()
    {
        Rect rect(x5 - x3 - d, y3 - y2 - d);
        rect.FillRounded(d + x3, d + y3, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text("œ–≈ƒÕ¿¡Œ–  ŒŒ–ƒ»Õ¿“€ Y").Write(rect.X() + d, rect.Y() + d, Color::BLACK);

        {
            Rect rect_gray(rect.Width() - d * 4, rect.Height() - 50);
            rect_gray.FillRounded(rect.X() + d * 2, rect.Y() + 40, 1, Color::GRAY_75, Color::BLACK);

            Font::Set(TypeFont::GOSTB28B);

            Text("0.000").Write(rect_gray.X() + d, rect_gray.Y() + d, Color::BLACK);
        }
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
        DrawWindowMessages();

        DrawZoneX();

        DrawZoneY();

        DrawZoneLoadIndication();       // »Ì‰ËÍ‡ˆËˇ Ì‡„ÛÁÍË

        DrawZoneFeedManagement();

        DrawZonePresetX();              // œÂ‰Ì‡·Ó X

        DrawZonePresetY();              // œÂ‰Ì‡·Ó Y

        DrawZonePreset();
    }

    static const int x_button1 = 905;

    static Button bMessages
    {
        TypeButton::_1,
        x_button1, 5,
        "—ŒŒ¡Ÿ≈Õ»ﬂ",
        []()
        {
            Menu::SetOpenedPage(PageMessages::self);
        }
    };

    static Button bSignals
    {
        TypeButton::_1,
        x_button1, bMessages.Y() + bMessages.Height() + 5,
        "—»√Õ¿À€ œÀ ",
        []()
        {

        }
    };

    static Button bNetwork
    {
        TypeButton::_1,
        x_button1, bSignals.Y() + bSignals.Height() + 5,
        "CET‹ MODBUS",
        []()
        {

        }
    };

    static const int x_button2 = 710;

    static Button bResetX
    {
        TypeButton::_2,
        x_button2, 400,
        "—¡–Œ—  ŒŒ–ƒ»Õ¿“€ X",
        []()
        {

        }
    };

    static Button bResetY
    {
        TypeButton::_2,
        x_button2, bResetX.Y() + bResetX.Height() + d,
        "—¡–Œ—  ŒŒ–ƒ»Õ¿“€ Y",
        []()
        {

        }
    };

    static Button bReady
    {
        TypeButton::_3,
        x_button2, bResetY.Y() + bResetY.Height() + d * 2,
        "√Œ“Œ¬ÕŒ—“‹",
        []()
        {

        }
    };

    static Button bRunning
    {
        TypeButton::_3,
        x_button2, bReady.Y() + bReady.Height() + d,
        "¬€œŒÀÕ≈Õ»≈",
        []()
        {

        }
    };

    static Button bCompletion
    {
        TypeButton::_3,
        x_button2, bRunning.Y() + bRunning.Height() + d,
        "«¿¬≈–ÿ≈Õ»≈",
        []()
        {

        }
    };

    int start_x = 350;
    int start_y = 400;

    static Button bButtons
    {
        TypeButton::_4,
        start_x, start_y,
        " ÕŒœ »",
        []()
        {

        }
    };

    int delta_x = 115;

    static Button bPreset
    {
        TypeButton::_4,
        start_x + delta_x, start_y,
        "œ–≈ƒÕ¿¡Œ–",
        []()
        {

        }
    };

    static Button bShturval
    {
        TypeButton::_4,
        start_x + delta_x * 2, start_y,
        "ÿ“”–¬¿À",
        []()
        {

        }
    };

    int start_x_m = start_x + 55;
    int start_y_m = start_y + 50;

    static Button bMinusX
    {
        TypeButton::_5,
        start_x_m, start_y_m,
        "-X",
        []()
        {

        }
    };

    static Button bPlusX
    {
        TypeButton::_5,
        start_x_m + 160, start_y_m,
        "+X",
        []()
        {

        }
    };

    int start_x_p = start_x_m + 80;
    int start_y_p = start_y_m - 20;

    static Button bPlusY
    {
        TypeButton::_5,
        start_x_p, start_y_p,
        "+Y",
        []()
        {

        }
    };

    static Button bMinusY
    {
        TypeButton::_5,
        start_x_p, start_y_p + 30,
        "-Y",
        []()
        {

        }
    };

    static Item *items[] =
    {
        &bMessages,
        &bSignals,
        &bNetwork,
        &bResetX,
        &bResetY,
        &bReady,
        &bRunning,
        &bCompletion,
        &bButtons,
        &bPreset,
        &bShturval,
        &bMinusX,
        &bPlusX,
        &bPlusY,
        &bMinusY,
        nullptr
    };

    static Page page(items, Func_Draw);

    Page *self = &page;
}
