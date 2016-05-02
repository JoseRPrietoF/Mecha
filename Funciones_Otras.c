//  JJSM
//  Funciones manejo display 7 segmentos y ADC
//
/*----------------------------------------------------------------------------


------------------------------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Funciones_Otras.h"
#include "stm32f0xx_adc.h"
#include "stm32f0xx_rcc.h"
#include "Func_inicio_Servos.h" 

//PC0 a PC5, PC10 y PC11  OUT  Display 8 Segmentos 2 numeros.
void Inicia_PortA_display_7SEGM(void){

  GPIO_InitTypeDef 		GPIO_InitStructureA7S;
  /* GPIOC Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  
  /* Configure bit 0 a 5 y 10 y 11 del port C in output pushpull: Para Display 7 segmentos */
  GPIO_InitStructureA7S.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_8 ;
  GPIO_InitStructureA7S.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructureA7S.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructureA7S.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructureA7S.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructureA7S);
}

//mascara_16: bits a considerar
void Write_Port_Masked(GPIO_TypeDef* GPIOx, uint16_t valor_16, uint16_t mascara_16) { 

	 uint16_t mascara1s_16, mascara0s_16 ;
	
   // mascara_16 son unos, hay que coger de val_16 los unos, hacemos que los dos sean unos.
   mascara1s_16 =  valor_16 & mascara_16; //  (unos en los dos)
   
   GPIO_SetBits(GPIOx, mascara1s_16);   //(a 1)mascara1s_16 bits a poner a uno.
   Delay(4); // aprox microseg 10
   // mascara_16 son unos, hay que coger de val_16 los ceros, hacemos la inversa de val_16,
   // entonces los ceros pasan a unos, y hacemos que los dos sean unos, para poner a cero.
   mascara0s_16 = ( ~ valor_16) & mascara_16; //  (inversa de valor y unos en los dos)
   
   GPIO_ResetBits(GPIOx, mascara0s_16);  //(a 1)mascara0s_16 bits a poner a cero.
	 Delay(4); // aprox microseg 10
}

void display(uint8_t valor)
{
	uint8_t unidades, decenas;
	uint16_t visu ;
  decenas = valor/10;
	unidades =valor%10;
	GPIO_SetBits(GPIOA, GPIO_Pin_14 );
	GPIO_SetBits(GPIOA, GPIO_Pin_15 );
	//Pone en BCD el valor de las unidades
	
	visu = (uint16_t) unidades ;
	visu = visu << 8;
	//Write_8Bits_portE_8_15(visu);
	//retardo(18000000);
	Write_Port_Masked(GPIOA, visu, 0x0F00);
	Delay(1800);
	//Write_4Bits_portC_0_3(visu);
	// produce un pulso a cero en bit 6 para visualizar unidades
	GPIO_ResetBits(GPIOA, GPIO_Pin_14 );
	Delay(1800);
	GPIO_SetBits(GPIOA, GPIO_Pin_14 );
	
	//Pone en BCD el valor de las decenas
	visu = (uint16_t)  decenas ;
	visu = visu << 8;
	//Write_8Bits_portE_8_15(visu);
	//retardo(18000000);
	Write_Port_Masked(GPIOA, visu, 0x0F00);
	Delay(1800);
	//oWrite_4Bits_portC_0_3(visu);
	// produce un pulso a cero en bit 7 para visualizar decenas
	GPIO_ResetBits(GPIOA, GPIO_Pin_15 );
	Delay(1800);
	GPIO_SetBits(GPIOA, GPIO_Pin_15 );
	
	}

void ADC1_Init(void)
{
	
	//__IO uint16_t  ADC1ConvertedValue = 0, ADC1Converted_mV = 0;
	ADC_InitTypeDef     ADC_InitStructureADC1;
	GPIO_InitTypeDef    GPIO_InitStructureC;
  /* GPIOC Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
  
  /* ADC1 Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
  
  /* Configure ADC Channel11 as analog input */
  GPIO_InitStructureC.GPIO_Pin = GPIO_Pin_1 ;
  GPIO_InitStructureC.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructureC.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_Init(GPIOC, &GPIO_InitStructureC);
  
  /* ADCs DeInit */  
  //ADC_DeInit(ADC1);
  
  /* Initialize ADC structure */
  ADC_StructInit(&ADC_InitStructureADC1);
  
  /* Configure the ADC1 in continous mode withe a resolutuion equal to 12 bits  */
  ADC_InitStructureADC1.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructureADC1.ADC_ContinuousConvMode = ENABLE; 
  ADC_InitStructureADC1.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructureADC1.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructureADC1.ADC_ScanDirection = ADC_ScanDirection_Upward;
  ADC_Init(ADC1, &ADC_InitStructureADC1); 
  
  /* Convert the ADC1 Channel 11 with 239.5 Cycles as sampling time */ 
  ADC_ChannelConfig(ADC1, ADC_Channel_11 , ADC_SampleTime_239_5Cycles);   

  /* ADC Calibration */
  ADC_GetCalibrationFactor(ADC1);
  
  /* Enable ADCperipheral[PerIdx] */
  ADC_Cmd(ADC1, ENABLE);     
  
  /* Wait the ADRDY falg */
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY)); 
  
  /* ADC1 regular Software Start Conv */ 
  ADC_StartOfConversion(ADC1);
}  

/**************************************************************************************/ 

// Pulsador PF9 UP, incrementar
// Uso función.
// if (Read_Pul_UP() == 0)																		
// {
// Pulsador apretado;																
// }
//uint8_t Read_Pulsad_USER(void)
//{
//	if(GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_9) == 0)			//is the pushbutton pressed (input = 0)      
//  {
//			retardo(9000);											//wait 10ms for debounce
//			if(GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_9) == 0)   //is the pushbutton still presed?
//				return 0;									    //true button push
//		  else
//				return 1;									    //false from contact bounce
//	}
//	return 1;
//}

/* fin funciones Otras *******/

/** El angulo debe rondar entre 0 y 180
*/

void mover_servo_angulo(uint8_t id_servo, uint8_t angulo)
{
	uint8_t dc_tim2 = angulo * 0.21 + PULSO_MIN_SERVO_TIM2;
	uint8_t dc_tim3 = angulo * 0.134 + PULSO_MIN_SERVO_TIM3;
	display(dc_tim3);
	if(angulo < 0 || angulo > 180) return;

	switch(id_servo){
		case 0:
			Set_TIM2_CH1_PA0(dc_tim2);
			break;
		
		case 1:
			Set_TIM2_CH2_PA1(dc_tim2);
			break;
		
		case 2:
			Set_TIM2_CH3_PA2(dc_tim2);
			break;
		
		case 3:
			Set_TIM2_CH4_PA3(dc_tim2);
			break;
		
		case 6:
			Set_TIM3_CH1_PC6(dc_tim3);
			break;
		
		case 7:
			Set_TIM3_CH2_PC7(dc_tim3);
			break;
		
		case 8:
			Set_TIM3_CH3_PC8(dc_tim3);
			break;
		
		case 9:
			Set_TIM3_CH4_PC9(dc_tim3);
			break;
	}
	
}

void initMov(){
	mover_servo_angulo(FI1,180); // esta al reves, seria 180
	mover_servo_angulo(TD1,0);
	mover_servo_angulo(FD1,180);
	mover_servo_angulo(TI1,0); // al reves
	
	mover_servo_angulo(TI2,0); 
	mover_servo_angulo(FD2,0);
	mover_servo_angulo(FI2,0); 
	mover_servo_angulo(TD2,0);
}
void andar_Adelante(){
	paso_AdelanteFITD();
	Delay(SEC * 0.75);
	paso_AdelanteFDTI();
	Delay(SEC * 0.75);
}
void paso_AdelanteFITD(){
	mover_servo_angulo(FD2,levantar);
	mover_servo_angulo(TI2,levantar);
	mover_servo_angulo(TD2,0);
	mover_servo_angulo(FI2,0);
	Delay(SEC * 0.25);
	mover_servo_angulo(FI1,0);// porque esta al reves
	mover_servo_angulo(TD1,180);
	mover_servo_angulo(TI1,180); // al reves 
	mover_servo_angulo(FD1,0);
}
void paso_AdelanteFDTI(){
	mover_servo_angulo(FD2,0);
	mover_servo_angulo(TI2,0);
	mover_servo_angulo(TD2,levantar);
	mover_servo_angulo(FI2,levantar);
	Delay(SEC * 0.25);
	mover_servo_angulo(FI1,180);// porque esta al reves
	mover_servo_angulo(TD1,0);
	mover_servo_angulo(TI1,0); // al reves 
	mover_servo_angulo(FD1,180);
	
	
}
