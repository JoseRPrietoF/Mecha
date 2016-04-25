/**
  ******************************************************************************
  * @file    Main.c
  * @author  Ivan Piquer Mora, Salvador Balaguer Trull, Adrián Albelda Copete y Pablo Burches García.
  * @date    Enero 2016.
  * @brief   Programa principal.
	******************************************************************************
*/ 

/* -----Includes ------- */

#include "Funciones.h"
#include "main.h"
#include "Parametros.h"

enum Quad State;

uint16_t i;
	
	
/** @addtogroup STM32F3_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup Proyecto_Quadropodo
  * @{
  */ 

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
	

int main(void)

{

	/* --------------------------------------Bucle sin fin--------------------------------------------------- */

ADC3_Configuration();
	
Init__TIMER2_PWM_GPIO();
Init__TIMER3_PWM_GPIO();
Init__TIMER4_PWM_GPIO();
	
Init_TIMER2_PWM_Signals();
Init_TIMER3_PWM_Signals();
Init_TIMER4_PWM_Signals();

State = 0;	
	
Reposo();
Delay(15000000);

/*
	
// Movimientos Servos.	
	
while (1){
	
	Set_PATA_DEL_DER(PATA_DEL_DER_delante);
	Delay(5000000);
	Set_PATA_DEL_DER(PATA_DEL_DER_reposo);
	Delay(5000000);
	Set_PATA_DEL_DER(PATA_DEL_DER_detras);
	Delay(5000000);
	
	Set_PATA_TRAS_DER(PATA_DEL_DER_delante);
	Delay(5000000);
	Set_PATA_TRAS_DER(PATA_DEL_DER_reposo);
	Delay(5000000);
	Set_PATA_TRAS_DER(PATA_DEL_DER_detras);
	Delay(5000000);
	
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_delante);
	Delay(5000000);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_reposo);
	Delay(5000000);
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_detras);
	Delay(5000000);
	
	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_delante);
	Delay(5000000);
	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_reposo);
	Delay(5000000);
	Set_PATA_TRAS_IZQ(PATA_DEL_IZQ_detras);
	Delay(5000000);
	
	
	Set_PATA_DEL_DER(PATA_DEL_DER_reposo);
	Delay(5000000);
	Set_PIE_DEL_DER(PIE_DEL_DER_arriba);
	Delay(5000000);
	Set_PIE_DEL_DER(PIE_DEL_DER_abajo);
	Delay(5000000);
	
	Set_PATA_TRAS_DER(PATA_DEL_DER_reposo);
	Delay(5000000);
	Set_PIE_TRAS_DER(PIE_DEL_DER_arriba);
	Delay(5000000);
	Set_PIE_TRAS_DER(PIE_DEL_DER_abajo);
	Delay(5000000);
	
	Set_PATA_DEL_IZQ(PATA_DEL_IZQ_reposo);
	Delay(5000000);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_arriba);
	Delay(5000000);
	Set_PIE_DEL_IZQ(PIE_DEL_IZQ_abajo);
	Delay(5000000);
	
	Set_PATA_TRAS_IZQ(PATA_TRAS_IZQ_reposo);
	Delay(5000000);
	Set_PIE_TRAS_IZQ(PIE_DEL_IZQ_arriba);
	Delay(5000000);
	Set_PIE_TRAS_IZQ(PIE_DEL_IZQ_abajo);
	Delay(5000000);
	
	
	Set_MED_DIST(MED_DIST_centro);
	Delay(5000000);
	Set_MED_DIST(MED_DIST_derecha);
	Delay(5000000);
	Set_MED_DIST(MED_DIST_centro);
	Delay(5000000);
	Set_MED_DIST(MED_DIST_izquierda);
	Delay(5000000);
	Set_MED_DIST(MED_DIST_centro);
	Delay(5000000);
	
}

*/

/*

// Movimientos Servos.	
	
while (1){
	
	Adelante();
	
	Reposo();
	Delay(10000000);
	
	Atras();
	
	Reposo();
	Delay(10000000);
	
	Izquierda();
	
	Reposo();
	Delay(10000000);
	
	Derecha();
	
	Reposo();
	Delay(10000000);

}

*/


while (1){
	
		switch (State) {
			
			case adelante:
				Adelante();
				break;
			
			case atras:
				for(i=0; i<1; i++){
				Atras();
				}
				State = mirar;
				break;
				
			case mirar:
				Mirar();
				break;
			
			case derecha:
				for(i=0; i<2; i++){
				Derecha();
				}
				State = adelante;
				break;
				
			case izquierda:
				for(i=0; i<2; i++){
				Izquierda();
				}
				State = adelante;
				break;
				
			default:
				break;
		}
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
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
