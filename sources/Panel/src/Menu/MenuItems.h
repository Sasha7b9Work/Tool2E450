// 2023/09/08 21:53:53 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Settings/Settings.h"
#include "Display/Colors.h"


struct TypeMeasure;
class Switch;
struct Control;


class Item
{
    friend class Hint;
public:
    Item() {}

    virtual void Draw() = 0;

    static int Height();

    // ������� ���������
    virtual void DrawMenuItem(int x, int y, int width, bool selected = false) = 0;

    virtual bool IsParameter() const { return false; }

    // ������� ��������� ������� ������/�����
    virtual bool OnEventControl(const Control &) { return false; }

    Color ColorBackground(bool selected);

    static Color ColorDraw(bool selected);

protected:

    int DeltaTextt() const { return 3; }
};


struct TypeButton
{
    enum E
    {
        _1,         // � ���������
        _2,         // �����
        _3,
        Count
    };
};


// ������ ����������
class Button : public Item
{
public:
    Button(TypeButton::E _type, int _x, int _y, pchar text_ru, void (*funcPress)()) :
        Item(), type(_type), text(text_ru), x(_x), y(_y), funcOnPress(funcPress) { }
    virtual void DrawMenuItem(int, int, int, bool) { }
    virtual void Draw() override;
    int X() const
    {
        return x;
    }
    int Y() const
    {
        return y;
    }
    int Width() const;
    int Height() const;
private:
    TypeButton::E type;
    pchar text;
    int x;
    int y;
    void (*funcOnPress)();
};


// ������ ����������
class Choice : public Item
{
public:
    Choice(pchar *_names, void (*funcPress)(), uint8 *_state) :
        Item(), colorBack(Color::MENU_UNSELECT), state(_state), funcOnPress(funcPress)
    {
        names = _names;
    }

    virtual void DrawMenuItem(int x, int y, int width, bool selected = false) override;
    virtual bool OnEventControl(const Control &) override;
    pchar Title() const;
    int Value() const { return (int)*state; }
    void SetColorBackground(const Color &color) { colorBack = color; }
    Color colorBack;        // ���� ������ ����� ������������ ��� � ������ Choice ��� ������ �����
private:
    pchar *names;
    uint8 *state;
    void (*funcOnPress)();
    int NumStates() const;
};


class Page
{
public:
    Page(Item **_items, void (*_funcDraw)()) :
        items(_items), funcDraw(_funcDraw)
    {}

    void Draw();

    void DrawItems() const;

    int NumItems() const;

protected:

    // ��������� �� ������ ��������� ����. ������������� ����.
    Item **items;

    void (*funcDraw)();
};
