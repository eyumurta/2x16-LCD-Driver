# 2x16 LCD Driver(HD44780)
 
 ![LCD_Ekran](https://github.com/eyumurta/2x16-LCD-Driver/assets/57114692/2f341855-61d0-464a-bba2-d86554d34126)
 This driver designing for be portable.You can esasily port for another devices.
 ## **Porting Guide**

 Goto LCD.h and find the below lines.
 ```C
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

```
This lines defening output ports,delay function and masking value.The library using masking value change only D0 to D7 pins of port.\
You can find  an example for STM32f411 in example directory.
## **Useful Links**
Data Sheet for [HD44780](https://pdf1.alldatasheet.com/datasheet-pdf/view/63673/HITACHI/HD44780.html)\
A [tutorial](https://www.allaboutcircuits.com/technical-articles/how-to-a-162-lcd-module-with-an-mcu/)  for HD4470 
