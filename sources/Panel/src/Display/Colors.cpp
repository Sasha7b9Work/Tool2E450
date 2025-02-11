// (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Display/Colors.h"
#include "Settings/Settings.h"


static uint colors[256] =
{
    MAKE_COLOR(0x00, 0x00, 0x00),   // FILL;
    MAKE_COLOR(0xA0, 0x80, 0x80),   // BACK;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // MENU_UNSELECT;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // MENU_SELECT;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // RED;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // GREEN;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // BLUE;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // WHITE;
    MAKE_COLOR(0x00, 0x00, 0x00),   // BLACK;
    MAKE_COLOR(0x00, 0x00, 0xFF),   // GRAY;
    MAKE_COLOR(0xFF, 0xFF, 0x00),   // YELLOW;
    MAKE_COLOR(0x00, 0x00, 0xFF),
    MAKE_COLOR(0x00, 0x00, 0xFF)
};


Color Color::FILL(0);
Color Color::BACK(1);
Color Color::MENU_UNSELECT(2);
Color Color::MENU_SELECT(3);
Color Color::RED(4);
Color Color::GREEN(5);
Color Color::BLUE(6);
Color Color::WHITE(7);
Color Color::BLACK(8);
Color Color::GRAY(9);
Color Color::YELLOW(10);


uint &Color::Value() const
{
    return colors[index];
}


uint8 Color::GetRED() const
{
    return (uint8)(Value() >> 16);
}


uint8 Color::GetGREEN() const
{
    return (uint8)(Value() >> 8);
}


uint8 Color::GetBLUE() const
{
    return (uint8)(Value());
}
