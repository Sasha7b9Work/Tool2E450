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


// ������ ����������
class Button : public Item
{
public:
    Button(pchar text_ru, void (*funcPress)()) :
        Item(), funcOnPress(funcPress)
    {
        text = text_ru;
    }
    virtual void DrawMenuItem(int x, int y, int width, bool selected = false) override;
    virtual bool OnEventControl(const Control &) override;
    pchar GetTitle() const;
    void SetTitle(pchar);
private:
    pchar text;
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

    bool OnEventControl(const Control &);

    // ���������� ��������� �� ���������� ����� ����
    Item *SelectedItem() { return items[selectedItem]; }

    // ��������� �� ������������ ����� ����������� �����. ���� �� ������, ��� ���������� ������ - ���������������
    void VerifySelectedItem();

    // ���������� �������� ���������� �� ����������� �������
    void DrawParameters() const;

    static const Page *ForCurrentSignal();

    // ��������� ����
    void StartTest() const;

    // ���������� true, ���� ������� �������� - �������� �������
    static bool IsSignal(Page *);

    // ���������� ���������� ������ �� ��������
    int NumItems() const;

protected:

    // ���������� ������ �������� ���� � ������� num
    int WidthItem(int num) const;

    // ��������� �� ������ ��������� ����. ������������� ����.
    Item **items;

    void (*funcDraw)();

private:

    // ����� ���������� �����
    int selectedItem;
};
