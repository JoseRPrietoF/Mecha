/*----------------------------------------------------------------------------
 * Name:    LCD.h
 * Purpose: low level LCD definitions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/


/*lcd.h*/

//#define P_LCD GPIOB

void LCD_Init (void);
//void retardo(uint32_t iret);
void oscilar_salidas_lcd(void);
void Write_port_masked(GPIO_TypeDef* GPIOx, uint16_t valor_16, uint16_t mascara_16);
void lcd_reset(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_escribe(unsigned char *s);
void lcd_cursoron(void);
void lcd_clrscr(void);
void lcd_cursoroff(void);
void lcd_creacaracter(unsigned char c, unsigned char *p);
void lcd_caracter(unsigned char c);
//void lcd_envia(unsigned char c);



// #ifndef __LED_H
// #define __LED_H


   /* LED Definitions */
// #define LCD_NUM     2                        /* Number of user LEDs          */
//
//extern void LED_Init(void);
//extern void LED_On  (unsigned int num);
//extern void LED_Off (unsigned int num);
//extern void LED_Out (unsigned int value);
//
//#endif
