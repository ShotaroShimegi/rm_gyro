#include "main.h"
#include "tim.h"
#include "can.h"

#include "System/mycan.h"
#include "System/gyro.h"
#include "System/mainsystem.h"

/*	float angle_degree = 0.0f;
	float omega = 0.0f;
	float gyro_base = 0.0f;
*/

void MainSystem()
{
	uint16_t i = 0;
	CAN_TxHeaderTypeDef header;
	uint8_t TxData[8] = { 0 };
	uint32_t TxMailbox;

	header.StdId = 0x1ff;
	header.RTR = CAN_RTR_DATA;
	header.IDE = CAN_ID_STD;
	header.DLC = 8;

	printf("Hello,Robomaster\n");

	InitGyro();
	InitCanFilter();

	//Get Base Value (Average)
	for(i=0;i<1000;i++){
		gyro_base += ReadGyro();
		HAL_Delay(1);
	}
	gyro_base = gyro_base / 1000;
	printf("Base Value is %lf\n",gyro_base);

	HAL_TIM_Base_Start_IT(&htim6);
	HAL_CAN_Start(&hcan);

	TxData[0] = raw_value_h >> 8;
	TxData[1] = raw_value_l & 0xFF;


	while(1){
			printf("Angle is %lf, omega is %lf\n",angle_degree,omega);
			HAL_Delay(1000);
			HAL_CAN_AddTxMessage(&hcan, &header, TxData, &TxMailbox);

	}

}


