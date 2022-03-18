/**
 ************************************
 * @file     : max7219_api.h
 * @author   : stxws
 * @date     : 2021-07-23
 ************************************
 * @brief :
 * 		MAX7219接口头文件
 */

#ifndef __MAX7219_API_H
#define __MAX7219_API_H

#include "max7219_drv.h"

/**
 * @brief : 向MAX7219的移位寄存器写入一个字节的数据
 * @param data : [in]需要写入的数据
 */
void write_max7219_byte(unsigned char data);

/**
 * @brief : 向MAX7219的内部寄存器写入数据
 * @param load_pin : [in]对应MAX7219的LOAD引脚
 * @param address : [in]内部寄存器地址
 * @param data : [in]需要写入内部寄存器的数据
 */
void write_max7219_register(max7219_pin_def load_pin, unsigned char address, unsigned char data);

/**
 * @brief : 初始化MAX7219
 * @param load_pin : [in]对应MAX7219的LOAD引脚
 */
void init_max7219(max7219_pin_def load_pin);

#endif /* __MAX7219_API_H */