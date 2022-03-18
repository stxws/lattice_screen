/**
 ************************************
 * @file     : max7219_api.c
 * @author   : stxws
 * @date     : 2021-07-23
 ************************************
 * @brief :
 * 		MAX7219接口实现
 */

#include "max7219_drv.h"
#include "max7219_api.h"

/**
 * @brief : 向MAX7219的移位寄存器写入一个字节的数据
 * @param data : [in]需要写入的数据
 */
void write_max7219_byte(unsigned char data)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		write_max7219_pin(CLK_PIN, 0);
		if(data & 0x80)
		{
			write_max7219_pin(DIN_PIN, 1);
		}
		else
		{
			write_max7219_pin(DIN_PIN, 0);
		}
		write_max7219_pin(CLK_PIN, 1);
		data = data << 1;
	}
}

/**
 * @brief : 向MAX7219的内部寄存器写入数据
 * @param load_pin : [in]对应MAX7219的LOAD引脚
 * @param address : [in]内部寄存器地址
 * @param data : [in]需要写入内部寄存器的数据
 */
void write_max7219_register(max7219_pin_def load_pin, unsigned char address, unsigned char data)
{
	write_max7219_pin(load_pin, 0);
	write_max7219_byte(address);
	write_max7219_byte(data);
	write_max7219_pin(load_pin, 1);
}

/**
 * @brief : 初始化MAX7219
 * @param load_pin : [in]对应MAX7219的LOAD引脚
 */
void init_max7219(max7219_pin_def load_pin)
{
	write_max7219_register(load_pin, 0x09, 0x00); /* 译码方式 */
	write_max7219_register(load_pin, 0x0a, 0x03); /* 亮度 */
	write_max7219_register(load_pin, 0x0b, 0x07); /* 扫描界限；8个数码管显示 */
	write_max7219_register(load_pin, 0x0c, 0x01); /* 掉电模式：0，普通模式：1 */
	write_max7219_register(load_pin, 0x0f, 0x00); /* 显示测试：1；测试结束，正常显示：0 */
}
