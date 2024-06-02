/*
 * ADC.h
 *
 * Created: 5/24/2024 4:19:27 PM
 *  Author: Reem Raouf
 */ 


#ifndef ADC_H_
#define ADC_H_
//#include "std_types.h"

void ADC_init(void);

uint16 ADC_read(uint8_t ch);

#endif /* ADC_H_ */