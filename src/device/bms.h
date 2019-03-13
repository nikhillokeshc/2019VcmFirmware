/*
 * bms.h
 *
 * Driver for the BMS. This controls all data access between the VCM
 * and BMS
 *
 *  Created on: Mar 9, 2019
 *      Author: Duemmer
 */

#ifndef SRC_DEVICE_BMS_H_
#define SRC_DEVICE_BMS_H_

#define BMS_NUM_CELLS               20;

/**
 * Data for one cell
 */
typedef struct {
    float voltage;
    float temp;
} tCellData;


/**
 * Custom flag 0 for the BMS
 */
typedef struct {
    uint8_t rlyChgFault : 1;
    uint8_t rlyDisFault : 1;
    uint8_t cellOVFault : 1;
    uint8_t cellUVFault : 1;
    uint8_t thermistorFault : 1;
    uint8_t overTempFault : 1;
    uint8_t internalTempFault : 1;
} tBmsFlag0;


/**
 * Custom flag 1 for the BMS
 */
typedef struct {
    uint8_t cellOpenWiringFault : 1;
    uint8_t weakCellFault : 1;
    uint8_t currentSenseFault : 1;
    uint8_t isolationFault : 1;
    uint8_t internalCellCommFault : 1;
    uint8_t internalLogicFault : 1;
    uint8_t internalHardwareFault : 1;
} tBmsFlag1;


/**
 * Data for the BMS
 */
typedef struct {
    tCellData cellData[BMS_NUM_CELLS];
    tBmsFlag0 flag0;
    tBmsFlag1 flag1;
    float vCellAvg;
    float vBat;
    float iBat;
    float soc;
    float vInput;
    uint8_t vMaxIdx;
    uint8_t tMaxIdx;
    uint8_t rlyDis : 1;
    uint8_t rlyChg : 1;

} tBMSData;


/**
 * Initializes the motor controller driver
 */
void bms_init();


/**
 * Tick routine to be run every ~10ms. This is where this api can
 * periodically query, check stuff, etc.
 *
 * \param now the current millisecond timestamp
 */
void bms_tick(uint32_t now);


/**
 * Retrieves the instantaneous data for the BMS.
 */
tBMSData *bms_data();



#endif /* SRC_DEVICE_BMS_H_ */












