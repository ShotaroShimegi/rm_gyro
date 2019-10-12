#include "main.h"
#include "tim.h"
#include "System/gyro.h"
#include "System/mainsystem.h"

/*	float angle_degree = 0.0f;
	float omega = 0.0f;
	float gyro_base = 0.0f;
*/

void MainSystem()
{
	uint16_t i = 0;

	printf("Hello,Robomaster\n");

	InitGyro();

	//Get Base Value (Average)
	for(i=0;i<1000;i++){
		gyro_base += ReadGyro();
		HAL_Delay(1);
	}
	gyro_base = gyro_base / 1000;
	printf("Base Value is %lf\n",gyro_base);

	HAL_TIM_Base_Start_IT(&htim6);

	while(1){
			printf("Angle is %lf, omega is %lf\n",angle_degree,omega);
			HAL_Delay(1000);

	}

}


