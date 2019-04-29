/**
 * Generated by Eclipse Mita 0.2.0.
 * @date 2019-04-24 17:25:19
 */


#ifndef CONNECTIVITYLED_LED_10_H
#define CONNECTIVITYLED_LED_10_H

#include <BCDS_Retcode.h>
#include "stdbool.h"


/**
 * Sets up the LED_10.
 */
Retcode_T ConnectivityLEDLeds_Setup(void);

/**
 * Enables the LED_10 sensor.
 */
Retcode_T ConnectivityLEDLeds_Enable(void);

/**
 * Provides read access to r.
 */
Retcode_T ConnectivityLEDLeds_R_Read(bool* result);

/**
 * Provides write access to r.
 */
Retcode_T ConnectivityLEDLeds_R_Write(bool* result);
/**
 * Provides read access to g.
 */
Retcode_T ConnectivityLEDLeds_G_Read(bool* result);

/**
 * Provides write access to g.
 */
Retcode_T ConnectivityLEDLeds_G_Write(bool* result);
/**
 * Provides read access to b.
 */
Retcode_T ConnectivityLEDLeds_B_Read(bool* result);

/**
 * Provides write access to b.
 */
Retcode_T ConnectivityLEDLeds_B_Write(bool* result);


#endif
