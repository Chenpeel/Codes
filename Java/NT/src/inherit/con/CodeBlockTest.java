package con;
/**
 * 静态代码块 > 构造代码块 > 构造方法
 */


public class CodeBlockTest {
    
    public static void main(String[] args) {
        // Window window3= new Window("window3");
        // House house = new House(window3);
        System.out.println("数量是" + Window.getWindowCount()) ;
    }
} 



class House{
    //构造代码块
    static Window window1;

    Window window2;
    Window window3;

    //静态代码块
    static{
        System.out.println("1c");
        window1 = new Window("window1");
        System.out.println(window1);
    }
    //构造代码块
    {
        System.out.println("2c");
        window2 = new Window("window2");
        System.out.println(window2);
    }
    //方法
    public House(){}
    public House(Window window3){
        System.out.println("3c");
        this.window3 = window3;
        System.out.println(window3);
    }

}




class Window{

    private  static int WindowCount; 

    private String name;

    public void setname(String name){
        this.name = name;
    }
    public String getname(){
        return name;
    }
    //构造代码块
    {
        WindowCount++;
    }
    public static int getWindowCount(){
        return WindowCount;
    }

    public Window(){

    }

    public Window(String name){
        this.name = name;
    }

    /**
     * 重写toString方法
     */
    @Override
    public String toString(){
        return   "房屋窗户信息{"+ "窗户名称'" + name +'\''+'}';
    }



}

