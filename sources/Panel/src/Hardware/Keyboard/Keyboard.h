// 2025/02/11 19:57:44 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once



struct Key
{
    enum E
    {
        None,       //  0
        _1,         //  1
        _2,         //  2
        _3,         //  3
        _4,         //  4
        Count
    };

    static pchar Name(E);
};


struct Action
{
    enum E
    {
        Press,
        Release,
        Long,
        Count
    };
};

struct Control
{
    Key::E key = Key::None;
    Action::E action = Action::Count;

    Control(Key::E v = Key::None, Action::E a = Action::Press) : key(v), action(a)
    {
    }

    bool IsRelease() const
    {
        return action == Action::Release;
    }
};

namespace Keyboard
{
    void Init();

    // Возвращает true, если есть событыия
    bool Empty();

    // Возвращает следующее событие
    Control NextControl();

    void Lock();

    void Unlock();
};
