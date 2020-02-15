/*
 * main.c
 *
 *  Created on: Dec 6, 2019
 *      Author: Ahmed Magdy
 */
#include"stdtypes.h"
#include"util.h"
#include"GPIO.h"
#include"Timer0.h"
void main (void)
{
    GPIO_Initialize_Port(PF);
    GPIO_Set_Pin_Direction(PF, PIN1, OUT);
    Timer0_Initialize();
    while(1);
}
TIMER0_Handler()
{
    u8 static count=0;
    if(GET_BIT(GPTMMIS,0)==1)
    {
        SET_BIT(GPTMICR,0);
        count++;

        if (count==1)
            GPIO_Write_Pin(PF, PIN1, HIGHV);
        else if (count==2)
        {
            GPIO_Write_Pin(PF, PIN1, LOWV);
            count=0;
        }
    }

}

