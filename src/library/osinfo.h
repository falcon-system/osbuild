#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_current_osid( int* os_id ) 
{
    char getosid[10];
    FILE *release = popen( "cat /etc/*-release | grep ID | head -n1 | cut -d '=' -f2", "r" );

    if( fgets ( getosid, 10, release ) != NULL ) {

        getosid[strcspn(getosid, "\n")] = 0;  // remove new line on string
      
        if ( strstr(getosid,"rhel") != NULL ) // check fgets result based on return value string contains
        {
            *os_id = 1;
        }
        else
        {
            *os_id = 0;
        }
    }
    fclose(release);

    return  *os_id;
}
