/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Description		:	Task (3)
*/


#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "SEVEN_SEG_interface.h"
#include "DIO_interface.h"


#define DCOM1	DIOA,PIN3
#define DCOM2	DIOA,PIN2
#define DCOM3	DIOB,PIN5
#define DCOM4	DIOB,PIN6


void Initialize_System(void);


int main(void)
{
	Initialize_System();
	u16 s = 0;
	s8 d2 = 0 , d1 = 0, d3 = 9, d4 = 9;

	while(1)
	{
		if(s == 1000)
		{
			s = 0;
			d1++;
			if(d1 > 9)
			{
				d1 = 0;
				d2++;
				if(d2 > 9)
				{
					d2 = 0;
				}
			}

			d3--;
			if(d3 < 0)
			{
				d3 = 9;
				d4--;
				if(d4 < 0)
				{
					d4 = 9;
				}
			}
		}


		HAL_SEVEN_SEG_voidDisplay(COM1, d1);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM1, High);

	
		HAL_SEVEN_SEG_voidDisplay(COM2, d2);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM2, High);

	
		HAL_SEVEN_SEG_voidDisplay(COM3, d3);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM3, High);

	
		HAL_SEVEN_SEG_voidDisplay(COM4, d4);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM4, High);
	}

}


void Initialize_System(void)
{
	MCAL_DIO_voidSetPinMode(DCOM1,Output);	
	MCAL_DIO_voidSetPinMode(DCOM2,Output);	
	MCAL_DIO_voidSetPinMode(DCOM3,Output);	
	MCAL_DIO_voidSetPinMode(DCOM4,Output);	

	MCAL_DIO_voidWritePin(DCOM1,High);
	MCAL_DIO_voidWritePin(DCOM2,High);
	MCAL_DIO_voidWritePin(DCOM3,High);
	MCAL_DIO_voidWritePin(DCOM4,High);


	MCAL_DIO_voidSetPinMode(DIOB, PIN0, Output); 
	MCAL_DIO_voidSetPinMode(DIOB, PIN1, Output); 
	MCAL_DIO_voidSetPinMode(DIOB, PIN2, Output); 
	MCAL_DIO_voidSetPinMode(DIOB, PIN4, Output); 
}