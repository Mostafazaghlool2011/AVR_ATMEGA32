/*
		Author			: 	Mostafa Zaghlol
		Date			:	20/10/2023
		Version			:	V 1.0
		Description		:	Standard types library
*/


#include "BIT_Math.h"
#include "STD_Types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void MCAL_DIO_voidSetPinMode(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_u8PINn, DIOMode_t Copy_DIOMode_tMode)
{
	if(Copy_DIOPort_tDIOx < 4)
	{
		if(Copy_u8PINn < 8)
		{
			switch(Copy_DIOPort_tDIOx)
			{
				case DIOA:			
					if(Copy_DIOMode_tMode) SET_BIT(DDRA,Copy_u8PINn);
					else CLR_BIT(DDRA,Copy_u8PINn);
					break;
				case DIOB:		
					if(Copy_DIOMode_tMode) SET_BIT(DDRB,Copy_u8PINn);
					else CLR_BIT(DDRB,Copy_u8PINn);
					break;
				case DIOC:			 
					if(Copy_DIOMode_tMode) SET_BIT(DDRC,Copy_u8PINn);
					else CLR_BIT(DDRC,Copy_u8PINn);
					break;
				case DIOD:			
					if(Copy_DIOMode_tMode) SET_BIT(DDRD,Copy_u8PINn);
					else CLR_BIT(DDRD,Copy_u8PINn);
					break;
			}
		}
		else
		{
			//Error_Handler();
		}
	}
	else
	{
		//Error_Handler();
	}
}


void MCAL_DIO_voidWritePin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn, DIOState_t Copy_DIOState_tValue)
{
	if(Copy_DIOPort_tDIOx < 4)
	{
		if(Copy_DIOPin_tPINn < 8)
		{
			switch(Copy_DIOPort_tDIOx)
			{
				case DIOA:			
					if(Copy_DIOState_tValue) SET_BIT(PORTA,Copy_DIOPin_tPINn);
					else CLR_BIT(PORTA,Copy_DIOPin_tPINn);
					break;
				case DIOB:			
					if(Copy_DIOState_tValue) SET_BIT(PORTB,Copy_DIOPin_tPINn);
					else CLR_BIT(PORTB,Copy_DIOPin_tPINn);
					break;
				case DIOC:			
					if(Copy_DIOState_tValue) SET_BIT(PORTC,Copy_DIOPin_tPINn);
					else CLR_BIT(PORTC,Copy_DIOPin_tPINn);
					break;
				case DIOD:			
					if(Copy_DIOState_tValue) SET_BIT(PORTD,Copy_DIOPin_tPINn);
					else CLR_BIT(PORTD,Copy_DIOPin_tPINn);
					break;
			}
		}
	}
	else
	{
		//Error_Handler();
	}
}


u8 MCAL_DIO_u8ReadPin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn)
{
	u8 pinValue;
	if(Copy_DIOPort_tDIOx < 4)
	{
		if(Copy_DIOPin_tPINn < 8)
		{
			switch(Copy_DIOPort_tDIOx)
			{
				case DIOA:			
					pinValue = GET_BIT(PINA,Copy_DIOPin_tPINn);
					break;
				case DIOB:			
					pinValue = GET_BIT(PINB,Copy_DIOPin_tPINn);
					break;
				case DIOC:			
					pinValue = GET_BIT(PINC,Copy_DIOPin_tPINn);
					break;
				case DIOD:			
					pinValue = GET_BIT(PIND,Copy_DIOPin_tPINn);
					break;
			}
			return pinValue;
		}
		else
		{
			//Error_Handler();
			return 0xFF;
		}
	}
	else
	{
		//Error_Handler();
		return 0xFF;
	}
}


void MCAL_DIO_voidWriteWord(DIOPort_t Copy_DIOPort_tDIOx, u8 Copy_u8Word)
{
	if(Copy_DIOPort_tDIOx < 4)
	{
		switch(Copy_DIOPort_tDIOx)
		{
			case DIOA:			
				PORTA = Copy_u8Word;
				break;
			case DIOB:			
				PORTB = Copy_u8Word;
				break;
			case DIOC:			
				PORTC = Copy_u8Word;
				break;
			case DIOD:			
				PORTD = Copy_u8Word;
				break;
		}
	}
}


u8 MCAL_DIO_u8WordRead(DIOPort_t Copy_DIOPort_tDIOx)
{
	u8 portValue;
	if(Copy_DIOPort_tDIOx < 4)
	{
		switch(Copy_DIOPort_tDIOx)
		{
			case DIOA:		
				portValue = PINA;
				break;
			case DIOB:			
				portValue = PINB;
				break;
			case DIOC:		
				portValue = PINC;
				break;
			case DIOD:			
				portValue = PIND;
				break;
			default:
				//No Code
				break;
		}
		return portValue;
	}
	else
	{
		return 0;
	}
}


void MCAL_DIO_voidTogglePin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn)
{
	if(Copy_DIOPort_tDIOx < 4)
	{
		if(Copy_DIOPin_tPINn < 8)
		{
			switch(Copy_DIOPort_tDIOx)
			{
				case DIOA:			
					TOG_BIT(PORTA,Copy_DIOPin_tPINn);
					break;
				case DIOB:			
					TOG_BIT(PORTB,Copy_DIOPin_tPINn);
					break;
				case DIOC:			
					TOG_BIT(PORTC,Copy_DIOPin_tPINn);
					break;
				case DIOD:			
					TOG_BIT(PORTD,Copy_DIOPin_tPINn);
					break;
			}
		}
		else
		{
			//Error_Handler();
		}
	}
	else
	{
		//Error_Handler();
	}
}


void MCAL_DIO_voidTogglePort(DIOPort_t Copy_DIOPort_tDIOx)
{
	if(Copy_DIOPort_tDIOx < 4)
	{
		switch(Copy_DIOPort_tDIOx)
		{
			case DIOA:			
				PORTA ^= 0xFF;
				break;
			case DIOB:		
				PORTB ^= 0xFF;
				break;
			case DIOC:			
				PORTC ^= 0xFF;
				break;
			case DIOD:		
				PORTD ^= 0xFF;
				break;
		}
	}
	else
	{
		//Error_Handler();
	}
}
