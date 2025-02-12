// 2023/09/08 20:49:48 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/HAL/HAL.h"
#include "Menu/Menu.h"
#include "Display/Display.h"
#include "Hardware/Keyboard/Keyboard.h"
#include "Device/Messages.h"


void init()
{
    HAL::Init();
    Display::Init();
    Keyboard::Init();
    Menu::Init();
    Messages::Init();
    Messages::AppendMessage("ÒÎÊÎÂÀß ÇÀÙÈÒÀ ÈÑÒÎ×ÍÈÊÀ ÏÈÒÀÍÈß 24V");
    Messages::AppendMessage("ÑÎÎÁÙÅÍÈÅ 2");
}


void update()
{
    Menu::Input::Update();
    Display::Update();
}
