/**
  ******************************************************************************
  * @file    Func_inicio_Servos.c
  * @author  JJ.Serranoi Martin.
  * @date    Marzo 2016.
  * @brief   Agrupacion de todas las funciones a utilizar en el programa principal.
	* 					Transpaso de funciones usadas en Cortex F3 SS.EE. Mast_Ing_Mecatronica.
  ******************************************************************************
*/ 

/** ---Includes ---------- */
	
#include "Func_inicio_Servos.h"
#include "main.h"
#include "LCD.h"

/**
* @brief	  Retardo por software.
* @param	  Nada.
*	@returns	Nada.	
*/

void Delay(uint32_t time) {
	
		/* Bucle que se produce constantemente al llamar a la funcion hasta que el valor de la variable tiempo alcanza el valor 0 */
		while(time--);
	}

/**
* @brief	Configuración de los pines Port A usados para TIM2
*			como salidas PWM manejo de los servos. TIM2 PINES PA0 a PA3
* @param	Ninguno.
* @returns 	Nada.	
*/
void Init_TIMER2_PWM_GPIOA(void) {

	GPIO_InitTypeDef GPIO_InitStructure_TIM2;

	// TIM2 PINES PA0 a PA3
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	GPIO_InitStructure_TIM2.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure_TIM2.GPIO_Mode = GPIO_Mode_AF; 		// Use the alternative pin functions.
	GPIO_InitStructure_TIM2.GPIO_Speed = GPIO_Speed_10MHz; 	// GPIO speed - has nothing to do with the timer timing.
	GPIO_InitStructure_TIM2.GPIO_OType = GPIO_OType_PP; 	// Push-pull.
	GPIO_InitStructure_TIM2.GPIO_PuPd = GPIO_PuPd_UP; 		// Setup pull-up resistors.
	GPIO_Init(GPIOA, &GPIO_InitStructure_TIM2);

	// Connect the timer output to the PD pins.
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_2); // TIM2_CH1 -> PA0.
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_2); // TIM2_CH2 -> PA1.
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_2); // TIM2_CH3 -> PA2.
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_2); // TIM2_CH4 -> PA3.
	
}

/**
* @brief	Configuración de los pines Port C usados para TIM3
*			como salidas PWM manejo de los servos. TIM3 PINES PC6-9.
* @param	Ninguno.
* @returns 	Nada.	
*/
void Init_TIMER3_PWM_GPIOC(void) {

	GPIO_InitTypeDef GPIO_InitStructure_TIM3;

	// TIM3 PINES PC6-9.
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	GPIO_InitStructure_TIM3.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure_TIM3.GPIO_Mode = GPIO_Mode_AF; 																					// Use the alternative pin functions.
	GPIO_InitStructure_TIM3.GPIO_Speed = GPIO_Speed_10MHz; 																			// GPIO speed - has nothing to do with the timer timing.
	GPIO_InitStructure_TIM3.GPIO_OType = GPIO_OType_PP; 																				// Push-pull.
	GPIO_InitStructure_TIM3.GPIO_PuPd = GPIO_PuPd_UP; 																					// Setup pull-up resistors.
	GPIO_Init(GPIOC, &GPIO_InitStructure_TIM3);

	// Connect the timer output to the PC pins.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_1); 	// TIM3_CH1 -> PC6.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_1); 	// TIM3_CH2 -> PC7.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_1); 	// TIM3_CH3 -> PC8.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_1); 	// TIM3_CH4 -> PC9.
}

///**
//* @brief	Configuración de los pines Port B usados para TIM5
//*			como salidas PWM manejo de los servos. TIM5 PINES PB14-PB15.
//* @param	Ninguno.
//* @returns 	Nada.	
//*/
//void Init_TIMER5_PWM_GPIOB(void) {

//	GPIO_InitTypeDef GPIO_InitStructure_TIM5;
//	
//	// TIM5 PINES PB14-PB15.
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
//	GPIO_InitStructure_TIM5.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
//	GPIO_InitStructure_TIM5.GPIO_Mode = GPIO_Mode_AF; 																					// Use the alternative pin functions.
//	GPIO_InitStructure_TIM5.GPIO_Speed = GPIO_Speed_10MHz; 																			// GPIO speed - has nothing to do with the timer timing.
//	GPIO_InitStructure_TIM5.GPIO_OType = GPIO_OType_PP; 																				// Push-pull.
//	GPIO_InitStructure_TIM5.GPIO_PuPd = GPIO_PuPd_UP; 																					// Setup pull-up resistors.
//	GPIO_Init(GPIOB, &GPIO_InitStructure_TIM5);

//	// Connect the timer output to the PB pins.
//	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_1); 	// TIM5_CH1 -> PB14.
//	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_1); 	// TIM5_CH2 -> PB15.
//	}

/**
* @brief	  Inicialización de las señales PWM configuradas.
* @param	  Nada.
*	@returns	Nada	.
*/
	void Init_TIMER2_PWM_Signals(void) { 														// (Centro).
	
	/* Realización de la sincronización */
	int clk2 = 48e6; 																								/* 48 MHz (Reloj del sistema del Stm32f0-Discovery) */
	int pwm_freq2 = 50;  																						/* Frecuencia de la señal PWM (50 Hz), que supone un período de 20 ms */
	int tim_freq2 = 20000; 																					/* Frecuencia del timer (20 KHz) */
	int prescaler2 = ((clk2 / tim_freq2) - 1);											/* Prescalado del sistema, que varía en función de la frecuencia del timer escogida */

	int pwm_period2 = (tim_freq2 / pwm_freq2);	 										/* Período en pulsos de reloj de la señal PWM */

	int ms_pulses2 = ((float)pwm_period2 / (1000.0 / pwm_freq2)); 	/* Número de pulsos por cada ms */

	/* Habilitar los periféricos de los timers */
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  				// Structure for TIM2.
	TIM_OCInitTypeDef  TIM_OCInitStructure;   							// Structure for TIM2 Output Compare.
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);		// Enable the TIM2 clock.
	
	// Structure for TIM Time Base.
	TIM_TimeBaseStructInit(& TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler2;
	TIM_TimeBaseStructure.TIM_Period = pwm_period2- 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	/* Inicializar los canales de los timers */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = ms_pulses2 * 2; 								/* Preestablecer el período de la señal PWM */
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 			/* Polaridad del pulso */
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;

	// Setup four channels.

	// Channel 1 (TIM2).
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

	// Channel 2 (TIM2).
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

	// Channel 3 (TIM2).
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

	// Channel 4 (TIM2).
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM2, DISABLE);
	TIM_CtrlPWMOutputs(TIM2, ENABLE);  
	TIM_Cmd(TIM2, ENABLE);           

}

void Init_TIMER3_PWM_Signals(void) {															// (Derecha).
	
	/* Realización de la sincronización */
	int clk3 = 72e6; 																								/* 72 MHz (Reloj del sistema del Stm32f3-Discovery) */
	int pwm_freq3 = 50;  																						/* Frecuencia de la señal PWM (50 Hz), que supone un período de 20 ms */
	int tim_freq3 = 20000; 																					/* Frecuencia del timer (20 KHz) */
	int prescaler3 = ((clk3 / tim_freq3) - 1);											/* Prescalado del sistema, que varía en función de la frecuencia del timer escogida */

	int pwm_period3 = (tim_freq3 / pwm_freq3);	 										/* Período en pulsos de reloj de la señal PWM */

	int ms_pulses3 = ((float)pwm_period3 / (1000.0 / pwm_freq3)); 	/* Número de pulsos por cada ms */

	/* Habilitar los periféricos de los timers */
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  				// Structure for TIM3.
	TIM_OCInitTypeDef  TIM_OCInitStructure;   							// Structure for TIM3 Output Compare.
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);		// Enable the TIM3 clock.

	
	// Structure for TIM Time Base.
	TIM_TimeBaseStructInit(& TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler3;
	TIM_TimeBaseStructure.TIM_Period = pwm_period3 - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* Inicializar los canales de los timers */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = ms_pulses3 * 2; 								/* Preestablecer el período de la señal PWM */
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 			/* Polaridad del pulso */
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;

	// Setup four channels

	// Channel 1 (TIM3).
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

	// Channel 2 (TIM3).
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

	// Channel 3 (TIM3).
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

	// Channel 4 (TIM3).
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM3, DISABLE);
	TIM_CtrlPWMOutputs(TIM3, ENABLE);  
	TIM_Cmd(TIM3, ENABLE);           
}

//void Init_TIMER5_PWM_Signals(void) {															// (Izquierda).
//	
//	/* Realización de la sincronización */
//	int clk4 = 72e6; 																								/* 72 MHz (Reloj del sistema del Stm32f3-Discovery) */
//	int pwm_freq4 = 50;  																						/* Frecuencia de la señal PWM (50 Hz), que supone un período de 20 ms */
//	int tim_freq4 = 20000; 																					/* Frecuencia del timer (20 KHz) */
//	int prescaler4 = ((clk4 / tim_freq4) - 1);											/* Prescalado del sistema, que varía en función de la frecuencia del timer escogida */

//	int pwm_period4 = (tim_freq4 / pwm_freq4);	 										/* Período en pulsos de reloj de la señal PWM */

//	int ms_pulses4 = ((float)pwm_period4 / (1000.0 / pwm_freq4)); 	/* Número de pulsos por cada ms */

//	/* Habilitar los periféricos de los timers */
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  				// Structure for TIM5.
//	TIM_OCInitTypeDef  TIM_OCInitStructure;   							// Structure for TIM5 Output Compare.
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);		// Enable the TIM5 clock.

//	// Structure for TIM Time Base.
//	TIM_TimeBaseStructInit(& TIM_TimeBaseStructure);
//	TIM_TimeBaseStructure.TIM_Prescaler = prescaler4;
//	TIM_TimeBaseStructure.TIM_Period = pwm_period4 - 1;
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

//	/* Inicializar los canales de los timers */
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = ms_pulses4 * 2; 								/* Preestablecer el período de la señal PWM */
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 			/* Polaridad del pulso */
//	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;

//	// Setup four channels

//	// Channel 1 (TIM5).
//	TIM_OC1Init(TIM5, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);

//	// Channel 2 (TIM5).
//	TIM_OC2Init(TIM5, &TIM_OCInitStructure);
//	TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);

//	TIM_ARRPreloadConfig(TIM5, DISABLE);
//	TIM_CtrlPWMOutputs(TIM5, ENABLE);  
//	TIM_Cmd(TIM5, ENABLE);           
//}

// llamadas para cambiar posición en servos TIM3

void Set_TIM3_CH1_PC6(uint32_t pulsos){				
	TIM_SetCompare1(TIM3, pulsos);
}

void Set_TIM3_CH2_PC7(uint32_t pulsos){			
	TIM_SetCompare2(TIM3, pulsos);
}

void Set_TIM3_CH3_PC8(uint32_t pulsos){			
	TIM_SetCompare3(TIM3, pulsos);
}

void Set_TIM3_CH4_PC9(uint32_t pulsos){			
	TIM_SetCompare4(TIM3, pulsos);
}

// llamadas para cambiar posición en servos TIM2
void Set_TIM2_CH1_PA0(uint32_t pulsos){				 
	TIM_SetCompare1(TIM2, pulsos);
}

void Set_TIM2_CH2_PA1(uint32_t pulsos){			 
	TIM_SetCompare2(TIM2, pulsos);
}

void Set_TIM2_CH3_PA2(uint32_t pulsos){			 
	TIM_SetCompare3(TIM2, pulsos);
}

void Set_TIM2_CH4_PA3(uint32_t pulsos){			 
	TIM_SetCompare4(TIM2, pulsos);
}

//// llamadas para cambiar posición en servos TIM5
//void Set_TIM5_CH1_PB14(int pulsos){			 
//	TIM_SetCompare1(TIM5, pulsos);
//}

//void Set_TIM5_CH2_PB15(int pulsos){				 
//	TIM_SetCompare2(TIM5, pulsos);
//}

void Visu_Pos_servo_LCD(uint8_t pos_a_mostrar)
{

  uint8_t text[16];
  sprintf((char*)text,"Pos_Nueva =%.2d ",pos_a_mostrar);           // Mostra x pantalla el valor de la variable mV
  // Set the LCD 
  lcd_gotoxy(1,1);
	lcd_escribe(" MANEJO SERVOS"); 
	Delay(200000); 
	lcd_gotoxy(1,2);
	lcd_escribe(text);
}


