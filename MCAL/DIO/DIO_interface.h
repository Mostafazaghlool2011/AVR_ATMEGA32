/*
		Author			: 	Mostafa Zaghlol
		Date			:	20/10/2023
		Version			:	V 1.0
		Description		:	Standard types library
*/


#ifndef STD_TYPES_H
#define STD_TYPES_H


void DIO_voidSetPortDirection		(u8 Copy_u8PortID ,u8 Copy_u8PortDif);
void DIO_voidSetPortValue			(u8 Copy_u8PortID ,u8 Copy_u8PortValue);
void DIO_voidSetPinDirection		(u8 Copy_u8PortID ,u8 Copy_u8PinId,u8 Copy_u8PinDir);
void DIO_voidSetPinValue			(u8 Copy_u8PortID ,u8 Copy_u8PinId,u8 Copy_u8PinValue);
void DIO_u8GetPinValue				(u8 Copy_u8PortID ,u8 Copy_u8PinId);
void DIO_voidTogglePin				(u8 Copy_u8PortID ,u8 Copy_u8PinId);


#endif