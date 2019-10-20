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

	float angle_degree;
	float omega;
	float gyro_base;
	uint8_t raw_value_h;
	uint8_t raw_value_l;

	#else

	extern float angle_degree;
	extern float omega;
	extern float gyro_base;
	extern uint8_t raw_value_h;
	extern uint8_t raw_value_l;


	#endif



#endif /* INC_SYSTEM_MAINSYSTEM_H_ */
