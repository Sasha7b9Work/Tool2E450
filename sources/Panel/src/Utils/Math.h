// 2025/02/11 19:58:27 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once


namespace Math
{
    template<class T> void Swap(T &x1, T &x2)
    {
        T temp = x1; x1 = x2; x2 = temp;
    }
}
