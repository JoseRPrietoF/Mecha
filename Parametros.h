/**
  ******************************************************************************
  * @file    Funciones.h
  * @author  Iván Piquer Mora, Salvador Balaguer Trull, Adrián Albelda Copete y Pablo Burches García.
  * @date    Enero 2016.
  * @brief   Agrupacion de la declaracion de todas las funciones a utilizar en el programa principal.
	
  ******************************************************************************
*/ 


/* Pines, puerto, reloj, grupo ADC, canal y periodo de muestreo del ADC */

#define ADC_PORT GPIOB											/*!< Puerto correspondiente al ADC */

#define ADC_PIN GPIO_Pin_1									/*!< Pin de conexionado del ADC */

#define ADC_PERIPH_CLK RCC_AHBPeriph_GPIOB	/*!< RCC del puerto correspondiente al ADC */
#define ADC_CLK RCC_AHBPeriph_ADC34					/*!< RCC del ADC */

#define ADC_GROUP ADC3											/*!< Grupo del ADC */
#define ADC_CHANNEL ADC_Channel_1						/*!< Canal del ADC */
#define ADC_ST ADC_SampleTime_7Cycles5			/*!< Período de muestreo del ADC */


/* Parámetros de las señales PWM */

#define PORT_LADO_DER GPIOC									/*!< Puerto correspondiente al ADC */
#define PORT_LADO_IZQ GPIOD									/*!< Puerto correspondiente al ADC */
#define PORT_CABEZA GPIOA

#define PWM_TIM4_RCC RCC_AHBPeriph_GPIOD
#define PWM_TIM3_RCC RCC_AHBPeriph_GPIOC
#define PWM_TIM2_RCC RCC_AHBPeriph_GPIOA

#define TIMER_LADO_DER TIM3
#define TIMER_LADO_IZQ TIM4
#define TIMER_CABEZA TIM2

#define PIN_PATA_DEL_DER GPIO_Pin_7
#define PS_PATA_DEL_DER GPIO_PinSource7
#define PIN_PATA_DEL_IZQ GPIO_Pin_12
#define PS_PATA_DEL_IZQ GPIO_PinSource12
#define PIN_PATA_TRAS_DER GPIO_Pin_9
#define PS_PATA_TRAS_DER GPIO_PinSource9
#define PIN_PATA_TRAS_IZQ GPIO_Pin_14
#define PS_PATA_TRAS_IZQ GPIO_PinSource14

#define PIN_PIE_DEL_DER GPIO_Pin_6
#define PS_PIE_DEL_DER GPIO_PinSource6
#define PIN_PIE_DEL_IZQ GPIO_Pin_13
#define PS_PIE_DEL_IZQ GPIO_PinSource13
#define PIN_PIE_TRAS_DER GPIO_Pin_8
#define PS_PIE_TRAS_DER GPIO_PinSource8
#define PIN_PIE_TRAS_IZQ GPIO_Pin_15
#define PS_PIE_TRAS_IZQ GPIO_PinSource15

#define PIN_MED_DIST GPIO_Pin_1
#define PS_MED_DIST GPIO_PinSource1



#define ADC_PIN GPIO_Pin_1									/*!< Pin de conexionado del ADC */

#define ADC_PERIPH_CLK RCC_AHBPeriph_GPIOB	/*!< RCC del puerto correspondiente al ADC */
#define ADC_CLK RCC_AHBPeriph_ADC34					/*!< RCC del ADC */

#define ADC_GROUP ADC3											/*!< Grupo del ADC */
#define ADC_CHANNEL ADC_Channel_1						/*!< Canal del ADC */
#define ADC_ST ADC_SampleTime_7Cycles5			/*!< Período de muestreo del ADC */


/* Variable distancia límite */

#define DISTANCIA_LIMITE 1182								/* 22.85 cm */

/* Posiciones preestablecidas para cada uno de los servos */

/* Pata delantera derecha */
#define PATA_DEL_DER_delante 18
#define PATA_DEL_DER_reposo 30
#define PATA_DEL_DER_detras 40

/* Pata delantera izquierda */
#define PATA_DEL_IZQ_delante 38
#define PATA_DEL_IZQ_reposo 30
#define PATA_DEL_IZQ_detras 20

/* Pata trasera derecha */
#define PATA_TRAS_DER_delante 18
#define PATA_TRAS_DER_reposo 30
#define PATA_TRAS_DER_detras 40

/* Pata trasera izquierda */
#define PATA_TRAS_IZQ_delante 38
#define PATA_TRAS_IZQ_reposo 30
#define PATA_TRAS_IZQ_detras 20

/* Pie delantero derecho */
#define PIE_DEL_DER_arriba 20
#define PIE_DEL_DER_abajo 14

/* Pie delantero izquierdo */
#define PIE_DEL_IZQ_arriba 20
#define PIE_DEL_IZQ_abajo 14

/* Pie trasero derecho */
#define PIE_TRAS_DER_arriba 20
#define PIE_TRAS_DER_abajo 14

/* Pie trasero izquierdo */
#define PIE_TRAS_IZQ_arriba 20
#define PIE_TRAS_IZQ_abajo 14

/* Cabeza (Medida distancia) */
#define MED_DIST_derecha 42
#define MED_DIST_centro 32
#define MED_DIST_izquierda 22

