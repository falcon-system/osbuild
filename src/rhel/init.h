// C Program to illustrate the system function
#include <stdio.h>
#include <stdlib.h>


int rhel_plow()
{


    // giving system command and storing return value
    int returnCode = system("echo Hello, World!");
 
    // checking if the command was executed successfully
    if (returnCode == 0) {
        printf("Command executed successfully.");
    }
    else {
        printf("Command execution failed or returned "
               "non-zero: %d", returnCode);
    }
 
    return 0;

}