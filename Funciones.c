/**
  ******************************************************************************
  * @file    Funciones.c
  * @author  JJ.Serranoi Martin.
  * @date    Enero 2016.
  * @brief   Agrupacion de todas las funciones a utilizar en el programa principal.
	* 					Transpaso de funciones usadas en Cortex F3 SS.EE. Mast_Ing_Mecatronica.
  ******************************************************************************
*/ 

/** ---Includes ---------- */
	
#include "Funciones.h"
#include "Parametros.h"
#include "main.h"

extern enum Quad State;

uint16_t Distancia_izquierda = 0;
uint16_t Distancia_derecha = 0;
uint16_t Distancia_centro = 0;


/**
* @brief	  Retardo por software.
* @param	  Nada.
*	@returns	Nada.	
*/

void Delay(uint32_t time) {
	
		/* Bucle que se produce constantemente al llamar a la funcion hasta que el valor de la variable tiempo alcanza el valor 0 */
		while(time--);
	}


///**
//* @brief	  Configuracion inicialización del ADC3.
//* @param	  Nada. 
//*	@returns	Nada.
//*/

//void ADC3_Configuration(void) {
//	
//	ADC_InitTypeDef       ADC_InitStructure;
//  ADC_CommonInitTypeDef ADC_CommonInitStructure;
//  GPIO_InitTypeDef      GPIO_InitStructure;
//	
//	/* Configure the ADC clock */
//  RCC_ADCCLKConfig(RCC_ADC34PLLCLK_Div2);
//	
//  /* GPIOC Periph clock enable */
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
//  
//	/* Enable ADC3 clock */
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC34, ENABLE);
//  
// /* Configure ADC Channel1 as analog input */
//  GPIO_InitStructure.GPIO_Pin = ADC_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//  GPIO_Init(ADC_PORT, &GPIO_InitStructure);
//  
//  /* Initialize ADC structure */
//  ADC_StructInit(&ADC_InitStructure);
//  
//	/* Calibration procedure */  
//  ADC_VoltageRegulatorCmd(ADC3, ENABLE);
//  
//  /* Insert delay equal to 10 µs */
//  Delay(1000);
//  
//  ADC_SelectCalibrationMode(ADC3, ADC_CalibrationMode_Single);
//  ADC_StartCalibration(ADC3);
//  
//  while(ADC_GetCalibrationStatus(ADC3) != RESET );
// 
//  /* Configure the ADC3 in continous mode withe a resolutuion equal to 12 bits  */
//  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;                                                                    
//  ADC_CommonInitStructure.ADC_Clock = ADC_Clock_AsynClkMode;                    
//  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;             
//  ADC_CommonInitStructure.ADC_DMAMode = ADC_DMAMode_OneShot;                  
//  ADC_CommonInitStructure.ADC_TwoSamplingDelay = 0;          
//  ADC_CommonInit(ADC3, &ADC_CommonInitStructure);
//  
//  ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Enable;
//  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b; 
//  ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_0;         
//  ADC_InitStructure.ADC_ExternalTrigEventEdge = ADC_ExternalTrigEventEdge_None;
//  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
//  ADC_InitStructure.ADC_OverrunMode = ADC_OverrunMode_Disable;   
//  ADC_InitStructure.ADC_AutoInjMode = ADC_AutoInjec_Disable;  
//  ADC_InitStructure.ADC_NbrOfRegChannel = 1;
//  ADC_Init(ADC3, &ADC_InitStructure);
//  
//  /* ADC1 regular channel1 configuration */ 
//  ADC_RegularChannelConfig(ADC3, ADC_Channel_1, 1, ADC_SampleTime_7Cycles5);
//  
//  /* Enable ADCperipheral[PerIdx] */
//  ADC_Cmd(ADC3, ENABLE);     
//  
//  /* wait for ADRDY */
//  while(!ADC_GetFlagStatus(ADC3, ADC_FLAG_RDY));
//  
//  /* ADC1 regular Software Start Conv */ 
//  ADC_StartConversion(ADC3);
// 
//}


///**
//* @brief	  Lectura de la entrada analogica del pin PB1.
//* @param	  Nada.
//*	@returns	Nada.
//*/

//uint16_t Lectura_Distancia(void) {
//	
//		uint16_t  ADC3ConvertedValue = 0;
//		uint16_t ADC3ConvertedVoltage = 0;
//	
//		uint16_t i;
//		uint16_t ADC3ConvertedVoltage_1 = 0;
//	
//		for (i=0; i<16; i++)
//	
//		{
//	
//		/* Test EOC flag */
//    while(ADC_GetFlagStatus(ADC3, ADC_FLAG_EOC) == RESET);
//    
//    /* Get ADC1 converted data */
//    ADC3ConvertedValue =ADC_GetConversionValue(ADC3);
//    
//    /* Compute the voltage */
//    ADC3ConvertedVoltage = (ADC3ConvertedValue *3300)/0xFFF;
//			
//		ADC3ConvertedVoltage_1 = (ADC3ConvertedVoltage_1 + ADC3ConvertedVoltage);
//		Delay(1000);
//			
//		}
//		
//		ADC3ConvertedVoltage_1 = (ADC3ConvertedVoltage_1 / 16);
//		Delay(1000);
//		
//		return(ADC3ConvertedVoltage_1);
//}


///**
//* @brief	  Configuración de los pines, timers y puertos de las señales PWM.
//* @param	  Nada.
//*	@returns	Nada.	
//*/

void Init__TIMER2_PWM_GPIO(void) {

	GPIO_InitTypeDef GPIO_InitStructure_TIM2;

	// TIM2 PINES PCA1
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	GPIO_InitStructure_TIM2.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure_TIM2.GPIO_Mode = GPIO_Mode_AF; 			// Use the alternative pin functions.
	GPIO_InitStructure_TIM2.GPIO_Speed = GPIO_Speed_50MHz; 	// GPIO speed - has nothing to do with the timer timing.
	GPIO_InitStructure_TIM2.GPIO_OType = GPIO_OType_PP; 		// Push-pull.
	GPIO_InitStructure_TIM2.GPIO_PuPd = GPIO_PuPd_UP; 			// Setup pull-up resistors.
	GPIO_Init(GPIOA, &GPIO_InitStructure_TIM2);

	// Connect the timer output to the PD pins.
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_1); 		// TIM2_CH2 -> PA1.
}

void Init__TIMER3_PWM_GPIO(void) {

	GPIO_InitTypeDef GPIO_InitStructure_TIM3;

	// TIM3 PINES PC6-9.
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	GPIO_InitStructure_TIM3.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure_TIM3.GPIO_Mode = GPIO_Mode_AF; 																					// Use the alternative pin functions.
	GPIO_InitStructure_TIM3.GPIO_Speed = GPIO_Speed_50MHz; 																			// GPIO speed - has nothing to do with the timer timing.
	GPIO_InitStructure_TIM3.GPIO_OType = GPIO_OType_PP; 																				// Push-pull.
	GPIO_InitStructure_TIM3.GPIO_PuPd = GPIO_PuPd_UP; 																					// Setup pull-up resistors.
	GPIO_Init(GPIOC, &GPIO_InitStructure_TIM3);

	// Connect the timer output to the PC pins.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_2); 		// TIM3_CH1 -> PC6.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_2); 		// TIM3_CH2 -> PC7.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_2); 		// TIM3_CH3 -> PC8.
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_2); 		// TIM3_CH4 -> PC9.
}

void Init__TIMER4_PWM_GPIO(void) {

	GPIO_InitTypeDef GPIO_InitStructure_TIM4;
	
	// TIM4 PINES PD12-15.
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
	GPIO_InitStructure_TIM4.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure_TIM4.GPIO_Mode = GPIO_Mode_AF; 																					// Use the alternative pin functions.
	GPIO_InitStructure_TIM4.GPIO_Speed = GPIO_Speed_50MHz; 																			// GPIO speed - has nothing to do with the timer timing.
	GPIO_InitStructure_TIM4.GPIO_OType = GPIO_OType_PP; 																				// Push-pull.
	GPIO_InitStructure_TIM4.GPIO_PuPd = GPIO_PuPd_UP; 																					// Setup pull-up resistors.
	GPIO_Init(GPIOD, &GPIO_InitStructure_TIM4);

	// Connect the timer output to the PD pins.
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_2); 	// TIM4_CH1 -> PD12.
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_2); 	// TIM4_CH2 -> PD13.
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_2); 	// TIM4_CH3 -> PD14.
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_2); 	// TIM4_CH4 -> PD15.
}


/**
* @brief	  Inicialización de las señales PWM configuradas.
* @param	  Nada.
*	@returns	Nada	.
*/

	void Init_TIMER2_PWM_Signals(void) { 														// (Centro).
	
	/* Realización de la sincronización */
	int clk2 = 72e6; 																								/* 72 MHz (Reloj del sistema del Stm32f3-Discovery) */
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

	// Channel 2 (TIM2).
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

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

void Init_TIMER4_PWM_Signals(void) {															// (Izquierda).
	
	/* Realización de la sincronización */
	int clk4 = 72e6; 																								/* 72 MHz (Reloj del sistema del Stm32f3-Discovery) */
	int pwm_freq4 = 50;  																						/* Frecuencia de la señal PWM (50 Hz), que supone un período de 20 ms */
	int tim_freq4 = 20000; 																					/* Frecuencia del timer (20 KHz) */
	int prescaler4 = ((clk4 / tim_freq4) - 1);											/* Prescalado del sistema, que varía en función de la frecuencia del timer escogida */

	int pwm_period4 = (tim_freq4 / pwm_freq4);	 										/* Período en pulsos de reloj de la señal PWM */

	int ms_pulses4 = ((float)pwm_period4 / (1000.0 / pwm_freq4)); 	/* Número de pulsos por cada ms */

	/* Habilitar los periféricos de los timers */
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  				// Structure for TIM4.
	TIM_OCInitTypeDef  TIM_OCInitStructure;   							// Structure for TIM4 Output Compare.
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);		// Enable the TIM4 clock.

	// Structure for TIM Time Base.
	TIM_TimeBaseStructInit(& TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler4;
	TIM_TimeBaseStructure.TIM_Period = pwm_period4 - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* Inicializar los canales de los timers */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = ms_pulses4 * 2; 								/* Preestablecer el período de la señal PWM */
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 			/* Polaridad del pulso */
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;

	// Setup four channels

	// Channel 1 (TIM4).
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	// Channel 2 (TIM4).
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	// Channel 3 (TIM4).
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	// Channel 4 (TIM4).
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM4, DISABLE);
	TIM_CtrlPWMOutputs(TIM4, ENABLE);  
	TIM_Cmd(TIM4, ENABLE);           
}


void Set_MED_DIST(int pulsos){					// MD.
	TIM_SetCompare2(TIM2, pulsos);
}


void Set_PIE_DEL_DER(int pulsos){				// PDD.
	TIM_SetCompare1(TIM3, pulsos);
}

void Set_PATA_DEL_DER(int pulsos){			// PDD.
	TIM_SetCompare2(TIM3, pulsos);
}

void Set_PIE_TRAS_DER(int pulsos){			// PDT.
	TIM_SetCompare3(TIM3, pulsos);
}

void Set_PATA_TRAS_DER(int pulsos){			// PDT.
	TIM_SetCompare4(TIM3, pulsos);
}


void Set_PATA_DEL_IZQ(int pulsos){			// PID.
	TIM_SetCompare1(TIM4, pulsos);
}

void Set_PIE_DEL_IZQ(int pulsos){				// PID.
	TIM_SetCompare2(TIM4, pulsos);
}

void Set_PATA_TRAS_IZQ(int pulsos){			// PIT.
	TIM_SetCompare3(TIM4, pulsos);
}

void Set_PIE_TRAS_IZQ(int pulsos){			// PIT.
	TIM_SetCompare4(TIM4, pulsos);
}


/**
* @brief	  Inicialización de las secuencias de movimiento.
* @param	  Nada.
*	@returns	Nada.	
*/

void Reposo() {	
	
	Set_PATA_DEL_DER(PATA_DEL_DER_reposo);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_reposo);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_reposo);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_reposo);
	Delay(8000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro );
	Delay(8000000);
	
}

void Adelante() {
	
	/* PASO 1 */
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_detras);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_delante);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro );	
	Delay(2000000);
	
	/* PASO 2 */
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Set_PATA_TRAS_DER(PATA_DEL_DER_delante);
	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_detras);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_arriba);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro );	
	Delay(2000000);
	
	Distancia_centro = Lectura_Distancia();
	
	if (Distancia_centro > DISTANCIA_LIMITE){
		State = atras;
		return;
	}
	else {
		State = adelante;
		return;
	}
	
	/* PASO 3 */
//	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
//	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
//	Set_PATA_TRAS_DER(PATA_DEL_DER_delante);
//	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_detras);
//	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 4 */
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Set_PATA_TRAS_DER(PATA_DEL_DER_detras);
	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_delante);
	Delay(5000000);
	
//	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
//	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
//	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
//	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
//	Set_MED_DIST(MED_DIST_centro);	
//	Delay(2000000);
	
	
	Distancia_centro = Lectura_Distancia();
	
	if (Distancia_centro > DISTANCIA_LIMITE){
		State = atras;
		return;
	}
	else {
		State = adelante;
		return;
	}
	
}

void Atras() {
	
	/* PASO 1 */
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_delante);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_detras);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro );	
	Delay(2000000);
	
	/* PASO 2 */
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_detras);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_delante);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_arriba);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_arriba);
	Set_MED_DIST(MED_DIST_centro );	
	Delay(2000000);
	
	/* PASO 3 */
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Set_PATA_TRAS_DER(PATA_DEL_DER_delante);
	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_detras);
	Delay(5000000);
	
//	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
//	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
//	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
//	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
//	Set_MED_DIST(MED_DIST_centro);	
//	Delay(2000000);
	
	/* PASO 4 */
//	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
//	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
//	Set_PATA_TRAS_DER(PATA_DEL_DER_delante);
//	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_detras);
//	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
}

void Izquierda() {
	
	/* PASO 1 */
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_detras);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_detras);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 2 */
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_delante);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_delante);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 3 */
//	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
//	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
//	Set_PATA_TRAS_DER(PATA_TRAS_DER_delante);
//	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_delante);
//	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_arriba);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_arriba);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 4 */
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_detras);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_detras);
	Delay(5000000);
	
//	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
//	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
//	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
//	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
//	Set_MED_DIST(MED_DIST_centro);	
//	Delay(2000000);

}

void Derecha() {
	
	/* PASO 1 */
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_delante);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_delante);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 2 */
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_detras);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_detras);
	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 3 */
//	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
//	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
//	Set_PATA_TRAS_DER(PATA_TRAS_DER_detras);
//	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_detras);
//	Delay(5000000);
	
	Set_PIE_DEL_DER(PIE_DEL_DER_arriba);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Set_PIE_TRAS_DER(PIE_TRAS_DER_abajo);
	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_arriba);
	Set_MED_DIST(MED_DIST_centro);	
	Delay(2000000);
	
	/* PASO 4 */
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Set_PATA_TRAS_DER(PATA_TRAS_DER_delante);
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_delante);
	Delay(5000000);
	
//	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
//	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
//	Set_PIE_TRAS_DER(PIE_TRAS_DER_arriba);
//	Set_PIE_TRAS_IZQ(PIE_TRAS_IZQ_abajo);
//	Set_MED_DIST(MED_DIST_centro);	
//	Delay(2000000);

}

void Mirar() {
	
	Set_MED_DIST(MED_DIST_derecha);
	Delay(5000000);
	Distancia_derecha = Lectura_Distancia();
	
	Set_MED_DIST(MED_DIST_izquierda);
	Delay(5000000);
	Distancia_izquierda = Lectura_Distancia();	
	
	if(Distancia_derecha > Distancia_izquierda) {
		State = izquierda;		
	}
	else{
		State = derecha;
	}
	
}

