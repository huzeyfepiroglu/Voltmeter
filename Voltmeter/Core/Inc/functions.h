/*
 * 	functions.h
 *
 *  Created on	: February 12, 2025
 *  Company		: ASELSAN KONYA
 *  Author		: ABDULLAH HUZEYFE PIROGLU
 *
 */

#ifndef INC_FUNCTIONS_H_
#define INC_FUNCTIONS_H_

#include "main.h"

float checkVoltage(void);
float getMedianVoltage(void);
void sortFloatArray(float* arr, uint8_t size);
float low_pass_filter(void);

#endif /* INC_FUNCTIONS_H_ */
