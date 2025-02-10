// 2024/02/01 16:41:42 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once


struct PinMode
{
    enum E
    {
        OUTPUT,
        INPUT,
        Count
    };
};


struct Pin
{
    Pin(PinMode::E _mode, void *_port, uint16 _pin) : port(_port), pin(_pin), mode(_mode) { }
    void Init();
protected:
    void      *port;
    uint16     pin;
    PinMode::E mode;
};


struct PinOut : public Pin
{
    PinOut(void *_port, uint16 _pin) : Pin(PinMode::OUTPUT, _port, _pin) { }
    void ToHi();
    void ToHi(uint timeUS);
    void ToLow();
    void ToState(bool);
};


struct PinIn : public Pin
{
    PinIn(void *_port, uint16 _pin) : Pin(PinMode::INPUT, _port, _pin) { }
    bool IsHi() const;
    bool IsLow() const;
};


namespace HAL_PINS
{
    void Init();
}
