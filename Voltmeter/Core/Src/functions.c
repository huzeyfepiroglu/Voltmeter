/*
 * 	functions.c
 *
 *  Created on	: February 12, 2025
 *  Company		: ASELSAN KONYA
 *  Author		: ABDULLAH HUZEYFE PIROGLU
 *
 */

#include "functions.h"
#include "definitions.h"
#include "timing.h"
#include <stdint.h>

#define BUFFER_SIZE 5

float voltageBuffer[BUFFER_SIZE] = {0};
uint8_t bufferIndex = 0;
uint8_t bufferCount = 0;

float filtered = 0;
float alpha = 0.6;  // 0 < alpha < 1, küçüldükçe daha yumuşak olur

float checkVoltage(void)
{
//	if(_1sFlag)
	{
		// 3.1205 / 4095 = 1 bite denk gelen voltage
		voltmeter.voltage = ((3.3/4095)*voltmeter.adcValue) * 14.55;

		if(voltmeter.voltage < 22)
		{
			//voltmeter.mode = false;
		}
		else
		{
			//voltmeter.mode = true;
		}
//	}
	return voltmeter.voltage;
}

}


float low_pass_filter(void)
{
	if(_1sFlag)
	{
		// 2481 ADC REAL = 27.00 volt MEASURE = 28.00  K = 13.505
		uint8_t multiplierCorrection =13.52;

//		if(voltmeter.adcValue < 1200)
//		{
//			multiplierCorrection = 14;
//		}
//
//		else
//		{
//			multiplierCorrection = 13.65;
//		}
		voltmeter.voltage = (((3.3/4095)*voltmeter.adcValue) * multiplierCorrection)+0.5;

		if(voltmeter.voltage < 22)
		{
			voltmeter.mode = false;
		}
		else
		{
			voltmeter.mode = true;
		}

	    filtered = alpha * voltmeter.voltage + (1.0 - alpha) * filtered;
	}

    return filtered;
}
