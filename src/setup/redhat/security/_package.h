
#include "aide.h"
#include "fapolicyd.h"
#include "firewall.h"
#include "keepass.h"
#include "rsyslog.h"
#include "usbguard.h"

int setup_security_base_package( int packages[], int size ) 
{
    for ( int i = 0; i < size ; i++ ) 
    {
        if ( packages[i] == 1 )
        {
            aide_module_init();
        }
        else if ( packages[i] == 2 )
        {
            fapo_module_init();
        }
        else if ( packages[i] == 3 )
        {
            fire_module_init();
        }
        else if ( packages[i] == 4 )
        {
            pass_module_init();
        }
        else if ( packages[i] == 5 )
        {
            rlog_module_init();
        }
        else if ( packages[i] == 6 )
        {
            usbg_module_init();
        }
    }
}