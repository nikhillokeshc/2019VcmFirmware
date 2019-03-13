/*
 * cvnp_hal.h
 *
 * Hardware access layer for the CVNP protocol. These methods should be
 * be implemented by the target device, and contain all of the target
 * specific code; everything in the main library is platform
 * independent.
 *
 *  Created on: Mar 6, 2019
 *      Author: Duemmer
 */

#ifndef CVNP_CVNP_HAL_H_
#define CVNP_CVNP_HAL_H_

#include <stdint.h>

typedef struct {
    uint8_t ide : 1;
    uint8_t rtr : 1;
    uint8_t dlc : 4;
} tCanHeader;

typedef struct {
    uint32_t id;
    tCanHeader head;
    uint8_t data[8];
} tCanFrame;


/**
 * Initializes the bus hardware. Returns true if successful
 */
bool cvnpHal_init();


/**
 * Transmits a raw frame on the bus
 */
void cvnpHal_sendFrame(tCanFrame frame);


/**
 * Returns the current system timestamp, in ms
 */
uint32_t cvnpHal_now();

#endif /* CVNP_CVNP_HAL_H_ */














