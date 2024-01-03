int aide_module_deploy( int* aide_stat ) 
{
    char aide[100];
    FILE *aidemodule = popen( "sudo -S rpm -qa | grep aide", "r" );

    if( fgets ( aide, 100 , aidemodule ) == NULL )
    {
        system("dnf install aide -y");
        system("aide --init");
        system("mv /var/lib/aide/aide.db.new.gz /var/lib/aide/aide.db.gz");
        *aide_stat = 1; 
    }
    else
    {
        *aide_stat = 0;
    }
    fclose(aidemodule);

    return *aide_stat;
}


int aide_module_init() 
{
    int aide_stat = 0;
    printf("\n");
    printf("Configure aide ... \n");

    aide_stat = aide_module_deploy( &aide_stat );

    if ( aide_stat ==  1 ) 
    {
        printf("Aide is installed. \n");
    }
    else 
    {
        printf("Aide is configured. \n");
    } 
}