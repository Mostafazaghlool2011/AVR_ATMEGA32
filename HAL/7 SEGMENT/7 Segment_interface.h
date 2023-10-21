/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Version			:	V 1.0
		Description		:	7 Segment_interface.h
*/



#ifndef HAL_SEVEN_SEG_INTERFACE_H
#define HAL_SEVEN_SEG_INTERFACE_H


typedef enum COM_enum {COM1,COM2,COM3,COM4} COM_t;


void HAL_SEVEN_SEG_voidDisplay(COM_t Copy_COM_tCOMn,u8 Copy_u8BCDNumber);


#endif 