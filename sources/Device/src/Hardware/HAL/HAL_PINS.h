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

extern PinOut pinT3D_PULS_2;
extern PinOut pinT3D_SIGN_2;
extern PinIn  pinT3D_D01_2;
extern PinOut pinT3D_SIGN_1;
extern PinOut pinT3D_S0N1;
extern PinOut pinT3D_PULS_1;
extern PinIn  pinENC_A7_A;
extern PinIn  pinENC_A7_B;
extern PinIn  pinT3D_D01_1;

extern PinOut pinESQ_X1;
extern PinOut pinESQ_X2;
extern PinIn  pinESQ_TC;
extern PinIn  pinRKF;
extern PinIn  pinKM1;
extern PinIn  pinKM2;
extern PinIn  pinKM3;
extern PinIn  pinKM4;
extern PinIn  pinQF5;
extern PinIn  pinQF6;
extern PinIn  pinQF7;
extern PinIn  pinQF10;
extern PinIn  pinQF11;
extern PinIn  pinQF12;
extern PinIn  pinQF13;
extern PinIn  pinQF14;
extern PinIn  pinQF15;
extern PinIn  pinKM5;
extern PinIn  pinKM6;
extern PinOut
