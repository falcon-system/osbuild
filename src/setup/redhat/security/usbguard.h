int usbguard_module_deploy( int* usbguard_stat ) 
{
    char usbguard[100];
    FILE *usbguardmodule = popen( "sudo -S rpm -qa | grep usbguard", "r" );

    if( fgets ( usbguard, 100 , usbguardmodule ) == NULL )
    {
        system("dnf install usbguard -y");
        system("systemctl enable --now usbguard");
        *usbguard_stat = 1; 
    }
    else
    {
        *usbguard_stat = 0;
    }
    fclose(usbguardmodule);

    return *usbguard_stat;
}


int usbg_module_init() 
{
    int usbguard_stat = 0;
    printf("\n");
    printf("Configure usbguard ... \n");

    usbguard_stat = usbguard_module_deploy( &usbguard_stat );

    if ( usbguard_stat ==  1 ) 
    {
        printf("usbguard is installed. \n");
    }
    else 
    {
        printf("usbguard is configured. \n");
    } 
}