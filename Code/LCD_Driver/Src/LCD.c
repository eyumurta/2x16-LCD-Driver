/*
 * LCD.c
 *
 *  Created on: 4 Haz 2023
 *      Author: Muhammed
 */
#include "LCD.h"


/**
 * @brief Writes a command to the LCD.
 *
 * This function takes an unsigned char command and writes it to the LCD module.
 *
 * @param command The command to be written to the LCD.
 */
void LCD_Write_Command( char command){
	  DATA_OUTPUT_PORT = (PORT_MASK_VALUE & DATA_OUTPUT_PORT);
	  DATA_OUTPUT_PORT = (command | DATA_OUTPUT_PORT);
	  SET_GPIO_PIN(E_PIN_PORT,E_PIN);
	  RST_GPIO_PIN(E_PIN_PORT,E_PIN);
	  //HAL_GPIO_WritePin(LCD_E_PIN_GPIO_Port, LCD_E_PIN_Pin, 1);//enable the lcd screen
	  //HAL_GPIO_WritePin(LCD_E_PIN_GPIO_Port, LCD_E_PIN_Pin, 0);//enable the lcd screen
	  DELAY_MS(2);


}

/**
 * @brief Writes a character to the LCD.
 *
 * This function takes a character and writes it to the LCD module.
 *
 * @param chracter The character to be written to the LCD.
 */
void LCD_Put_Char( char chracter){

	      SET_GPIO_PIN(RS_PIN_PORT,RS_PIN);
	      RST_GPIO_PIN(RW_PIN_PORT,RW_PIN);
		  RST_GPIO_PIN(E_PIN_PORT,E_PIN);
		 // HAL_GPIO_WritePin(LCD_RS_PIN_GPIO_Port, LCD_RS_PIN_Pin, 1);
		 // HAL_GPIO_WritePin(LCD_RW_PIN_GPIO_Port, LCD_RW_PIN_Pin, 0);
		  //HAL_GPIO_WritePin(LCD_E_PIN_GPIO_Port, LCD_E_PIN_Pin, 0);

		  DATA_OUTPUT_PORT = (PORT_MASK_VALUE & DATA_OUTPUT_PORT);
		  DATA_OUTPUT_PORT = (chracter | DATA_OUTPUT_PORT);

		 // GPIOC->ODR = 0x61 ;//|0xFF00;
		  SET_GPIO_PIN(E_PIN_PORT,E_PIN);
		  RST_GPIO_PIN(E_PIN_PORT,E_PIN);
		  DELAY_MS(2);

}

/**
 * @brief Moves the cursor to the specified column and row of the LCD.
 *
 * This function takes the column and row numbers and moves the cursor to the corresponding position on the LCD module.
 *
 * @param column The column number (0 or 1) to move the cursor to.
 * @param row The row number (0 to 15) to move the cursor to.
 */
void LCD_Goto( char column, char row){

	      RST_GPIO_PIN(RW_PIN_PORT,RW_PIN);
		  RST_GPIO_PIN(RS_PIN_PORT,RS_PIN);
		  switch (column) {
			case 0:
				LCD_Write_Command(0x80 | row);
				break;
			case 1:
				LCD_Write_Command(0x80 | 0x40 | row);
				break;
			default:
				break;
		}


}

/**
 * @brief Clears the LCD screen.
 *
 * This function clears the entire LCD screen and positions the cursor at the home position (0, 0).
 */
void LCD_Clear(void){
	RST_GPIO_PIN(RW_PIN_PORT,RW_PIN);
	RST_GPIO_PIN(RS_PIN_PORT,RS_PIN);
	LCD_Write_Command(LCD_CLEAR);

}

/**
 * @brief Writes a string to the LCD.
 *
 * This function takes a null-terminated string and writes it to the LCD module.
 *
 * @param String The null-terminated string to be written to the LCD.
 */
void LCD_Put_String(char *String){
	for (int var = 0; String[var]!='\0'; var++) {
		LCD_Put_Char(String[var]);
	}


}

/**
 * @brief Initializes the LCD module.
 *
 * This function initializes the LCD module by setting the necessary configuration commands.
 * It sets the write mode, cursor move direction, cursor or display shift, number of lines, display clear,
 * and display on/off control.
 */
void LCD_Init(void){

	RST_GPIO_PIN(RW_PIN_PORT,RW_PIN);//write mode
	RST_GPIO_PIN(RS_PIN_PORT,RS_PIN);

	LCD_Write_Command(0x06);//entry mode set and set cursor move direction
	LCD_Write_Command(0x1C);//cursor or display shift
	LCD_Write_Command(0x38);/*Two lines 8 bit mode*/
	LCD_Write_Command(LCD_CLEAR);
	LCD_Write_Command(0x0c);//display on/off control

}
