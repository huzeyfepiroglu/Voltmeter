/*
 * 	definitions.h
 *
 *  Created on	: February 12, 2025
 *  Company		: ASELSAN KONYA
 *  Author		: ABDULLAH HUZEYFE PIROGLU
 *
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include "main.h"
#include "stdbool.h"

typedef struct
{
	volatile uint16_t adcValue;
	volatile bool mode;
	volatile float voltage;
	bool blinkFlag;

}voltmeterStructer;

extern voltmeterStructer voltmeter;

#endif /* DEFINITIONS_H_ */
