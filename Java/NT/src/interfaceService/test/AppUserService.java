package test;

import interf.LogService;
import interf.PCUserServiceImpl;
import interf.PCUserServices;

public class AppUserService  extends CommonUserService1 implements PCUserServices,LogService{
    public static void main(String[] args) {
        PCUserServiceImpl pcUserServiceImpl= new PCUserServiceImpl();
        pcUserServiceImpl.register();
        pcUserServiceImpl.login();
        pcUserServiceImpl.getSecurityService();
    }       
    public void login(){
        log();
        System.out.println("app用户注册成功");
    }
    public void resetPassword(){
        System.out.println("");
    }
    public void register(){
        log();
        System.out.println("app用户登陆成功");
    }

    public void log(){
        System.out.println("记录操作日志成功");
    }
}
