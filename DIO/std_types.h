/*
 * std_types.h
 *
 * Created: 5/24/2024 8:20:51 PM
 *  Author: Reem Raouf
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdint.h>

typedef unsigned char         uint8;          /*           0 .. 255              */
typedef unsigned short        uint16;         /*           0 .. 65535            */
typedef unsigned long         uint32;

typedef float float32;
typedef double float64;

typedef enum {
	FALSE,
	TRUE
} boolean;

#define NULL_PTR ((void*)0)


#endif /* STD_TYPES_H_ */