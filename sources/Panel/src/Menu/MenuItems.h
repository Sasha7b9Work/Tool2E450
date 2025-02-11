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


class Page : public Item
{
    friend struct Channel;

public:
    Page(Item **_items, void (*_additionalDraw)(), void (*_func_start_test)()) :
        Item(),
        items(_items), additionalDraw(_additionalDraw), func_start_test(_func_start_test), selectedItem(0)
    {}

    virtual void DrawMenuItem(int x, int y, int width, bool selected = false) override;

    virtual bool OnEventControl(const Control &) override;

    // ���������� ��������� �� ���������� ����� ����
    Item *SelectedItem() { return items[selectedItem]; }

    // ��������� �� ������������ ����� ����������� �����. ���� �� ������, ��� ���������� ������ - ���������������
    void VerifySelectedItem();

    // ���������� true, ���� �������� ����� �������������� ������� ���������
    bool IsAddition() const { return additionalDraw != nullptr; }

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

    void (*additionalDraw)();

    void (*func_start_test)();

private:

    // ����� ���������� �����
    int selectedItem;
};


class PageModes : public Page
{
public:
    PageModes(Item **_items) : Page(_items, nullptr, nullptr) {}
};
