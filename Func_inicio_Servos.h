/**
  ******************************************************************************
  * @file    Func_inicio_Servos.h
  * @author  JJ.Serrano Martin.
  * @date   Marzo 2016.
  * @brief   Agrupacion de todas las funciones a utilizar con Pines y Timers
	* 					para manejar los servos.
  ******************************************************************************
*/

/* ------Includes --------*/

#include "main.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_tim.h"

/* -------Parametros modificables del programa----------- */

/**
  * @}
  */

void Delay(uint32_t time); 

void Init_TIMER2_PWM_GPIOA(void);
void Init_TIMER3_PWM_GPIOC(void); 
//void Init_TIMER5_PWM_GPIOB(void); 

void Init_TIMER2_PWM_Signals(void); 	
void Init_TIMER3_PWM_Signals(void); 
//void Init_TIMER5_PWM_Signals(void);  

void Set_TIM3_CH1_PC6(uint32_t pulsos);
void Set_TIM3_CH2_PC7(uint32_t pulsos);
void Set_TIM3_CH3_PC8(uint32_t pulsos);
void Set_TIM3_CH4_PC9(uint32_t pulsos);

void Set_TIM2_CH1_PA0(uint32_t pulsos);
void Set_TIM2_CH2_PA1(uint32_t pulsos);
void Set_TIM2_CH3_PA2(uint32_t pulsos);
void Set_TIM2_CH4_PA3(uint32_t pulsos);

//void Set_TIM5_CH1_PB14(int pulsos);
//void Set_TIM5_CH2_PB15(int pulsos);
void Visu_Pos_servo_LCD(uint8_t pos_a_mostrar);
