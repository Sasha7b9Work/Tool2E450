// (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "defines.h"


#define MAKE_COLOR(r, g, b)     ((uint)((r) | ((g) << 8) | ((b) << 16)))

#define BLUE_FROM_COLOR(color)   ((uint8)(((color) >> 16) & 0xFF))
#define GREEN_FROM_COLOR(color) ((uint8)(((color) >> 8) & 0xFF))
#define RED_FROM_COLOR(color)  ((uint8)((color) & 0xFF))


struct Color
{
    static Color FILL;              // ���� ����� ��������
    static Color BACK;              // ���� ����
    static Color MENU_UNSELECT;     // ��� ������������� �����
    static Color MENU_SELECT;       // ��� ����������� �����
    static Color RED;               // ������� ��������� ��� ���������
    static Color GREEN;             // ������ ��������� ��� ���������
    static Color BLUE;              // ����� ��������� ��� ���������
    static Color WHITE;             // �����
    static Color BLACK;             // ׸���� ���
    static Color GRAY_75;
    static Color YELLOW;
    static Color PRESSED;           // ����� ����, ������� ����� ������ � ������� ���������

    static const int COUNT = 255;

    explicit Color(uint8 i) : index(i) {}

    void SetAsCurrent() const;
    static Color GetCurrent();

    uint8 Index() const { return index;  }

    void SetValue(uint value) const { Value() = value; }
    void SetValue(uint8 red, uint8 green, uint8 blue) const { Value() = MAKE_COLOR(red, green, blue); }

    // ������ �� ��������
    uint &Value() const;

    uint8 GetRED() const;
    uint8 GetGREEN() const;
    uint8 GetBLUE() const;

private:

    uint8 index;
};
