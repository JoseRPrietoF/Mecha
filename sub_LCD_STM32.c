/*----------------------------------------------------------------------------
  * Name:   sub_LCD_STM32.c   Subrutinas Dispaly LCD dos lineas de 16 caracteres.
  ******************************************************************************
  * @file    main.c 
  * @author  Juan Jose Serrano Martin
  * @version V0.0.0
  * @date    10-Octubre-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *  Programa de prueba DSM  ETS. Ingenieros Informaticos Valencia
  *  IUI ITACA  - UPV
  *  Programa  trabajo     
  *  como un puerto de 8 bits.   Usando libreria CMSIS de STM  (GPIO)
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
/* #include "stm32f0xx_gpio.h" */
/* #include "stm32f0xx_rcc.h"  */
/* #include "stm32f0xx_conf.h"  */

/** @addtogroup STM32F0_Discovery_Practicas DSM 2012_13 ETSIInf_UPV
  * @{
  */

/** @addtogroup Manejo Display LCD dos lineas
  * @{
  */


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef        GPIO_InitStructure;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*----------------------------------------------------------------------------
  delay por software 
 *------------------------------------------------------------------------*/
void Delay (uint32_t retardo) {                                              
  uint32_t i, j;

 	for (i = 0; i < retardo; i++){
     for (j = 0; j < 100000; j++){};
   }
}



{

uint16_t var_luces= 0x0001, count; 

  
 
	/* GPIOC Periph clock enable  */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

  /* Configure PC7 a PC0 in output pushpull mode para trabajar como un port de 8 bits */  
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);   

  void LCD_wait (void)
  {
    uchar d;  
	lcd_port &= 0x000F;
    GPIO_Write(GPIOC, lcd_port);
	
	lcd_port |= 0x002F;
    GPIO_Write(GPIOC, lcd_port);
	
	do
	{
		lcd_port |= 0x0010;
		GPIO_Write(GPIOC, lcd_port);
	
		d = GPIO_read(GPIOC);
		lcd_port &= 0x000F;
		GPIO_Write(GPIOC, lcd_port);
		
		lcd_port &= 0x000F;
		GPIO_Write(GPIOC, lcd_port);
	
		lcd_port &= 0x000F;
		GPIO_Write(GPIOC, lcd_port);
	
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