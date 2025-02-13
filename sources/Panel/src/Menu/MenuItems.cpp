// 2025/02/11 21:50:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/MenuItems.h"
#include "Display/Primitives.h"
#include "Display/Font/Font.h"
#include "Display/Text.h"
#include "Display/Colors.h"


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
    const int width[TypeButton::Count] =
    {
        112, 185, 185, 100, 70, 250, 60
    };

    return width[type];
}

int Button::Height() const
{
    const int height[TypeButton::Count] =
    {
        105, 35, 30, 25, 25, 80, 30
    };

    return height[type];
}


Color Button::ColorFill() const
{
    const Color colors[TypeButton::Count] =
    {
        Color::WHITE, Color::GRAY_75, Color::WHITE, Color::WHITE, Color::WHITE, Color::GRAY_75, Color::WHITE
    };

    Color color = colors[type];

    if (is_pressed)
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
    if (is_active)
    {
        is_pressed = true;
        funcOnPress();
    }
}


void Button::Release()
{
    is_pressed = false;
}


void Button::Draw()
{
    Rect rect(Width(), Height());
    rect.FillRounded(x, y, 1, ColorFill(), Color::BLACK);

    Font::Set(TypeFont::GOSTAU16BOLD);

    Text(text).Write(x + 5, y + 5, Color::BLACK);

    if (funcDraw)
    {
        funcDraw(x, y);
    }
}


void Page::TouchDown(int x, int y)
{
    for(int i = 0; i < NumItems(); i++)
    {
        if(items[i]->UnderPosition(x, y) && items[i]->IsButton())
        {
            Button *button = (Button *)items[i];
            if (button->IsActive())
            {
                button->Press();
                return;
            }
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


void Button::ChangeActive(bool activate)
{
    if(!activate)
    {
        Release();
    }

    is_active = activate;
}
