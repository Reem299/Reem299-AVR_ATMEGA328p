/*
 * math.h
 *
 * Created: 5/2/2024 2:31:22 PM
 *  Author: Reem Raouf
 */ 


#ifndef MATH_H_
#define MATH_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT)     (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT)    (REG&=~(1<<BIT))

/* get a certain bit of any register */
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

#define  TOG_BIT(REG,BIT)	REG^=(1<<BIT)


#endif /* MATH_H_ */