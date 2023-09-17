package interf;

import test.CommonUserService1;

public  class  PCUserServiceImpl  extends CommonUserService1 implements  PCUserServices{
    @Override
    public void login() {
        //安全检查
        securityservice.securitycheck(); 
        System.out.println("PC用户登录成功");
    }
    @Override
    public void resetPassword(){
        //安全检查
        getSecurityService().securitycheck(); 
        System.out.println("重置成功");
    }

    public void register(){
        //安全检查
        getSecurityService().securitycheck(); 
        System.out.println("注册成功");
    }

}