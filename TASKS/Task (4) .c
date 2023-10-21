/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Description		:	Task (4)
*/


#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "SEVEN_SEG_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"


void Initialize_System(void);


int main(void)
{
	Initialize_System();

	while(1)
	{
		s8 row = 3, col = 0;
		u8 rising = 1, falling = 0;
		while(col < COL_MAX)
		{
			HAL_LCD_WriteString((u8 *)"A", row, col);
			_delay_ms(200);
			HAL_LCD_SendCommand(0x01);

			col++;

			if(rising)
			{
				row--;
			}
			if(falling)
			{
				row++;
			}

			if(row < 0)
			{
				rising = 0;
				falling = 1;
				row = 1;
			}

			if(row > 3)
			{
				rising = 1;
				falling = 0;
				row = 2;
			}
		}
	}

}


void Initialize_System(void)
{
	HAL_LCD_Init();
}