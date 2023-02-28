	
    
#include <stdio.h>
#include <string.h>
#include <ctype.h>

 
 int main(void){

    char *token;

    volatile char RxBuffer[60] = "G90 Z0 F5 \r   G91 Z1 F20 \r ";
  
    	// Replace all occurrences of "\r " with "\r" (if any)
		char* space_ptr = strstr(RxBuffer, "\r");
		while (space_ptr != NULL) {
			// Skip over the "\r" delimiter
			space_ptr++;

			// Remove any leading spaces after the "\r" delimiter
			while (isspace(*space_ptr)) {
				memmove(space_ptr, space_ptr + 1, strlen(space_ptr + 1) + 1);
			}

			// Find the next occurrence of "\r"
			space_ptr = strstr(space_ptr, "\r");
		}


      /* Split the string by the delimiter "\r" */
		token = strtok(RxBuffer, "\r");
    
		while (token != NULL ) { 
			// if(is_command_valid(token))
			// {
			// 	enqueue(&CommandBuffer,token);
			// }
            printf("%s\n",token);
			token = strtok(NULL, "\r");
		}


 }