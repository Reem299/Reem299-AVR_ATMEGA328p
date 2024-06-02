/*
 * math.h
 *
 * Created: 5/21/2024 11:22:31 AM
 *  Author: Reem Raouf
 */ 


#ifndef MATH_H_
#define MATH_H_
//reg=port ,,, bit=pin

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT)     (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT)    (REG&=~(1<<BIT))

/* get a certain bit of any register */
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

#define  TOG_BIT(REG,BIT)	REG^=(1<<BIT)




#endif /* MATH_H_ */