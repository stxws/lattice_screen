/**
 ************************************
 * @file     : max7219_drv.c
 * @author   : stxws
 * @date     : 2021-07-23
 ************************************
 * @brief :
 * 		MAX7219驱动实现
 */

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "max7219_drv.h"

/**
 * @brief : 设置MAX7219的引脚高低电平
 * @param pin : [in]对应的引脚
 * @param logic : [in]传如0表示设置成低电平，非0表示高电平
 */
void write_max7219_pin(max7219_pin_def pin, unsigned char logic)
{
	if(logic == 0)
	{
		HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_SET);
	}
}

