package test;

import interf.SecurityService;

public class CommonUserService1 {
    protected final SecurityService securityservice = new SecurityServiceImpl();
    public SecurityService getSecurityService() {
    return securityservice;
}

}
