/*----------------------------------------------------------------------------
 * Name:    LCD.c
 * Purpose: Low level LCD functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the DSM  Lab (2012) practice developped tools.
 * Este codigo corresponde a una traduccion al STM32F0, del programa de manejo del  
 * LCD hecho para el 8051.
 *
 * Traducido por:  
 * 
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 DSM Course ETSIInf - UPV - DISCA - ITACA. All rights reserved.
 *----------------------------------------------------------------------------*/
/*  ----------  Conexión LCD modo 4 bits placa SS.EE. MIM 2015 ---------------*/
/*----------------------------------------------------------------------------*/      
/* Las conexiones del LCD quedan de la siguiente manera:  P_LCD:  GPIOB 0-7   */
/* PB7  RS Seleccion de registro 0=Control,  1= datos.                        */
/* PB5 R/W  Selec. de tipo operación 0=WR - escritura ,  1= RD - lectura.     */
/* PB4 E Enable. Operation enable signal. Falling edge triggered.             */
/*   Realmente actua como habilitación de operaciones                         */
/*   En la transición de E de "1" a "0" se activan las operaciones de WR y RD.*/
/*                                                                            */
/* PB3 Bit7 bus de datos del LCD - modo 4 bits.                               */
/* PB2 Bit6 bus de datos del LCD - modo 4 bits.                               */
/* PB1 Bit5 bus de datos del LCD - modo 4 bits.                               */
/* PB0 Bit4 bus de datos del LCD - modo 4 bits.                               */
/*----------------------------------------------------------------------------*/
#include "Func_inicio_servos.h"                                
#include "stm32f0xx_gpio.h"
#include "LCD.h"

#define P_LCD GPIOB  // acordarse de cambiar la func RCC_AHB...  si se cambia de puerto  

#define Enable_oper_lcd GPIO_Pin_0  // pin 1 Enable del bus del LCD   // ahora pin 0
#define R_W_lcd GPIO_Pin_1        // pin 10 R/W del bus del LCD  // ahora pin 1
#define RS_lcd GPIO_Pin_3           // pin 11 RS del bus del LCD  // ahora pin 3
#define busLCD_4_bits  0x00F0       //  define bits 12 a 15  // ahora 4 a 7
// GPIO_InitTypeDef        GPIO_InitStructure;

/*-----------------------------------------------------------------------------
 *      LED_Init:  Initialize LEDs
 *
 * Parameters: (none)
 * Return:     (none)
 *----------------------------------------------------------------------------*/
/*
void LCD_Init (void) {

  // GPIOC Periph clock enable  
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  // Configure PC7 a PC0 in output pushpull mode para trabajar como un port de 8 bits   
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_2 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(P_LCD, &GPIO_InitStructure);   
     
}
*/
// PD0 a PD7 OUT  Display LCD de 2 Lineas
void LCD_Init(void){

  GPIO_InitTypeDef 		GPIO_InitStructureDLCD;
  /* GPIOD Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
  
  /* Configure bit 0 al 7 del port D in output pushpull: Para LCD de 2 lineas */
  GPIO_InitStructureDLCD.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_0 | GPIO_Pin_1 ;
  GPIO_InitStructureDLCD.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructureDLCD.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructureDLCD.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructureDLCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(P_LCD, &GPIO_InitStructureDLCD);
}
/*--------------------------------------------------------------------------*/
/*     Retardo por software          */
// prueba espera placa teev pequeña micro C6 de 48 pines
//  espera 1 --> 1,36 microseg
//  espera 2 --> 1,72 microseg
//  espera 10 --> 5,68 microseg
//  espera 20 --> 10,6 microseg
//  espera 50 --> 25,4 microseg  en discv0 > 4,5 microseg
//  espera 100 --> 50 microseg   en  discv0 > 8,6 microseg
//  espera 500 -->  248 microseg  en discv0 > 42 microseg
//  espera 5000 --> 2,46 mili-seg
//  espera 10000 --> 4,96 mili-seg   en discv0 12000 es 1 miliseg
 /*------------------------------------------------------------------------*/
/*
void retardo(uint32_t iret) 
{ 
    while(iret--); 
} 
*/

// programa oscilan las salida para prueba


void oscilar_salidas_lcd(void){
	uint32_t i;
	for (i=0;i<800000000;++i) {
		
	  GPIO_SetBits(P_LCD, GPIO_Pin_2);
	  Delay(10000);
	  GPIO_ResetBits(P_LCD, GPIO_Pin_2 );
	  Delay(10000);

/*	  GPIO_SetBits(P_LCD, GPIO_Pin_14 | GPIO_Pin_12 | GPIO_Pin_10 );
	  retardo(100);
	  GPIO_ResetBits(P_LCD, GPIO_Pin_14 | GPIO_Pin_12 | GPIO_Pin_10 );
	  retardo(100);  */
	}
	
}
	


//mascara_16: bits a considerar
void Write_port_masked(GPIO_TypeDef* GPIOx, uint16_t valor_16, uint16_t mascara_16) { 

	 uint16_t mascara1s_16, mascara0s_16 ;
	
   // mascara_16 son unos, hay que coger de val_16 los unos, hacemos que los dos sean unos.
   mascara1s_16 =  valor_16 & mascara_16; //  (unos en los dos)
   
   GPIO_SetBits(GPIOx, mascara1s_16);   //(a 1)mascara1s_16 bits a poner a uno.
   Delay(90); // aprox microseg 10
   // mascara_16 son unos, hay que coger de val_16 los ceros, hacemos la inversa de val_16,
   // entonces los ceros pasan a unos, y hacemos que los dos sean unos, para poner a cero.
   mascara0s_16 = ( ~ valor_16) & mascara_16; //  (inversa de valor y unos en los dos)
   
   GPIO_ResetBits(GPIOx, mascara0s_16);  //(a 1)mascara0s_16 bits a poner a cero.
	 Delay(90); // aprox microseg 10
}

void lcd_envia(uint8_t d) {
	volatile uint16_t val;
 
	val = (uint16_t) d>>4;
	
	val = val<<4;
	Write_port_masked(P_LCD, val, busLCD_4_bits);  // Escribe parte alta 
	Delay(320); // aprox microseg -50  2014 12
	GPIO_ResetBits(P_LCD, R_W_lcd); // Sel escritura, bit 5 
	Delay(320); // aprox microseg -50  2014 12
	GPIO_SetBits(P_LCD, Enable_oper_lcd); // Activa escritura  E=1   
	Delay(2200); // aprox microseg - 100   2014 120
	GPIO_ResetBits(P_LCD, Enable_oper_lcd); // Desactiva escritura E=0 
	Delay(90); // aprox microseg -100  2014 50
 
	val = (uint16_t) d & 0x000F;
	val = val<<4;
	Write_port_masked(P_LCD, val, busLCD_4_bits); // Escribe parte baja
	Delay(90); // aprox 37microseg -100  2014 50
	GPIO_SetBits(P_LCD, Enable_oper_lcd); // Activa escritura E=1 
	Delay(320); // aprox 37microseg -100 2014 120
  GPIO_ResetBits(P_LCD, Enable_oper_lcd); // Desactiva escritura E=0 
	Delay(90); // aprox microseg -100   2014 50                                                                                                                                                                                                       	GPIO_ResetBits(P_LCD, Enable_oper_lcd); // Desactiva escritura E=0 
	Delay(92000); // aprox 37microseg -240000  2014 42000

}

/* tomar el control del LCD y establecer condiciones iniciales */ 
void lcd_reset(void) { 
		
	Delay(120000); // aprox 20 miliseg: inicializacion micro del LCD 260000

	GPIO_ResetBits(P_LCD, RS_lcd); /* Selecc Registro de ordenes */ 
	Delay(100); // aprox 8microseg 100
	lcd_envia(0x03);   // se carga orden -03- reg de control -cursor a origen- 
	Delay(100); // aprox 8microseg 100
	GPIO_ResetBits(P_LCD, R_W_lcd | RS_lcd );  // bits a cero 
	
	Delay(120); // aprox 8microseg 100
	GPIO_SetBits(P_LCD, Enable_oper_lcd); // Activa escritura  E=1  
	Delay(120); // aprox 8microseg 100
	GPIO_ResetBits(P_LCD, Enable_oper_lcd); // Desactiva escritura E=0 
	Delay(120); // aprox 8microseg 100

	GPIO_SetBits(P_LCD, Enable_oper_lcd); // Activa escritura  E=1  
	Delay(120); // aprox 8microseg 100
	GPIO_ResetBits(P_LCD, Enable_oper_lcd); // Desactiva escritura E=0 
	Delay(120); // aprox 8microseg 100
	
  GPIO_SetBits(P_LCD, Enable_oper_lcd); // Activa escritura  E=1   
	Delay(120); // aprox 8microseg 100
	GPIO_ResetBits(P_LCD, Enable_oper_lcd); // Desactiva escritura E=0 
	Delay(120); // aprox 8microseg 100
	
	lcd_envia(0x28); // bus de 4 bits  
 
	lcd_envia(0x0C); // cursor apagado  

	lcd_envia(0x06); // lcd no desplazado 
 
	lcd_envia(0x01); // limpiar pantalla  
	
 
}

// crear un nuevo caracter con codigo de 0 a 8 (o 16) 
// el puntero debera asignarse a una cadena de 8 caracteres 
void lcd_creacaracter(unsigned char c, unsigned char *p) {
	unsigned char i;
//	uint16_t val_16;
	
	GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 500
	lcd_envia(0x40|(c*8));
	Delay(120); // aprox 8microseg 500
	for (i=0;i<8;++i) {
		GPIO_SetBits(P_LCD, RS_lcd); // Selecc Registro de datos 
    Delay(120); // aprox 8microseg 400
		lcd_envia(*p);
		p++;
	}
	GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 
	lcd_envia(0x80);
}

// situar el puntero de escritura en el lugar deseado del display
// la coordenada superior izquierda es la 1,1
void lcd_gotoxy(unsigned char x, unsigned char y){

  unsigned char d;

  GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 
  d = 0x80 + (y-1)*0x40 + x-1;
  lcd_envia(d);
}

// escribir el caracter especificado a la posicion del cursor
void lcd_caracter(unsigned char c){

  GPIO_SetBits(P_LCD, RS_lcd); // Selecc Registro de datos 
  Delay(120); // aprox 8microseg 
  lcd_envia(c);
}

// escribir una cadena a partir de la posición del cursor
void lcd_escribe(unsigned char *s){

	while(*s){
		lcd_caracter(*s);
		s++;
	}
}

// hacer visible el cursor con parpadeo
void lcd_cursoron(void){

	GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 
	lcd_envia(0x0F);
}

// ocultar el cursor
void lcd_cursoroff(void){

	GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 
	lcd_envia(0x0C);
}


// borrar la pantalla
void lcd_clrscr(void){

	GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 
	lcd_envia(0x01);
	Delay(300); // aprox 37microseg 
}


void lcd_rincon(void){

	GPIO_ResetBits(P_LCD, RS_lcd); // Selecc Registro de ordenes 
  Delay(120); // aprox 8microseg 
	lcd_envia(0x02);
}

