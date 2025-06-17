/*
 * 	seven_segment_display.c
 *
 *  Created on	: February 12, 2025
 *  Company		: ASELSAN KONYA
 *  Author		: ABDULLAH HUZEYFE PIROGLU
 *
 */


#include "seven_segment_display.h"
#include "definitions.h"
#include "timing.h"

volatile uint8_t currentDigit = 0;
volatile uint8_t digits[4] = {0, 0, 0, 0};

void sevenSegmentDisplaySetDigit(uint8_t digitPosition, uint8_t number, uint8_t decimalPosition)
{

    if (!voltmeter.blinkFlag && !voltmeter.mode)
    {
        DIGIT_CONTROL(DIGIT_1,DIGIT_OFF);
        DIGIT_CONTROL(DIGIT_2,DIGIT_OFF);
        DIGIT_CONTROL(DIGIT_3,DIGIT_OFF);
        DIGIT_CONTROL(DIGIT_4,DIGIT_OFF);
        SEGMENT_CONTROL(SEG_A, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_B, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_C, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_D, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_E, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_F, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_G, SEGMENT_OFF);
        SEGMENT_CONTROL(SEG_DP, SEGMENT_OFF);
        return;
    }

    uint8_t segmentPositions = COMMON_CATHODE_SEGMENT_MAP[number];

    DIGIT_CONTROL(DIGIT_1,DIGIT_OFF);
    DIGIT_CONTROL(DIGIT_2,DIGIT_OFF);
    DIGIT_CONTROL(DIGIT_3,DIGIT_OFF);
    DIGIT_CONTROL(DIGIT_4,DIGIT_OFF);

    SEGMENT_CONTROL(SEG_A ,(segmentPositions & SEG_A_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_B ,(segmentPositions & SEG_B_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_C ,(segmentPositions & SEG_C_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_D ,(segmentPositions & SEG_D_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_E ,(segmentPositions & SEG_E_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_F ,(segmentPositions & SEG_F_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_G ,(segmentPositions & SEG_G_POSITION) ? SEGMENT_ON : SEGMENT_OFF);
    SEGMENT_CONTROL(SEG_DP,(decimalPosition  & SEG_DP_POSITION)? SEGMENT_ON : SEGMENT_OFF);
//    if(!voltmeter.mode && _500msFlag)
//    {
//        switch (digitPosition)
//        {
//            case 0: DIGIT_CONTROL(DIGIT_1,DIGIT_ON);break;
//            case 1: DIGIT_CONTROL(DIGIT_2,DIGIT_ON);break;
//            case 2: DIGIT_CONTROL(DIGIT_3,DIGIT_ON);break;
//            case 3: DIGIT_CONTROL(DIGIT_4,DIGIT_ON);break;
//            default: /*out of range*/ break;
//        }
//    }
//    else if(voltmeter.mode)
//    {
        switch (digitPosition)
        {
            case 0:
            	DIGIT_CONTROL(DIGIT_1,DIGIT_ON);
            	//SEGMENT_CONTROL(SEG_DP, SEGMENT_OFF);
            	break;
            case 1:
            	DIGIT_CONTROL(DIGIT_2,DIGIT_ON);
            	SEGMENT_CONTROL(SEG_DP, SEGMENT_ON);
            	break;
            case 2:
            	DIGIT_CONTROL(DIGIT_3,DIGIT_ON);
            	//SEGMENT_CONTROL(SEG_DP, SEGMENT_OFF);
            	break;
            case 3:
            	DIGIT_CONTROL(DIGIT_4,DIGIT_ON);
            	//SEGMENT_CONTROL(SEG_DP, SEGMENT_OFF);
            	break;
            default: /*out of range*/ break;
        }
 //   }



}
void sevenSegmentDisplayUpdate(void)
{
	if(_1msFlag)
	{
			sevenSegmentDisplaySetDigit(currentDigit, digits[currentDigit],2);

			currentDigit = (currentDigit + 1) % 4;

			if(currentDigit == 4) currentDigit = 0;
	}
}
void sevenSegmentDisplaySetNumbers(float value)
{
    uint16_t number = (uint16_t)(value * 100);

    digits[0] = (number / 1000) % 10;
    digits[1] = (number / 100) % 10;
    digits[2] = (number / 10) % 10;
    digits[3] = 0;//(number / 1) % 10;

}
