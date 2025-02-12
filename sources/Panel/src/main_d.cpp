// (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/HAL/HAL.h"
#include "Hardware/HAL/HAL_PINS.h"
#include "Hardware/Timer.h"
#include "Hardware/Keyboard/Keyboard.h"
#include "Menu/Menu.h"
#include "Device/Messages.h"


int main()
{
    HAL::Init();
    HAL_TIM::DelayMS(500);             // �������� ����� ��� ����, ����� AD9952 ����� ������ ���������� �������������

    Keyboard::Init();

    Menu::Init();

    Messages::Init();

    while (1)
    {
    }
}
