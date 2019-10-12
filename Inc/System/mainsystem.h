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

	#else

	extern float angle_degree;
	extern float omega;
	extern float gyro_base;

	#endif



#endif /* INC_SYSTEM_MAINSYSTEM_H_ */
