/**
 ************************************
 * @file     : screen.c
 * @author   : stxws
 * @date     : 2021-07-27
 ************************************
 * @brief :
 * 		16×16点阵屏驱动实现，需要有max7219驱动
 */

#include "max7219_api.h"

/**
 * @brief : 让点阵屏显示一个A
 */
void show_a(max7219_pin_def cs_pin)
{
	int i;
	unsigned char data[8] = {0x08, 0x14, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x22};

	init_max7219(cs_pin);
	for(i = 1; i <= 8; i++)
	{
		write_max7219_register(cs_pin, (unsigned char)i, data[i - 1]);
	}
}

/**
 * @brief : 初始化16×16点阵屏
 */
void init_screen()
{
	init_max7219(CS1_PIN);
	init_max7219(CS2_PIN);
	init_max7219(CS3_PIN);
	init_max7219(CS4_PIN);
}

/**
 * @brief : 让16*16点阵屏显示一个字
 */
void show_word(unsigned char *word_code)
{
	int i;
	for(i = 0; i < 16; i++)
	{
		if(i % 2 == 0)
		{
			write_max7219_register(CS4_PIN, (unsigned char)(i / 2 + 1), word_code[i]);
		}
		else
		{
			write_max7219_register(CS2_PIN, (unsigned char)(i / 2 + 1), word_code[i]);
		}
	}
	for(i = 16; i < 32; i++)
	{
		if(i % 2 == 0)
		{
			write_max7219_register(CS3_PIN, (unsigned char)(i / 2 - 8 + 1), word_code[i]);
		}
		else
		{
			write_max7219_register(CS1_PIN, (unsigned char)(i / 2 - 8 + 1), word_code[i]);
		}
	}
}

/**
 * @brief : 将字的编码循环移动一位
 * @param word_code : [in/out]字的编码
 * @param word_count : [in]字的个数
 */
void cyclic_shift_word(unsigned char *word_code, int word_count)
{
	int i, len;
	unsigned short front;
	unsigned char *p = word_code;

	front = 0x0000;
	for(i = 0; i < 16; i++)
	{
		if((p[2 * i] & 0x80) != 0)
		{
			front += (0x0001 << i);
		}
	}
	len = word_count * 32;
	for(i = 0; i < len - 32; i++)
	{
		if(i % 2 == 0)
		{
			p[i] = (p[i] << 1) + (p[i + 1] >> 7);
		}
		else
		{
			p[i] = (p[i] << 1) + (p[i + 31] >> 7);
		}
	}
	for(i = len - 32; i < len; i++)
	{
		if(i % 2 == 0)
		{
			p[i] = (p[i] << 1) + (p[i + 1] >> 7);
		}
		else
		{
			p[i] = (p[i] << 1) + ((front >> ((i + 31 - len) / 2)) & 0x0001);
		}
	}
}