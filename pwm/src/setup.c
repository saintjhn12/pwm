#include "pwm.h"
void pwm_init(){ 
//SETTING MODE TIMER TO FAST PWM 10 BIT MODE
TCCR1B &=~(1<<WGM13);
TCCR1B |=(1<<WGM12);
TCCR1A|=(1<<WGM10)|(1<<WGM11);

//SETTING PWM MODE TO NON INVERTING MODE
TCCR1A |=(1<< COM1A1);
TCCR1A &=~(1<<COM1A0);
//setting prescaler of 64 bit(clk)
TCCR1B |= (1<<CS10)|(1<<CS11);
TCCR1B &=~(1<<CS12);
DDRD |= (1<<PD5);
}
void pwm_dutycycle(uint8_t dutycycle){
    OCR1A =dutycycle;
}