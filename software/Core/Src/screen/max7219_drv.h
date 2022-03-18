/**
 ************************************
 * @file     : max7219_drv.h
 * @author   : stxws
 * @date     : 2021-07-23
 ************************************
 * @brief :
 * 		MAX7219驱动头文件
 */

#ifndef __MAX7219_DRV_H
#define __MAX7219_DRV_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

/**
 * @brief : 与MAX7219相关的引脚定义
 */
typedef enum
{
	CLK_PIN = GPIO_PIN_7,
	DIN_PIN = GPIO_PIN_8,

	CS1_PIN = GPIO_PIN_3,
	CS2_PIN = GPIO_PIN_4,
	CS3_PIN = GPIO_PIN_5,
	CS4_PIN = GPIO_PIN_6
} max7219_pin_def;

/**
 * @brief : 设置MAX7219的引脚高低电平
 * @param pin : [in]对应的引脚
 * @param logic : [in]传如0表示设置成低电平，非0表示高电平
 */
void write_max7219_pin(max7219_pin_def pin, unsigned char logic);

#endif /* __MAX7219_DRV_H */