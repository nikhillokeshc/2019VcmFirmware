/*
 * fault.h
 *
 *  Provides an API for tracking,
 *  handling, and asserting faults on the system.
 *  Created on: Feb 25, 2019
 *      Author: Duemmer
 */

#ifndef FAULT_H_
#define FAULT_H_

#include <stdint.h>

/**
 * Represents a list of all of the different fault codes
 * in the system, as well as a flag for the number of faults
 */
typedef enum {
    FAULT_BMS_CELL_OVER_VOLT_WARN,
    FAULT_BMS_CELL_UNDER_VOLT_WARN,
    FAULT_BMS_PACK_OVER_VOLT_WARN,
    FAULT_BMS_PACK_UNDER_VOLT_WARN,
    FAULT_BMS_PACK_SHORT,
    FAULT_BMS_COMM,
    FAULT_BMS_OVER_CURRENT_CHG,
    FAULT_BMS_OVER_CURRENT_DISCHG,
    FAULT_BMS_CELL_OVER_VOLT,
    FAULT_BMS_CELL_UNDER_VOLT,
    FAULT_BMS_PACK_OVER_VOLT,
    FAULT_BMS_PACK_UNDER_VOLT,
    FAULT_BMS_TEMP,
    FAULT_BMS_IMBALANCE,
    FAULT_BMS_GENERAL,
    FAULT_MPPT_TEMP_WARN,
    FAULT_MPPT_TEMP,
    FAULT_MPPT_BATT_CHARGED,
    FAULT_MPPT_NO_BATT,
    FAULT_MPPT_LOW_SOLAR_VOLTS,
    FAULT_MPPT_COMM,
    FAULT_TELE_LORA,
    FAULT_TELE_PI,
    FAULT_TELE_COMM,
    FAULT_MOTOR_TEMP,
    FAULT_MOTOR_GEN,
    FAULT_MOTOR_COMM,
    FAULT_GEN_ESTOP,
    FAULT_GEN_AUX_OVER_DISCHARGE,
    FAULT_NUM_FAULTS
} tFaultCode;

/**
 * Generic 64 bit data container for fault specific data. Different data
 * representations are there to make it more versatile for different faults to
 * use
 */
typedef union {
    uint64_t ui64;
    uint32_t pui32[2];
    uint16_t pui16[4];
    uint8_t pui8[8];
    float pfloat[2];
} tFaultData;


/**
 * Fault hook to attach to a certain fault. Each fault registered to
 * the system will have one of these. Each contains some function pointers
 * to be called
 */
typedef struct {
    uint32_t bSet : 1;
    uint32_t ui32TSet : 31;
    void (*pfnOnAssert)(tFaultData);
    void (*pfnOnDeassert)(void);
    tFaultData uData;
} tFaultHook;

/**
 * Returns a summary of which faults are set in the system, where each bit
 * in the return value corresponds to one fault. If the fault is set, then
 * the bit will be set, and vice versa.
 */
uint64_t fault_getFaultSummary();


/**
 * Asserts the fault, with the specified data
 */
void fault_assert(uint32_t ui32FaultNum, tFaultData uData);

#endif /* FAULT_H_ */


