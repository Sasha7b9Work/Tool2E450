// 2025/02/11 21:50:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/MenuItems.h"
#include "Display/Primitives.h"
#include "Display/Font/Font.h"
#include "Display/Text.h"


using namespace Primitives;


void Page::Draw()
{
    funcDraw();

    DrawItems();
}


void Page::DrawItems() const
{
    for (int i = 0; i < NumItems(); i++)
    {
        items[i]->Draw();
    }
}


int Page::NumItems() const
{
    int i = 0;
    while (items[i] != nullptr)
    {
        i++;
    }
    return i;
}


int Button::Width() const
{
    if (type == TypeButton::_1)
    {
        return 112;
    }
    else if (type == TypeButton::_2 || type == TypeButton::_3)
    {
        return 185;
    }

    return 100;
}

int Button::Height() const
{
    if (type == TypeButton::_1)
    {
        return 105;
    }
    else if (type == TypeButton::_2)
    {
        return 35;
    }
    else if (type == TypeButton::_3)
    {
        return 30;
    }

    return 100;
}


void Button::Draw()
{
    if (type == TypeButton::_1)
    {
        Rect rect(Width(), Height());
        rect.FillRounded(x, y, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text(text).Write(x + 5, y + 5, Color::BLACK);
    }
    else if(type == TypeButton::_2)
    {
        Rect rect(Width(), Height());
        rect.FillRounded(x, y, 1, Color::GRAY_75, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text(text).Write(x + 5, y + 5, Color::BLACK);
    }
    else if (type == TypeButton::_3)
    {
        Rect rect(Width(), Height());
        rect.FillRounded(x, y, 1, Color::WHITE, Color::BLACK);

        Font::Set(TypeFont::GOSTAU16BOLD);

        Text(text).Write(x + 5, y + 5, Color::BLACK);
    }
}
