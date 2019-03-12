/*----------------------------------------------------------------------------*/
/*
 * Copyright (C) Bosch Connected Devices and Solutions GmbH.
 * All Rights Reserved. Confidential.
 *
 * Distribution only to people who need to know this information in
 * order to do their job.(Need-to-know principle).
 * Distribution to persons outside the company, only if these persons
 * signed a non-disclosure agreement.
 * Electronic transmission, e.g. via electronic mail, must be made in
 * encrypted form.
 */
/*----------------------------------------------------------------------------*/

#ifndef TESTSUITE_SPI_H_
#define TESTSUITE_SPI_H_

//TEst SPI Extention Board
#define SPI_TEST_SERIAL_PORT                USART2
#define SPI_TEST_PERCLK_FREQUENCY           HSE_VALUE
#define SPI_TEST_BAUDRATE                   UINT32_C(2000000)

#define SPI_TEST_RX_IRQN                     USART2_RX_IRQn
#define SPI_TEST_RX_INTERRUPT_PRIORITY       UINT32_C(5)

#define SPI_TEST_TX_IRQN                     USART2_TX_IRQn
#define SPI_TEST_TX_INTERRUPT_PRIORITY       UINT32_C(5)

#define SPI_TEST_SPI1_MISO_PIN               (4)
#define SPI_TEST_SPI1_MISO_PORT              (gpioPortB)

#define SPI_TEST_SPI1_MOSI_PIN               (3)
#define SPI_TEST_SPI1_MOSI_PORT              (gpioPortB)

#define SPI_TEST_SPI1_SCK_PIN                (5)
#define SPI_TEST_SPI1_SCK_PORT               (gpioPortB)

#define SPI_TEST_CS_PIN                     (8)
#define SPI_TEST_CS_PORT                    (gpioPortD)

enum TestSuite_2_RetCode_E
{
    TESTSUITE_2_SETUP_TRIGGERED_SEVERAL_TIMES = RETCODE_FIRST_CUSTOM_CODE,
    TESTSUITE_2_RUN_TRIGGERED_SEVERAL_TIMES,
    TESTSUITE_2_TEARDOWN_TRIGGERED_SEVERAL_TIMES,
};

Retcode_T TestSuite_SPI_initialize(uint8_t testSuiteId);

/**
 * @brief SPI receive interrupt service routine used to capture interrupts at the SPI
 * resource and to forward them to the MCU driver for processing.
 */
void SPITest_SPIRxISR(void);
/**
 * @brief SPI transmit interrupt service routine used to capture interrupts at the SPI
 * resource and to forward them to the MCU driver for processing.
 */
void SPITest_SPITxISR(void);

void USART2_TX_IRQHandler(void);

void USART2_RX_IRQHandler(void);

#endif /* TESTSUITE_SPI_H_ */
