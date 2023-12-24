// C Program to illustrate the system function
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rhel/init.h"



char get_os_id() {

    char os_id = system( "cat /etc/*-release | grep ID | head -n1 | cut -d '=' -f2" );
    return os_id;
}



int main(void)
{

    char os_id = get_os_id();


    if ( strcmp( os_id, "rhel" ) == 0 )
    {
        rhel_plow();
    }
    else if ( strcmp( os_id, "ubuntu" ) == 0 )
    {

    }
    else
    {
        printf( "%c\n", "Operating System not supported." ); 
    }

    return 0;
}
