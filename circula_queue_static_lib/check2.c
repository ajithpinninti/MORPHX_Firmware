
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char buffer[] = "hello \r   hi \r         How r u";
    char* token;
    
    // Replace all occurrences of "\r " with "\r" (if any)
    char* space_ptr = strstr(buffer, "\r");
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
    
    // Split the string using "\r" delimiter
    printf("aslkdjflkasdf Buffer: %s \n",buffer);
    token = strtok(buffer, "\r");
    
    // Iterate through all the tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "\r");
    }
    
    return 0;
}
