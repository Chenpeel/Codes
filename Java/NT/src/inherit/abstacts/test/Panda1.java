package abstacts.test;

public class Panda1 extends Animal{
   
    public Panda1(){
    }

    public Panda1(String nationality){
        super(nationality);
    }

    public void eat(){
        System.out.println("熊猫吃竹子");
    }
   
    public void sleep(){}
   
    public void sleep(String nationality){
        System.out.println(nationality +"熊猫在睡觉");
    }
    
}
