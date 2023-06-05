/*
 * LCD.h
 *
 *  Created on: 4 Haz 2023
 *      Author: Muhammed
 */

#ifndef LCD_DRIVER_INC_LCD_H_
#define LCD_DRIVER_INC_LCD_H_

/*Platform Dependet defines*/
#include "main.h"//This is header of HAl_Delay and GPIOx->ODR

#define DELAY_MS(delay) HAL_Delay(delay)//Change with your delay function

#define PORT_MASK_VALUE 0xFF00//ST32 port resister is 32 bit but only 16 bit is usable.This is the mask value for it

#define DATA_OUTPUT_PORT GPIOC->ODR //D0..D7 output port definition.

#define RS_PIN_PORT GPIOA->ODR//RS PIN output port definition.
#define RS_PIN 1			  //RS PIN Pin definition

#define RW_PIN_PORT GPIOA->ODR//RW PIN output port definition.
#define RW_PIN 4			  //RW PIN Pin definition

#define E_PIN_PORT GPIOA->ODR//E PIN output port definition.
#define E_PIN 6				 //E PIN Pin definition
/*Platform Dependet defines*/


#define SET_GPIO_PIN(GPIO_PORT,GPIO_PIN) (GPIO_PORT |= (1 << GPIO_PIN))//setting a bit in port
#define RST_GPIO_PIN(GPIO_PORT,GPIO_PIN) (GPIO_PORT &= (~(1 << GPIO_PIN)))//resetting a bit in port



#define LCD_CLEAR 0x01
#define CURSOR_HOME 0x02

void LCD_Write_Command( char command);
void LCD_Put_Char(char chracter);
void LCD_Goto( char column, char row);
void LCD_Clear(void);
void LCD_Put_String(char *String);
void LCD_Init(void);
#endif /* LCD_DRIVER_INC_LCD_H_ */
