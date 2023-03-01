/*
 * GCode_helper.c
 *
 *  Created on: Jan 28, 2023
 *      Author: Ajith Pinninti
 */

#include "GCode_helper.h"

Status_buff Mot_Status =  {0};


char* G_codes[] = {"G90","G91","HOME","MOTPOS","ENCZERO","ENCVAL"};

char* Instant_G_codes[] = {"M414 \r"};

int is_instant_command(char* command){
	return 0;

}

int is_command_valid(char* command){

	char* Temp_Buffer = (char *) malloc(strlen(command)+1);

	strcpy(Temp_Buffer,command);

	int MAX_TOKENS = 3;
	char *token;
	char *tokens[3] = {0};
	int i = 0;


	/* Split the string by the delimiter " " */
	token = strtok((char *)Temp_Buffer, " ");

	while (token != NULL && i < MAX_TOKENS) {
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	int total_commands = sizeof(G_codes)/sizeof(char *);
	for(int val=0;val < total_commands;val++){

		if(strcmp(tokens[0],G_codes[val]) == 0 )
		{
			free(Temp_Buffer);
			return 1;
		}
	}
	free(Temp_Buffer);
	return 0;

//	if(strcmp(tokens[0],"G90") == 0 ){
//	}

}

void Setup_Absolute_position(char *tokens[] ){

	if((*tokens[1]) == 'Z'){
	// Z directional motor
//	char *p;
	float steps =strtod(tokens[1]+1,NULL);  // strtol(tokens[1]+1, &p, 10);  //number start from next position of string

	/* Z motor Positioning */
	int32_t total_steps = (int32_t) (steps * steps_per_millimeters);
	moveTo(total_steps);



	if(*tokens[2] == 'F'){
	/* F speed controller */
	float speed = strtod(tokens[2]+1,NULL);
	speed = speed * steps_per_millimeters;
	/*Fan Speed controlling */
	setMaxSpeed(speed);

	}
	return;
	}


}


void Setup_Relative_position(char *tokens[] ){

	if((*tokens[1]) == 'Z'){
	// Z directional motor
//	char *p;
	float steps =strtod(tokens[1]+1,NULL);  // strtol(tokens[1]+1, &p, 10);  //number start from next position of string

	/* Z motor Positioning */
	int32_t total_steps = (int32_t) (steps * steps_per_millimeters);
	move(total_steps);

	if(*tokens[2] == 'F'){
	/* F speed controller */
	float speed = strtod(tokens[2]+1,NULL);
	speed = speed * steps_per_millimeters;

	/*Fan Speed controlling */
	setMaxSpeed(speed);

	}
}
	return;
}

void Homing_motor(char *tokens[] ){
	setMaxSpeed(2*HOME_SPEED); //MOVING IN ccw
	setSpeed(-1*HOME_SPEED); //MOVING IN ccw

	while(!HOMED){
	runSpeed();
	}
	Homing_completion();
	return;
}

void Homing_completion(void){
	stop();
	//resetting position parameters
	setCurrentPosition(0);
	//Resetting the encoder value to zero
	__HAL_TIM_SET_COUNTER(&htim2,0);
	return;
}

void Run_Motor(void){
	runToPosition();
	return;
}

void send_json_data(Status_buff* status){

    char json_string[100] = {0};   // Initialize JSON string buffer

    // Create JSON string
    sprintf(json_string, "{\"Status\":%lu,\"MOTPOS\":%d,\"ENCVAL\":%d,\"busy\":%d}\r\n", status->Status, status->busy);

    // Send JSON string over UART
    HAL_UART_Transmit(&huart2, (uint8_t*)json_string, strlen(json_string), HAL_MAX_DELAY);

}

