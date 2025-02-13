// 2025/02/13 08:49:44 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/InputKeyboard.h"


namespace InputKeyboard
{
    static bool is_active = false;
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
