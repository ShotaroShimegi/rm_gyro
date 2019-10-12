/*
 * gyro.c
 *
 *  Created on: 2019/10/08
 *      Author: 標 祥太郎
 */

#include"System/gyro.h"
#include"main.h"
#include "spi.h"
#include "tim.h"
#include "System/mainsystem.h"

uint8_t ReadByte(uint8_t addres)
{
	uint8_t trans_addres[2];
	uint8_t receive_data[2];

	trans_addres[0] = addres | 0x80;
	trans_addres[1] = 0x00;

	HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,RESET);
	HAL_SPI_TransmitReceive(&hspi1,trans_addres,receive_data,2,1);
	HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,SET);

	return receive_data[1];
}

void WriteByte(uint8_t addres,uint8_t data)
{

	uint8_t trans_data[2];
	uint8_t receive_data[2];

	trans_data[0] = addres & 0x7f;
	trans_data[1] = data;

	HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,RESET);
	HAL_SPI_TransmitReceive(&hspi1,trans_data,receive_data,2,1);
	HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,SET);

}

void InitGyro(void)
{
	uint8_t who_am_i = ReadByte(WHO_AM_I);
	printf("Who am I ? -> 0x%x\n", who_am_i);

	if(who_am_i != GYRO_CORREST_REACTION){
		who_am_i = ReadByte(WHO_AM_I);
		printf("addres is %d\n",WHO_AM_I);
		printf("Who am I ? -> 0x%x\n", who_am_i);
		while(who_am_i != GYRO_CORREST_REACTION){
			who_am_i = ReadByte(WHO_AM_I);
			printf("Who am I ? -> 0x%x\n", who_am_i);
			printf("Gyro Fail\n");
			HAL_Delay(1000);
		}
	}

	printf("Gyro OK\n");

	WriteByte(PWR_MGMT_1,0x00);
	HAL_Delay(10);
	WriteByte(CONFIG,0x00);
	HAL_Delay(10);
	WriteByte(GYRO_CONFIG,0x18);
	HAL_Delay(10);

}

float ReadGyro(void){
	int16_t omega_raw_z;
	float omega;
	omega_raw_z = (int16_t)(ReadByte(GYRO_ZOUT_H) << 8 | ReadByte(GYRO_ZOUT_L));	//0x47が上位，0x48が下位の16bitデータでジャイロ値を取得
	omega = (float)(omega_raw_z / GYRO_FIX);
	return omega;
}


/*
void GetGyroOffset(uint16_t num){
	float gyro_offset = 0;
	int i;

	for(i=0;i<num;i++){
		gyro_offset += ReadGyro();
		WaitMs(1);
	}
	gyro_base = gyro_offset / num;
}
*/
