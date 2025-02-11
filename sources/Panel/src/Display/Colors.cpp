// (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Display/Colors.h"
#include "Settings/Settings.h"


static uint colors[256] =
{

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
