// C Program to illustrate the system function
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "virthost.h"

int rhel_setup( int action )
{
    if ( action == 1 ) 
    {
        printf(" Redhat - Software Development \n");
    }
    else if ( action == 2 )
    {
        printf(" Redhat - Design and Multimedia \n");
    } 
    else if ( action == 3 )
    {
        printf(" Redhat - Virtualization Host \n");
    }
    else
    {
        printf( "%s", "Operation not supported yet" );
    }
}

