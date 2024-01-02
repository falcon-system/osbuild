// C Program to illustrate the system function
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library/osinfo.h"
#include "setup/redhat/setup.h"



void falcon_header()
{
    printf("=========================================\n");
    printf("FALCON INFORMATION SYSTEM FRAMEWORK\n");
    printf("=========================================\n");
    printf("\n");
    printf("1 . Workstation - Software Development \n");
    printf("2 . Workstation - Design and Multimedia  \n");
    printf("3 . Server - Virtualization Host \n");
    printf("4 . Server - Single Application Server  \n");
    printf("\n");
    printf("========================================\n");
}


int main( int argc, char *argv[] )
{
    int acts = 0;
    int osid = 0;
    get_current_osid( &osid );

    // setup menu
    falcon_header();
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
  
    return 0;
}