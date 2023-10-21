/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Description		:	Task (1)
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
void BinaryNumber(u8 n);


int main(void)
{
	Initialize_System();

	while(1)
	{
		for(u8 i = 0; i < 10; i++)
		{
			BinaryNumber(i);
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
	}

}


void BinaryNumber(u8 n)
{
	switch(n)
	{
		case 0:
			MCAL_DIO_voidWritePin(LED_RED, Low);
			MCAL_DIO_voidWritePin(LED_GRN, Low);
			MCAL_DIO_voidWritePin(LED_BLU, Low);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 1:
			MCAL_DIO_voidWritePin(LED_RED, High);
			MCAL_DIO_voidWritePin(LED_GRN, Low);
			MCAL_DIO_voidWritePin(LED_BLU, Low);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 2:
			MCAL_DIO_voidWritePin(LED_RED, Low);
			MCAL_DIO_voidWritePin(LED_GRN, High);
			MCAL_DIO_voidWritePin(LED_BLU, Low);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 3:
			MCAL_DIO_voidWritePin(LED_RED, High);
			MCAL_DIO_voidWritePin(LED_GRN, High);
			MCAL_DIO_voidWritePin(LED_BLU, Low);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 4:
			MCAL_DIO_voidWritePin(LED_RED, Low);
			MCAL_DIO_voidWritePin(LED_GRN, Low);
			MCAL_DIO_voidWritePin(LED_BLU, High);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 5:
			MCAL_DIO_voidWritePin(LED_RED, High);
			MCAL_DIO_voidWritePin(LED_GRN, Low);
			MCAL_DIO_voidWritePin(LED_BLU, High);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 6:
			MCAL_DIO_voidWritePin(LED_RED, Low);
			MCAL_DIO_voidWritePin(LED_GRN, High);
			MCAL_DIO_voidWritePin(LED_BLU, High);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 7:
			MCAL_DIO_voidWritePin(LED_RED, High);
			MCAL_DIO_voidWritePin(LED_GRN, High);
			MCAL_DIO_voidWritePin(LED_BLU, High);
			MCAL_DIO_voidWritePin(LED_YEL, Low);
			break;
		case 8:
			MCAL_DIO_voidWritePin(LED_RED, Low);
			MCAL_DIO_voidWritePin(LED_GRN, Low);
			MCAL_DIO_voidWritePin(LED_BLU, Low);
			MCAL_DIO_voidWritePin(LED_YEL, High);
			break;
		case 9:
			MCAL_DIO_voidWritePin(LED_RED, High);
			MCAL_DIO_voidWritePin(LED_GRN, Low);
			MCAL_DIO_voidWritePin(LED_BLU, Low);
			MCAL_DIO_voidWritePin(LED_YEL, High);
			break;
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

	MCAL_DIO_voidSetPinMode(DIOA, PIN4, Output);
	MCAL_DIO_voidSetPinMode(DIOA, PIN5, Output);
	MCAL_DIO_voidSetPinMode(DIOA, PIN6, Output);
	MCAL_DIO_voidSetPinMode(DIOB, PIN7, Output);
}