/**
  ******************************************************************************
  * @file    Funciones.h
  * @author  Iván Piquer Mora, Salvador Balaguer Trull, Adrián Albelda Copete y Pablo Burches García.
  * @date    Enero 2016.
  * @brief   Agrupacion de la declaracion de todas las funciones a utilizar en el programa principal.
	
  ******************************************************************************
*/ 

/* ------Includes --------*/

#include "main.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_adc.h"
#include "stm32f30x_dac.h"
#include "stm32f30x_tim.h"

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


enum Quad {adelante, atras, mirar, derecha, izquierda};
extern enum Quad State;

void Delay(uint32_t time);

void ADC3_Configuration(void);

uint16_t Lectura_Distancia(void);

void Init__TIMER2_PWM_GPIO(void);
void Init__TIMER3_PWM_GPIO(void);
void Init__TIMER4_PWM_GPIO(void);

void Init_TIMER2_PWM_Signals(void);
void Init_TIMER3_PWM_Signals(void);
void Init_TIMER4_PWM_Signals(void);

void Set_PATA_DEL_DER(int pulsos);
void Set_PATA_DEL_IZQ(int pulsos);
void Set_PATA_TRAS_DER(int pulsos);
void Set_PATA_TRAS_IZQ(int pulsos);
void Set_PIE_DEL_DER(int pulsos);
void Set_PIE_DEL_IZQ(int pulsos);
void Set_PIE_TRAS_DER(int pulsos);
void Set_PIE_TRAS_IZQ(int pulsos);
void Set_MED_DIST(int pulsos);

void Reposo(void);
void Adelante(void);
void Atras(void);
void Izquierda(void);
void Derecha(void);
void Mirar(void);

