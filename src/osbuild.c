// C Program to illustrate the system function
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "library/heading.h"
#include "library/osinfo.h"
#include "setup/redhat/setup.h"


int topnav() 
{
    printf("\n");
    printf("1. Desktop - Software Development \n");
    printf("2. Dekstop - Design and Multimedia  \n");
    printf("3. Servers - Virtualization Host \n");
    printf("4. Servers - Single Application Server  \n");
    printf("5. Servers - Single Application Server  \n");
    printf("\n");
    printf("========================================\n");
}


int setups() {

    int acts = 0;
    int osid = 0;
    get_current_osid( &osid );

    // setup menu
    banner();
    topnav();
    printf("Type action number: \n");
    scanf("%d", &acts);

    // selected process
    if ( osid == 1 )
    {
        rhel_setup( acts );
    }
    else
    {
        printf( "%s\n", "Action is not supported" ); 
    }

    printf("\n");
}


int main( int argc, char *argv[] )
{
    if ( getuid() == 0 ){
        setups(); //so you can do what`enter code here`ever `enter code here` you want as root user
    }
    else
    {
        printf("please run this application as root user !\n");
    }
    return 0;
}