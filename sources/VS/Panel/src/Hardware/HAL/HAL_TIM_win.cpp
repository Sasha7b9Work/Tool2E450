// 2025/02/11 20:45:58 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/HAL/HAL.h"
#include <ctime>


void HAL_TIM::Init()
{

}


void HAL_TIM2::Init()
{

}


uint HAL_TIM2::GetTicks()
{
    return 0;
}


void HAL_TIM3::Init()
{

}


void HAL_TIM3::StartIT(uint)
{

}


void HAL_TIM3::StopIT()
{

}


uint HAL_TIM::TimeMS()
{
    return (uint)std::clock();
}
