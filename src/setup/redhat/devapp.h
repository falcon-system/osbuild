
int setup_rhel_devapp_workstation()
{
    int security[6] = { 1, 2, 3, 4, 5, 6 };

    banner();
    setup_security_base_package( security, 6 );
}