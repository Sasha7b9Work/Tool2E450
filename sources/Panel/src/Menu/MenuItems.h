// 2023/09/08 21:53:53 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Settings/Settings.h"
#include "Display/Colors.h"


struct Control;


class Item
{
    friend class Hint;
public:
    Item(int _x, int _y) : x(_x), y(_y)
    {
    }

    virtual void Draw() = 0;

    virtual bool IsParameter() const
    {
        return false;
    }

    // Функция обработки нажатия кнопки/ручки
    virtual bool OnEventControl(const Control &)
    {
        return false;
    }

    virtual bool IsButton() const
    {
        return false;
    }

    bool UnderPosition(int x, int y) const;

protected:

    int DeltaTextt() const
    {
        return 3;
    }

    virtual int Width() const = 0;
    virtual int Height() const = 0;

    int x = 0;
    int y = 0;
};


struct TypeButton
{
    enum E
    {
        _1,         // С картинкой
        _2,         // Серая
        _3,
        Count
    };
};


// Общего назначения
class Button : public Item
{
public:

    Button(TypeButton::E _type, int _x, int _y, pchar text_ru, void (*funcPress)()) :
        Item(_x, _y), type(_type), text(text_ru), funcOnPress(funcPress)
    {
    }

    virtual void DrawMenuItem(int, int, int, bool)
    {
    }

    virtual void Draw() override;

    virtual bool IsButton() const override
    {
        return true;
    }

    virtual int Width() const;

    virtual int Height() const;

    int X() const { return x; }

    int Y() const { return y; }

    Color ColorFill() const;

    // Вызывается при нажатии
    void Press();

    // Вызывается при отпускании
    void Release();

private:

    TypeButton::E type;

    pchar text;

    bool pressed = false;

    void (*funcOnPress)();
};


class Page
{
public:
    Page(Item **_items, void (*_funcDraw)()) :
        items(_items), funcDraw(_funcDraw)
    {
    }

    void Draw();

    void DrawItems() const;

    int NumItems() const;

    // Нажали
    void TouchDown(int x, int y);

    // Отпустили
    void TouchUp(int x, int y);

    void OnEventPage();

protected:

    // Указатель на массив элементов меню. Заканчивается нулём.
    Item **items;

    void (*funcDraw)();
};
