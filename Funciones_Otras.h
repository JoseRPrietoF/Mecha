/**
  ******************************************************************************
  * @file    Funciones_otras.h
  * @author  Juan José Serrano M.
  * @date    Marzo 2016.
  * @brief   Funciones manejos otros perifericos display 7 segmentos,....
	
  ******************************************************************************
*/ 

/* ------Includes --------*/

#include "main.h"
#include "stm32f0xx_gpio.h"

#define PULSO_MIN_SERVO_TIM2 11
#define PULSO_MAX_SERVO_TIM2 47

#define PULSO_MIN_SERVO_TIM3 8
#define PULSO_MAX_SERVO_TIM3 32 // esta mal

/* -------Parametros modificables del programa----------- */


/** @addtogroup STM32F3_Discovery_Peripheral_Examples
  * @{
  */
	
	/** @addtogroup Proyecto_Quadropodo
  * @{
  */ 
	
/** @addtogroup Parametros_Modificables
  * @{
  */


/**
  * @}
  */

/**
  * @}
  */

void Inicia_PortA_display_7SEGM(void);
void Write_Port_Masked(GPIO_TypeDef* GPIOx, uint16_t valor_16, uint16_t mascara_16);
void display(uint8_t valor);
void mover_servo_angulo(uint8_t id_servo, uint8_t angulo);

