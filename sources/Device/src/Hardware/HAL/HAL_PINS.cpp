// 2024/02/01 16:42:26 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/HAL/HAL.h"
#include "Hardware/HAL/HAL_PINS.h"
#include "Hardware/Timer.h"
#include <stm32f4xx_hal.h>


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
