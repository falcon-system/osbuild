int keepass_module_deploy( int* keepass_stat ) 
{
    char keepass[100];
    FILE *keepassmodule = popen( "sudo -S rpm -qa | grep keepassxc", "r" );

    if( fgets ( keepass, 100 , keepassmodule ) == NULL )
    {
        system("dnf install keepassd -y");
        *keepass_stat = 1; 
    }
    else
    {
        *keepass_stat = 0;
    }
    fclose(keepassmodule);

    return *keepass_stat;
}


int pass_module_init() 
{
    int keepass_stat = 0;
    printf("\n");
    printf("Configure keepass ... \n");

    keepass_stat = keepass_module_deploy( &keepass_stat );

    if ( keepass_stat ==  1 ) 
    {
        printf("keepass is installed. \n");
    }
    else 
    {
        printf("keepass is configured. \n");
    } 
}
