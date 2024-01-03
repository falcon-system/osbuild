// C Program to illustrate the system function
#include "security/_package.h"
#include "vihost.h"
#include "design.h"
#include "devapp.h"


int rhel_setup( int action )
{
    if ( action == 1 ) 
    {
        setup_rhel_devapp_workstation();
    }
    else if ( action == 2 )
    {
        setup_rhel_design_workstation();
    } 
    else if ( action == 3 )
    {
        setup_rhel_virtualization_host();
    }
    else
    {
        printf( "%s", "Operation not supported yet" );
    }
}

