// 2025/02/13 08:49:44 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/InputKeyboard.h"
#include "Display/Display.h"
#include "Display/Primitives.h"
#include "Menu/MenuItems.h"


using namespace Primitives;


namespace InputKeyboard
{
    static bool is_active = false;
    static const int width = 200;
    static const int height = 150;

    static int X();

    static int Y();
}


bool InputKeyboard::IsActive()
{
    return is_active;
}


void InputKeyboard::Activate()
{
    is_active = true;
}


void InputKeyboard::Deactivate()
{
    is_active = false;
}


void InputKeyboard::Draw()
{
    Rect(width, height).FillRounded(X(), Y(), 1, Color::GRAY_75, Color::BLACK);
}


int InputKeyboard::X()
{
    return Display::PHYSICAL_WIDTH / 2 - width / 2;
}


int InputKeyboard::Y()
{
    return Display::PHYSICAL_HEIGHT / 2 - height / 2;
}
