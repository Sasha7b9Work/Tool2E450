// 2023/09/08 20:49:48 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/HAL/HAL.h"
#include "Menu/Menu.h"
#include "Display/Display.h"
#include "Hardware/Keyboard/Keyboard.h"
#include "Device/Messages.h"
#include "Hardware/Timer.h"
#include "Display/Text.h"


void init()
{
    HAL::Init();
    Display::Init();
    Keyboard::Init();
    Menu::Init();
    Messages::Init();
    Messages::AppendMessage("ÒÎÊÎÂÀß ÇÀÙÈÒÀ ÈÑÒÎ×ÍÈÊÀ ÏÈÒÀÍÈß 24V");
    Messages::AppendMessage("ÑÎÎÁÙÅÍÈÅ 1");
}


void update()
{
    static uint prev_time = 0;

    if (TIME_MS > prev_time + 10000)
    {
        prev_time = TIME_MS;

        static int counter = 2;

        Messages::AppendMessage(Text("ÑÎÎÁÙÅÍÈÅ %d", counter++).c_str());
    }

    Menu::Input::Update();
    Display::Update();
}
