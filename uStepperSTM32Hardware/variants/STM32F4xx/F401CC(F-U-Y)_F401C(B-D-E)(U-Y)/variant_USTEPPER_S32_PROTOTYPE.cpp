/*
 *******************************************************************************
 * Copyright (c) 2011-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_USTEPPER_S32_PROTOTYPE)

#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
	//Shield Connectors
	PC_7,  // Digital pin 0/RXD6
	PC_6,  // Digital pin 1/TXD6
	PC_13,  // Digital pin 2
	PA_4,  // Digital pin 3/A3/SPI1_SS
	PA_7,  // Digital pin 4/MOSI1/A4
	PA_6,  // Digital pin 5/MISO1/A5
	PA_5,  // Digital pin 6/SCK1/A6
	PB_8,  // Digital pin 7/SCL1
	PB_9,  // Digital pin 8/SDA1
	PB_10,  // Digital pin 9/A0
	PB_3, // Digital pin 10/A1
	PA_0, // Digital pin 11/A2

	//Expansion connector
	PA_2, // Digital pin 12/A7
	PC_5, // Digital pin 13/A8
	PB_1, // Digital pin 14/A9
	PB_0, // Digital pin 15/A10
	PC_4,  // Digital pin 16/A11
	PC_2,  // Digital pin 17/A12
	PD_2,  // Digital pin 18
	PB_5,  // Digital pin 19
	PC_9,  // Digital pin 20
	PC_3,  // Digital pin 21/A13

	//Internal
	PH_0, // Digital pin 34, used by the external oscillator
	PH_1  // Digital pin 35, used by the external oscillator

};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
	11, // A0,  PA0
	11, // A1,  PA0
	11, // A2,  PA0
	3,  // A3,  PA4
	4,  // A4,  PA7
	5,  // A5,  PA6
	6,  // A6,  PA5
	12, // A7,  PA2
	13, // A8,  PC5
	14, // A9,  PB1
	15, // A10,  PB0
	16, // A11,  PC4
	17, // A12,  PC2
	21 // A13,  PC3
};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  
  RCC_OscInitStruct.PLL.PLLM = 10;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  /*
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  */
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_2);
}

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_BLACKPILL_F401CC */