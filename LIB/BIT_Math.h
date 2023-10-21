/*
		Author			: 	Mostafa Zaghlol
		Date			:	20/10/2023
		Version			:	V 1.0
		Description		:	Bit math library
*/


#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(REG,BIT) 					(REG) |= (1 << (BIT))
#define CLEAR_BIT(REG,BIT) 					(REG) &=~(1 << (BIT))
#define TOGG_BIT(REG,BIT) 					(REG) ^= (1 << (BIT))
#define GET_BIT(REG,BIT) 					(((REG) >> (BIT)) & 1)
#define SET_BYTE(REG,VAL) 					(REG) = (VAL)
#define CONC_BYTE(B7,B6,B5,B4,B3,B2,B1,B0) 	(0B##B7##B6##B5##B4##B3##B2##B1##B0)


#endif