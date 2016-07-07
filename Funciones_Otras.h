/**
  ******************************************************************************
  * @file    Funciones_otras.h
  * @author  Dídac Bosch & Jose R. Prieto
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
#define PULSO_MAX_SERVO_TIM3 32

#define FD1 8
#define FD2 9
#define FI1 6
#define FI2 7
#define TD1 2
#define TD2 3
#define TI1 0
#define TI2 1

#define SEC 10000000

#define levantar 20



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

// movimiento
void initMov();
void andar_Adelante();
void paso_AdelanteFITD();
void paso_AdelanteFDTI();
void girar(uint8_t grados);

