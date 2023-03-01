/*
 * GCode_helper.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Ajith Pinninti
 */

#ifndef INC_GCODE_HELPER_H_
#define INC_GCODE_HELPER_H_


/*********************************** Macros definitons **********************/

#include "stepper.h"
#include "main.h"

/*************************  User Variables *******************/

/*
 * MOT_STATUS descrine the motor is in busy or ready status
 */
typedef enum
{
  MOT_BUSY = 0,
  MOT_IDLE = 1
}MOT_STATUS;


/*
 * MOTOR STATUS Data Types
 */
typedef struct {

	MOT_STATUS mot_status;            // Busy flag

	float  Motpos;

    uint32_t encoder_val;    // Encoder value

} Driver_status ;


/************************* variables Initialization *****************/
extern Driver_status Driv_status;


/************************ Function Prototype ******************/


/*Checks wheter received command is valid or not
 * @ params
 * RxBuffer -> Contains received command from serial device
 *
 */

int is_command_valid(char* command);
/*Setting up the absolute motor position,
 * @ params
 * tokens -> contains splitted receiver buffer
 *
 */

void Setup_Absolute_position(char *tokens[]);
/* Setting up the Relative motor position,
 * @ params
 * tokens -> contains splitted receiver buffer
 *
 */
void Setup_Relative_position(char *tokens[] );

/*
 * Running the Motor to the desired poistion
 * won't return until completion
 */

void Run_Motor(void);


/** Homing Functions **/

//moving motor in one direction in same speed
void Homing_motor(char *tokens[] );

//reset the position
void Homing_completion(void);

/*
 *  send the status of driver in the json format
 */
void send_json_data(Driver_status* status);

/*
 *@ check whether given command is should be in Non Blocking Mode
 */
int is_instant_command(char *tokens[]);
/*******************************************************************/

#endif /* INC_GCODE_HELPER_H_ */
