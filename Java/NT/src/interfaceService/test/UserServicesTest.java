package test;

import interf.PCUserServiceImpl;
import interf.PCUserServices;

public  class UserServicesTest {
    public static void main(String[] args) {
        System.out.println("当前网站名称是"+PCUserServices.WEB_SITE_NAME);

        PCUserServiceImpl pcUserService = new PCUserServiceImpl();
        
        // pcUserService.login();

        pcUserService.resetPassword();
        PCUserServices.statistics();
        
    }
} 
