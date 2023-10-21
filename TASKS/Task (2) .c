/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Description		:	Task (2)
*/



#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "SEVEN_SEG_interface.h"
#include "DIO_interface.h"


#define LED_RED		DIOB, PIN7
#define LED_GRN		DIOA, PIN4
#define LED_BLU		DIOA, PIN5
#define LED_YEL		DIOA, PIN6

void Initialize_System(void);


int main(void)
{
	Initialize_System();

	while(1)
	{
		MCAL_DIO_voidWritePin(LED_RED, High);
		for(u8 i = 9; i > 0; i--)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
		MCAL_DIO_voidWritePin(LED_RED, Low);


		MCAL_DIO_voidWritePin(LED_YEL, High);
		for(u8 i = 3; i > 0; i--)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
		MCAL_DIO_voidWritePin(LED_YEL, Low);


		MCAL_DIO_voidWritePin(LED_GRN, High);
		for(u8 i = 8; i > 0; i--)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
		MCAL_DIO_voidWritePin(LED_GRN, Low);
	}

}


void Initialize_System(void)
{
	MCAL_DIO_voidSetPinMode(DIOA,PIN3,Output);	
	MCAL_DIO_voidSetPinMode(DIOA,PIN2,Output);	
	MCAL_DIO_voidSetPinMode(DIOB,PIN5,Output);	
	MCAL_DIO_voidSetPinMode(DIOB,PIN6,Output);	

	MCAL_DIO_voidWritePin(DIOA,PIN3,High);
	MCAL_DIO_voidWritePin(DIOA,PIN2,High);
	MCAL_DIO_voidWritePin(DIOB,PIN5,High);
	MCAL_DIO_voidWritePin(DIOB,PIN6,High);

	
	MCAL_DIO_voidSetPinMode(DIOB, PIN0, Output); 
	MCAL_DIO_voidSetPinMode(DIOB, PIN1, Output); 
	MCAL_DIO_voidSetPinMode(DIOB, PIN2, Output); 
	MCAL_DIO_voidSetPinMode(DIOB, PIN4, Output); 

	MCAL_DIO_voidSetPinMode(LED_RED, Output);
	MCAL_DIO_voidSetPinMode(LED_GRN, Output);
	MCAL_DIO_voidSetPinMode(LED_BLU, Output);
	MCAL_DIO_voidSetPinMode(LED_YEL, Output);
}
