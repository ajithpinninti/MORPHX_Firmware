/*
 * main_config.h
 *
 *  Created on: 28-Feb-2023
 *      Author: Ajith Pinninti
 */

#ifndef INC_MAIN_CONFIG_H_
#define INC_MAIN_CONFIG_H_


#define MAX_PER_COMMAND_SIZE 40
#define MAX_COMMANDS_PER_TIME 30
#define steps_per_millimeters 50000




/*
 * HOMING MACROS
 */

#define HOME_SPEED_MM  1 /* in mm/sec^2 */
#define HOME_SPEED HOME_SPEED_MM * steps_per_millimeters

#define HOMING_PASS_BACK_MM 0.2

#endif /* INC_MAIN_CONFIG_H_ */
