/*
 * mainsystem.h
 *
 *  Created on: Oct 12, 2019
 *      Author: 標 祥太郎
 */

#ifndef INC_SYSTEM_MAINSYSTEM_H_
#define INC_SYSTEM_MAINSYSTEM_H_


	#ifndef _GLOBAL_
	#define _GLOBAL_

	float angle_degree_yaw;
	float angle_degree_roll;
	float angle_degree_pitch;

	float omega_yaw;
	float omega_roll;
	float omega_pitch;

	float gyro_base_yaw;
	float gyro_base_roll;
	float gyro_base_pitch;

	uint8_t roll_value_h;
	uint8_t roll_value_l;
	uint8_t pitch_value_h;
	uint8_t pitch_value_l;
	uint8_t yaw_value_h;
	uint8_t yaw_value_l;

	#else

	extern float angle_degree_yaw;
	extern float angle_degree_roll;
	extern float angle_degree_pitch;

	extern float omega_yaw;
	extern float omega_roll;
	extern float omega_pitch;

	extern float gyro_base_yaw;
	extern float gyro_base_roll;
	extern float gyro_base_pitch;

	extern uint8_t roll_value_h;
	extern uint8_t roll_value_l;
	extern uint8_t pitch_value_h;
	extern uint8_t pitch_value_l;
	extern uint8_t yaw_value_h;
	extern uint8_t yaw_value_l;


	#endif



#endif /* INC_SYSTEM_MAINSYSTEM_H_ */
