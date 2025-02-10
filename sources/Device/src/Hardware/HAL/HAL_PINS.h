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


extern PinOut pinHL1;
extern PinOut pinHL2;
extern PinOut pinHL3;
extern PinOut pinHL4;

extern PinOut pinDISP_BL_C;
extern PinOut pinDISP_RESET;
extern PinOut pinDISP_WAIT;

extern PinOut pinLED;

extern PinIn pinMPG_X1;
extern PinIn pinMPG_X10;
extern PinIn pinMPG_X100;
extern PinIn pinMPG_X;
extern PinIn pinMPG_Y;
extern PinIn pinMPG_A;
extern PinIn pinMPG_B;
extern PinIn pinMPG_4;
extern PinIn pinMPG_5;
extern PinIn pinMPG_6;
extern PinIn pinMPG_CN;

extern PinIn pinIN_1;
extern PinIn pinIN_2;
extern PinIn pinIN_3;
extern PinIn pinIN_4;
extern PinIn pinIN_5;
extern PinIn pinIN_6;
extern PinIn pinIN_7;
extern PinIn pinIN_8;
extern PinIn pinIN_9;
extern PinIn pinIN_10;
extern PinIn pinIN_11;
extern PinIn pinIN_12;
extern PinIn pinIN_13;
extern PinIn pinIN_14;
extern PinIn pinIN_15;
extern PinIn pinIN_16;
extern PinIn pinIN_17;
extern PinIn pinIN_18;
extern PinIn pinIN_19;
extern PinIn pinIN_20;
extern PinIn pinIN_21;
extern PinIn pinIN_22;
extern PinIn pinIN_23;
extern PinIn pinIN_24;
extern PinIn pinIN_25;
extern PinIn pinIN_31;

extern PinIn pinSA1;
extern PinIn pinSA2_1;
extern PinIn pinSA2_2;
extern PinIn pinSA3_1;
extern PinIn pinSA3_2;

extern PinIn pinSB2;
extern PinIn pinSB3;
extern PinIn pinSB4;
extern PinIn pinSB5;
extern PinIn pinSB6;
extern PinIn pinSB7;
extern PinIn pinSB8;
extern PinIn pinSB9;
extern PinIn pinSB10;

extern PinIn pinENC_A7_A;
extern PinIn pinENC_A7_B;
extern PinIn pinENC_A8_A;
extern PinIn pinENC_A8_B;

