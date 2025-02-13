// 2025/02/13 09:10:53 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Display/Primitives.h"


using namespace Primitives;


int HLine::Draw(int x, int /*y*/)
{
    return x;
}


int VLine::Draw(int /*x*/, int y)
{
    return y;
}


void Point::Draw(int /*x*/, int /*y*/)
{
}


Coord Line::Draw(int /*x1*/, int /*y1*/, int x2, int y2)
{
    return { x2, y2 };
}
