/*
 * 	seven_segment_display.h
 *
 *  Created on	: February 12, 2025
 *  Company		: ASELSAN KONYA
 *  Author		: ABDULLAH HUZEYFE PIROGLU
 *
 */

#ifndef INC_SEVEN_SEGMENT_DISPLAY_H_
#define INC_SEVEN_SEGMENT_DISPLAY_H_

#include "main.h"

#define SEGMENT_CONTROL(segment, action)  \
    HAL_GPIO_WritePin(segment##_GPIO_Port, segment##_Pin, (action == ON) ? GPIO_PIN_SET : GPIO_PIN_RESET)

#define DIGIT_CONTROL(digit, action)  \
    HAL_GPIO_WritePin(digit##_GPIO_Port, digit##_Pin, (action == ON) ? GPIO_PIN_SET : GPIO_PIN_RESET)

#define ON	1
#define OFF	0

#define SEGMENT_ON	0
#define SEGMENT_OFF	1

#define DIGIT_ON	1
#define DIGIT_OFF	0

#define SEG_A_POSITION 	0x01
#define SEG_B_POSITION 	0x02
#define SEG_C_POSITION 	0x04
#define SEG_D_POSITION 	0x08
#define SEG_E_POSITION 	0x10
#define SEG_F_POSITION 	0x20
#define SEG_G_POSITION 	0x40
#define SEG_DP_POSITION	0x80

static const uint8_t COMMON_CATHODE_SEGMENT_MAP[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

#define SEG_A
#define SEG_B
#define SEG_C
#define SEG_D
#define SEG_E
#define SEG_F
#define SEG_G
#define SEG_DP

#define DIGIT_1
#define DIGIT_2
#define DIGIT_3
#define DIGIT_4

void sevenSegmentDisplaySetDigit(uint8_t digit, uint8_t number, uint8_t decimal);
void sevenSegmentDisplayUpdate(void);
void sevenSegmentDisplaySetNumbers(float value);

#endif /* INC_SEVEN_SEGMENT_DISPLAY_H_ */
