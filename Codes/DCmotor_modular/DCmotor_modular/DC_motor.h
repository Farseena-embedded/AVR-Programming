/*
 * dcmotor.h
 *
 * Created: 2/13/2026 12:33:57 PM
 *  Author: acer cc
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/* Function declarations */
void motor_init(void);     
void cw(uint16_t delay);
void ccw(uint16_t delay);
void stp(uint16_t delay);
void delay_ms(uint16_t ms);



#endif /* DCMOTOR_H_ */