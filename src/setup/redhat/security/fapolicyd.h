int fapo_rules_vscode() 
{
    system("fapolicyd-cli --file add /usr/share/code/ --trust-file vscode");
    system("fapolicyd-cli --update");
}


int fapo_rules_hugo() 
{
    system("fapolicyd-cli --file add /usr/bin/hugo --trust-file hugo");
    system("fapolicyd-cli --update");
}


int fapo_module_deploy( int* fapo_stat ) 
{
    char fapo[100];
    FILE *fapomodule = popen( "sudo -S rpm -qa | grep fapolicyd", "r" );

    if( fgets ( fapo, 100 , fapomodule ) == NULL )
    {
        system("dnf install fapolocyd -y");
        system("systemctl enable --now --fapolicyd");
        printf("Fapolocyd is installed. \n");
        *fapo_stat = 1; 
    }
    else
    {
        *fapo_stat = 0;
    }
    fclose(fapomodule);

    return *fapo_stat;
}


int fapo_module_init() 
{
    int fapo_stat = 0;
    printf("\n");
    printf("Configure fapolicyd ... \n");

    fapo_stat = fapo_module_deploy( &fapo_stat );

    if ( fapo_stat ==  1 ) 
    {
        printf("Fapolicyd is installed. \n");
    }
    else 
    {
        printf("Fapolicyd is configured. \n");
    } 
}