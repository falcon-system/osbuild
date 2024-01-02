

int rhel_firewall_deployment() 
{

}

// firewall config for central command 
int rhel_firewall_setup_zone_coredev()
{

}


// firewall config for system administrator
int rhel_firewall_setup_zone_manages()
{
    
}


// firewall config for server cluster
int rhel_firewall_setup_zone_barepol()
{
    
}




int rhel_firewall_setup_setup_coredev_zone() {

    char fwcoredev[10];
    FILE *zcheck = popen( "firewall-cmd --list-all-zone | grep cordev", "r" );

    if( fgets ( fwcoredev, 10, zcheck ) == NULL ) 
    {
        system( "sudo -S firewall-cmd --permanent --new-zone=coredev" );
        printf( "%s", "Firewall zone created.\n" );
    }
    else
    {
        printf( "%s", "Firewall zone exist." );
    }
    fclose(zcheck);

}