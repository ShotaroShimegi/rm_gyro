/*
 * gyro.h
 *
 *  Created on: 2019/10/08
 *      Author: 標 祥太郎
 */

#ifndef INC_SYSTEM_GYRO_H_
#define INC_SYSTEM_GYRO_H_

#include "stdint.h"

// For MPU9250 Resister
	#define WHO_AM_I 0x75
	#define GYRO_CORREST_REACTION 0x71
	#define	PWR_MGMT_1 0x6B
	#define	CONFIG 0x1A
	#define GYRO_CONFIG 0x1B
	#define GYRO_ZOUT_H 0x47
	#define GYRO_ZOUT_L 0x48
	#define GYRO_FIX  16.4f


uint8_t ReadByte(uint8_t);
void WriteByte(uint8_t,uint8_t);

void InitGyro();
float ReadGyro(void);
void GetGyroOffset(uint16_t);




#endif /* INC_SYSTEM_GYRO_H_ */
