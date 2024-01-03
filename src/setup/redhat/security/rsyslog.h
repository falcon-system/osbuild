int rsyslog_module_deploy( int* rsyslog_stat ) 
{
    char rsyslog[100];
    FILE *rsyslogmodule = popen( "sudo -S rpm -qa | grep rsyslog", "r" );

    if( fgets ( rsyslog, 100 , rsyslogmodule ) == NULL )
    {
        system("dnf install rsyslog -y");
        *rsyslog_stat = 1; 
    }
    else
    {
        *rsyslog_stat = 0;
    }
    fclose(rsyslogmodule);

    return *rsyslog_stat;
}


int rlog_module_init() 
{
    int rsyslog_stat = 0;
    printf("\n");
    printf("Configure rsyslog ... \n");

    rsyslog_stat = rsyslog_module_deploy( &rsyslog_stat );

    if ( rsyslog_stat ==  1 ) 
    {
        printf("rsyslog is installed. \n");
    }
    else 
    {
        printf("rsyslog is configured. \n");
    } 
}
