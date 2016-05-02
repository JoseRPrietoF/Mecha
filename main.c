/*----------------------------------------------------------------------------
  * Name:    main.c   Proyecto hexapodo
  ******************************************************************************
  * @file    main.c 
  * @author  Juan Jose Serrano Martin , Didac Bosch, Jose R. Prieto
  * @version V0.0.0
  * @date    Marzo-2015
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *  Programa de prueba DSM  ETS. Ingenieros Informaticos Valencia
  *  IUI ITACA  - UPV
  *  Programa para controlar un hexapodo
	*  Usando libreria CMSIS de STM  (GPIO)
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "Func_inicio_Servos.h" 
#include "LCD.h" 
#include "Funciones_Otras.h" 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
// GPIO_InitTypeDef        GPIO_InitStructure;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#define SEC 10000000

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{

	//uint8_t dc = 0;
	uint8_t min = 11;
	//uint32_t max = 47;
	uint8_t angulo = 3;
// uint16_t var_luces= 0x0001, count; 

  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */

 
//	/* GPIOC Periph clock enable  */
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

//  /* Configure PC7 a PC0 in output pushpull mode para trabajar como un port de 8 bits */  
//  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);   

	Init_TIMER2_PWM_GPIOA();
	Init_TIMER3_PWM_GPIOC(); 
 

	Init_TIMER2_PWM_Signals(); 	
	Init_TIMER3_PWM_Signals(); 

	// Inicializa port A parte A8-A15 para manejar display 7 segmentos
	Inicia_PortA_display_7SEGM();
	
	//Inicializa pines A12 y A13 a "1s" para que no melesten.
	GPIO_SetBits(GPIOA, GPIO_Pin_12 );
	GPIO_SetBits(GPIOA, GPIO_Pin_13 );
	
	// Visualiza 0 en dispaly 7 segmentos.
	
	display(00);
  Delay (4*SEC); 
	initMov();
	
  while (1)
  {
		//display(0);

		
		//Delay (2*SEC);
		//display(90);

		andar_Adelante();
		//Delay (2*SEC);

		//

    /* prueba coche fantastico */
//    count = 0;
//	while (count < 7) {
//	
//		Delay (5);
//		var_luces = var_luces << 1;
//		GPIO_Write(GPIOA, var_luces);
//		count ++;
//	}
//	count =0;
//	while (count < 7) {
//	
//		
//		var_luces = var_luces >> 1;
//		GPIO_Write(GPIOA, var_luces);
//		count ++;
//	}
	
  }
}


#ifdef  USE_FULL_ASSERT
/*
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/




