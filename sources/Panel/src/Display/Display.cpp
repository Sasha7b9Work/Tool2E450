// 2025/02/11 20:31:59 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Display/Display.h"
#include "Display/Font/Font.h"
#include "Menu/Menu.h"


namespace Display
{
    void InitHardware();
}


void Display::Init()
{
    InitHardware();

    Font::Set(TypeFont::GOSTAU16BOLD);

    Font::SetSpacing(2);
}


void Display::Update()
{
    BeginScene();

    Menu::OpenedPage()->Draw();

    EndScene();
}
