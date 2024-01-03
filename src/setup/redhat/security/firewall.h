int firewall_config_zone_systems()
{

}


int firewall_config_zone_manages()
{
    
}


int firewall_config_zone_barepol()
{
    
}


int firewall_config_zone_coredev() 
{
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


int firewall_module_deploy( int* firewall_stat ) 
{
    char firewall[100];
    FILE *firewallmodule = popen( "sudo -S rpm -qa | grep firewalld", "r" );

    if( fgets ( firewall, 100 , firewallmodule ) == NULL )
    {
        system("dnf install firewalld -y");
        *firewall_stat = 1; 
    }
    else
    {
        *firewall_stat = 0;
    }
    fclose(firewallmodule);

    return *firewall_stat;
}


int fire_module_init() 
{
    int firewall_stat = 0;
    printf("\n");
    printf("Configure firewall ... \n");

    firewall_stat = firewall_module_deploy( &firewall_stat );

    if ( firewall_stat ==  1 ) 
    {
        printf("firewall is installed. \n");
    }
    else 
    {
        printf("firewall is configured. \n");
    } 
}