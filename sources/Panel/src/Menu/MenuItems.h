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

    // Функция отрисовки
    virtual void DrawMenuItem(int x, int y, int width, bool selected = false) = 0;

    virtual bool IsParameter() const { return false; }

    // Функция обработки нажатия кнопки/ручки
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
        _1,
        Count
    };
};


// Общего назначения
class Button : public Item
{
public:
    Button(TypeButton::E _type, int _x, int _y, pchar text_ru, void (*funcPress)()) :
        Item(), type(_type), text(text_ru), x(_x), y(_y), funcOnPress(funcPress) { }
    virtual void DrawMenuItem(int, int, int, bool) { }
    void Draw();
    pchar GetTitle() const;
    void SetTitle(pchar);
private:
    TypeButton::E type;
    pchar text;
    int x;
    int y;
    void (*funcOnPress)();
};


// Общего назначения
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
    Color colorBack;        // Этим цветом будем отрисовывать фон в случае Choice для выбора цвета
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

    // Возвращает указатель на выделенный пункт меню
    Item *SelectedItem() { return items[selectedItem]; }

    // Проверить на корректность номер выделенного итема. Если он больше, чем количество итемов - скорректировать
    void VerifySelectedItem();

    // Отображает значения параметров на изображении сигнала
    void DrawParameters() const;

    static const Page *ForCurrentSignal();

    // Запустить тест
    void StartTest() const;

    // Возвращает true, если текущая страница - страница сигнала
    static bool IsSignal(Page *);

    // Возвращает количество итемов на странице
    int NumItems() const;

    void DrawItems() const;

protected:

    // Возвращает ширину элемента меню с номером num
    int WidthItem(int num) const;

    // Указатель на массив элементов меню. Заканчивается нулём.
    Item **items;

    void (*funcDraw)();

private:

    // Номер выбранного итема
    int selectedItem;
};
