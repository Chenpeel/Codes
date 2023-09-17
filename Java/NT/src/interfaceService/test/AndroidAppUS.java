package test;

import interf.PCUserServices;

public class AndroidAppUS  extends CommonUserService1 implements PCUserServices{
   
    public static void main(String[] args) {
        
    }
   
    public void login(){
        System.out.println("Android app用户注册成功");
    }
    // public void resetPassword(){
    //     System.out.println("");
    // }
    public void register(){
        System.out.println("Android app用户登陆成功");
    }
    

}
