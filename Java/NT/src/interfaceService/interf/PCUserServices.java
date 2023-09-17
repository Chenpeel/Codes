package interf;

public interface PCUserServices extends LoginService,RegisterService{
    
    String WEB_SITE_NAME = "淘宝网";

    void login();

    public default void resetPassword(){
        System.out.println("手机号发送验证码");
        sendCode();
        System.out.println("验证码");
        System.out.println("输入新密码");
        System.out.println( "确认新密码");
        System.out.println("成功");
    }

    private void sendCode(){
      System.out.println("你的验证码是XXXXXX,请勿泄漏");  
    }
    

    static void statistics(){
        long count= getAllUserInfo();
        System.out.println("注册人数"+count);
    }

    private static long getAllUserInfo(){
        System.out.println("查询所有用户信息");
        int count = 1_000_000_000;
        return count;
    }

}
