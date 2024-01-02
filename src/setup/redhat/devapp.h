
int setup_security_package() 
{
    aide_module_init();
}

int setup_rhel_devapp_workstation()
{

    setup_security_package();
    // rhel_firewall_setup_coredev_zone();
    // printf("%s", "devpp mode");
}