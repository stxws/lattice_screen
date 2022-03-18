/**
 ************************************
 * @file     : screen.h
 * @author   : stxws
 * @date     : 2021-07-27
 ************************************
 * @brief :
 * 		16×16点阵屏驱动头文件，需要有max7219驱动
 */

#ifndef __SCREEN_H
#define __SCREEN_H

#include "max7219_api.h"

/**
 * @brief : 让8*8点阵屏显示一个A
 */
void show_a(max7219_pin_def cs_pin);

/**
 * @brief : 初始化16×16点阵屏
 */
void init_screen();

/**
 * @brief : 让16*16点阵屏显示一个字
 * @param word_code : [in]需要显示字的编码，32个字节
 */
void show_word(unsigned char *word_code);

/**
 * @brief : 将字的编码循环移动一位
 * @param word_code : [in/out]字的编码
 * @param word_count : [in]字的个数
 */
void cyclic_shift_word(unsigned char *word_code, int word_count);

#endif /* __SCREEN_H */