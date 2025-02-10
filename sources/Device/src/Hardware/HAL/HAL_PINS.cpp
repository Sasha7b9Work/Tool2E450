// 2024/02/01 16:42:26 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/HAL/HAL.h"
#include "Hardware/HAL/HAL_PINS.h"
#include "Hardware/Timer.h"
#include <stm32f4xx_hal.h>


PinOut pinHL1(GPIOD, GPIO_PIN_6);
PinOut pinHL2(GPIOD, GPIO_PIN_7);
PinOut pinHL3(GPIOA, GPIO_PIN_2);
PinOut pinHL4(GPIOB, GPIO_PIN_4);

PinOut pinDISP_BL_C(GPIOB, GPIO_PIN_0);
PinOut pinDISP_RESET(GPIOC, GPIO_PIN_5);
PinOut pinDISP_WAIT(GPIOC, GPIO_PIN_6);

PinOut pinLED(GPIOC, GPIO_PIN_13);

PinIn pinMPG_X1(GPIOD, GPIO_PIN_0);
PinIn pinMPG_X10(GPIOD, GPIO_PIN_1);
PinIn pinMPG_X100(GPIOD, GPIO_PIN_2);
PinIn pinMPG_X(GPIOD, GPIO_PIN_3);
PinIn pinMPG_Y(GPIOD, GPIO_PIN_4);
PinIn pinMPG_A(GPIOD, GPIO_PIN_12);
PinIn pinMPG_B(GPIOD, GPIO_PIN_13);
PinIn pinMPG_4(GPIOD, GPIO_PIN_14);
PinIn pinMPG_5(GPIOD, GPIO_PIN_15);
PinIn pinMPG_6(GPIOE, GPIO_PIN_0);
PinIn pinMPG_CN(GPIOE, GPIO_PIN_3);

PinIn pinIN_1(GPIOB, GPIO_PIN_3);
PinIn pinIN_2(GPIOB, GPIO_PIN_5);
PinIn pinIN_3(GPIOD, GPIO_PIN_5);
PinIn pinIN_4(GPIOC, GPIO_PIN_12);
PinIn pinIN_5(GPIOC, GPIO_PIN_11);
PinIn pinIN_6(GPIOC, GPIO_PIN_10);
PinIn pinIN_7(GPIOA, GPIO_PIN_15);
PinIn pinIN_8(GPIOA, GPIO_PIN_12);
PinIn pinIN_9(GPIOA, GPIO_PIN_11);
PinIn pinIN_10(GPIOA, GPIO_PIN_8);
PinIn pinIN_11(GPIOC, GPIO_PIN_9);
PinIn pinIN_12(GPIOC, GPIO_PIN_8);
PinIn pinIN_13(GPIOC, GPIO_PIN_7);
PinIn pinIN_14(GPIOD, GPIO_PIN_11);
PinIn pinIN_15(GPIOD, GPIO_PIN_10);
PinIn pinIN_16(GPIOD, GPIO_PIN_9);
PinIn pinIN_17(GPIOD, GPIO_PIN_8);
PinIn pinIN_18(GPIOB, GPIO_PIN_15);
PinIn pinIN_19(GPIOB, GPIO_PIN_14);
PinIn pinIN_20(GPIOB, GPIO_PIN_13);
PinIn pinIN_21(GPIOB, GPIO_PIN_12);
PinIn pinIN_22(GPIOE, GPIO_PIN_14);
PinIn pinIN_23(GPIOC, GPIO_PIN_4);
PinIn pinIN_24(GPIOE, GPIO_PIN_12);
PinIn pinIN_25(GPIOE, GPIO_PIN_13);
PinIn pinIN_31(GPIOA, GPIO_PIN_3);

PinIn pinSA1(GPIOE, GPIO_PIN_4);
PinIn pinSA2_1(GPIOE, GPIO_PIN_2);
PinIn pinSA2_2(GPIOE, GPIO_PIN_1);
PinIn pinSA3_1(GPIOB, GPIO_PIN_9);
PinIn pinSA3_2(GPIOB, GPIO_PIN_8);

PinIn pinSB2(GPIOC, GPIO_PIN_0);
PinIn pinSB3(GPIOC, GPIO_PIN_2);
PinIn pinSB4(GPIOB, GPIO_PIN_1);
PinIn pinSB5(GPIOB, GPIO_PIN_2);
PinIn pinSB6(GPIOE, GPIO_PIN_7);
PinIn pinSB7(GPIOE, GPIO_PIN_8);
PinIn pinSB8(GPIOE, GPIO_PIN_10);
PinIn pinSB9(GPIOE, GPIO_PIN_6);
PinIn pinSB10(GPIOE, GPIO_PIN_5);

PinIn pinENC_A7_A(GPIOE, GPIO_PIN_9);
PinIn pinENC_A7_B(GPIOE, GPIO_PIN_11);
PinIn pinENC_A8_A(GPIOA, GPIO_PIN_0);
PinIn pinENC_A8_B(GPIOA, GPIO_PIN_1);


void HAL_PINS::Init()
{
}


void PinOut::ToHi()
{
    GPIO_TypeDef *gpio = (GPIO_TypeDef *)port;

    HAL_GPIO_WritePin(gpio, pin, GPIO_PIN_SET);
}


void PinOut::ToHi(uint timeUS)
{
    ToHi();

    HAL_TIM::DelayUS(timeUS);

    ToLow();
}


void PinOut::ToLow()
{
    GPIO_TypeDef *gpio = (GPIO_TypeDef *)port;

    HAL_GPIO_WritePin(gpio, pin, GPIO_PIN_RESET);
}


void PinOut::ToState(bool state)
{
    state ? ToHi() : ToLow();
}


bool PinIn::IsLow() const
{
    return HAL_GPIO_ReadPin((GPIO_TypeDef *)port, pin) == GPIO_PIN_RESET;
}


bool PinIn::IsHi() const
{
    return !IsLow();
}


void Pin::Init()
{
    if (mode == PinMode::OUTPUT)
    {
        GPIO_InitTypeDef is =
        {
            pin,
            GPIO_MODE_OUTPUT_PP,
            GPIO_PULLUP
        };
        HAL_GPIO_Init((GPIO_TypeDef *)port, &is);

        HAL_GPIO_WritePin((GPIO_TypeDef *)port, pin, GPIO_PIN_RESET);
    }
    else if (mode == PinMode::INPUT)
    {
        GPIO_InitTypeDef is =
        {
            pin,
            GPIO_MODE_INPUT,
            GPIO_PULLUP
        };

        HAL_GPIO_Init((GPIO_TypeDef *)port, &is);
    }
}
