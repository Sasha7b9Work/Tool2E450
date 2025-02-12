// 2025/02/11 21:50:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/MenuItems.h"
#include "Display/Primitives.h"
#include "Display/Font/Font.h"
#include "Display/Text.h"


using namespace Primitives;


bool Item::UnderPosition(int pos_x, int pos_y) const
{
    if (pos_x < x)
    {
        return false;
    }

    if (pos_y < y)
    {
        return false;
    }

    if (pos_x > x + Width())
    {
        return false;
    }

    if (pos_y > y + Height())
    {
        return false;
    }

    return true;
}


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


Color Button::ColorFill() const
{
    Color color = Color::WHITE;

    if(type == TypeButton::_1)
    {
        color = Color::WHITE;
    }
    else if(type == TypeButton::_2)
    {
        color = Color::GRAY_75;
    }
    else if(type == TypeButton::_3)
    {
        color = Color::WHITE;
    }

    if (pressed)
    {
        uint col_val = color.Value();

        uint8 r = (uint8)(RED_FROM_COLOR(col_val) / 2);
        uint8 g = (uint8)(GREEN_FROM_COLOR(col_val) / 2);
        uint8 b = (uint8)(BLUE_FROM_COLOR(col_val) / 2);

        Color::PRESSED.SetValue(MAKE_COLOR(r, g, b));

        color = Color::PRESSED;
    }

    return color;
}


void Button::Press()
{
    pressed = true;
    funcOnPress();
}


void Button::Release()
{
    pressed = false;
}


void Button::Draw()
{
    Rect rect(Width(), Height());
    rect.FillRounded(x, y, 1, ColorFill(), Color::BLACK);

    Font::Set(TypeFont::GOSTAU16BOLD);

    Text(text).Write(x + 5, y + 5, Color::BLACK);
}


void Page::TouchDown(int x, int y)
{
    for(int i = 0; i < NumItems(); i++)
    {
        if(items[i]->UnderPosition(x, y) && items[i]->IsButton())
        {
            Button *button = (Button *)items[i];
            button->Press();
        }
    }
}


void Page::TouchUp(int x, int y)
{
    for(int i = 0; i < NumItems(); i++)
    {
        if(items[i]->UnderPosition(x, y) && items[i]->IsButton())
        {
            Button *button = (Button *)items[i];
            button->Release();
        }
    }
}


void Page::OnEventPage()
{
    for (int i = 0; i < NumItems(); i++)
    {
        if (items[i]->IsButton())
        {
            Button *button = (Button *)items[i];

            button->Release();
        }
    }
}
