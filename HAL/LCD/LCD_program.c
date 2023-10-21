/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Version			:	V 1.0
		Description		:	LCD_program.c
*/


#include <BIT_Math.h>
#include "STD_Types.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "LCD_config.h"


static u8 InitFinished = 0;


void HAL_LCD_Init()
{

	
	MCAL_DIO_voidSetPinMode(RS, Output);
	MCAL_DIO_voidSetPinMode(E  , Output);
	MCAL_DIO_voidSetPinMode(DB7, Output);
	MCAL_DIO_voidSetPinMode(DB6, Output);
	MCAL_DIO_voidSetPinMode(DB5, Output);
	MCAL_DIO_voidSetPinMode(DB4, Output);


	_delay_ms(31);

	HAL_LCD_SendCommand(0x20);
	HAL_LCD_SendCommand(0x20);
	HAL_LCD_SendCommand(0x80);

	_delay_us(40);

	HAL_LCD_SendCommand(0x00);
	HAL_LCD_SendCommand(0xC0);

	_delay_us(40);

	HAL_LCD_SendCommand(0x00);
	HAL_LCD_SendCommand(0x10);

	_delay_ms(1.6);


	InitFinished = 1;
}


void HAL_LCD_SendCommand(u8 cmd)
{
	MCAL_DIO_voidWritePin(RS, Low);

	MCAL_DIO_voidWritePin(DB4, GET_BIT(cmd,4));
	MCAL_DIO_voidWritePin(DB5, GET_BIT(cmd,5));
	MCAL_DIO_voidWritePin(DB6, GET_BIT(cmd,6));
	MCAL_DIO_voidWritePin(DB7, GET_BIT(cmd,7));

	MCAL_DIO_voidWritePin(E, High);

	_delay_us(51);

	MCAL_DIO_voidWritePin(E, Low);

	if(InitFinished)
	{
		MCAL_DIO_voidWritePin(DB4, GET_BIT(cmd,0));
		MCAL_DIO_voidWritePin(DB5, GET_BIT(cmd,1));
		MCAL_DIO_voidWritePin(DB6, GET_BIT(cmd,2));
		MCAL_DIO_voidWritePin(DB7, GET_BIT(cmd,3));

		MCAL_DIO_voidWritePin(E, High);

		_delay_us(51);

		MCAL_DIO_voidWritePin(E, Low);
	}

	_delay_ms(1.6);
}


void HAL_LCD_WriteData(u8 Data)
{
	MCAL_DIO_voidWritePin(RS, High);

	MCAL_DIO_voidWritePin(DB4, GET_BIT(Data,4));
	MCAL_DIO_voidWritePin(DB5, GET_BIT(Data,5));
	MCAL_DIO_voidWritePin(DB6, GET_BIT(Data,6));
	MCAL_DIO_voidWritePin(DB7, GET_BIT(Data,7));

	MCAL_DIO_voidWritePin(E, High);

	_delay_us(51);

	MCAL_DIO_voidWritePin(E, Low);

	MCAL_DIO_voidWritePin(DB4, GET_BIT(Data,0));
	MCAL_DIO_voidWritePin(DB5, GET_BIT(Data,1));
	MCAL_DIO_voidWritePin(DB6, GET_BIT(Data,2));
	MCAL_DIO_voidWritePin(DB7, GET_BIT(Data,3));

	MCAL_DIO_voidWritePin(E, High);

	_delay_us(51);

	MCAL_DIO_voidWritePin(E, Low);

	_delay_ms(1.6);
}


void HAL_LCD_WriteString(u8 *string, u8 row, u8 col)
{
	HAL_LCD_ChangePos(row,col);
	u8 i = 0;
	while(string[i] != '\0')
	{
		HAL_LCD_WriteData(string[i]);
		i++;
		col++;
		if(col >= COL_MAX)
		{
			col = 0;
			row++;
			if(row >= ROW_MAX) row = 0;
			HAL_LCD_ChangePos(row,col);
		}
	}
}


void HAL_LCD_ChangePos(u8 row, u8 col)
{
	if(row < ROW_MAX && col < COL_MAX)
	{
		u8 Address;
		Address = (row * 0x40) + col;
		SET_BIT(Address,7);
		HAL_LCD_SendCommand(Address);
	}
}


void HAL_LCD_AddPattern(u8* Pattern, u8 CGRAM_index)
{
	u8 Address;
	if(CGRAM_index < 8)
	{
		Address = 8 * CGRAM_index;
		SET_BIT(Address,6);
		HAL_LCD_SendCommand(Address);
		for(u8 i = 0; i < 7; i++)
		{
			HAL_LCD_WriteData(Pattern[i]);
		}
		HOME_POS;
		_delay_ms(2);
	}
}
