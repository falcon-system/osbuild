

int aide_module_deploy() 
{
    char aide[100];
    FILE *aidemodule = popen( "sudo -S rpm -qa | grep aide", "r" );

    if( fgets ( aide, 100 , aidemodule ) == NULL )
    {
        printf("%s", "aide not installed");
    }
    else
    {
        printf("%s", "aide installed");
    }
    fclose(aidemodule);
}


int aide_module_update() 
{
    printf("%s", "Plese wait aide will generate database for a few minute");
    system("aide --init");
    system("mv /var/lib/aide/aide.db.new.gz /var/lib/aide/aide.db.gz");
}


int aide_module_init() 
{
    aide_module_deploy();
    aide_module_update();
}