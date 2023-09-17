public class CatchTest1 {

    public static void main(String[] args) {
        Integer a = 1;
        Integer b = 1;
        try{
        Integer c = devision(a,b);
        System.out.println(c);
        System.out.println("a/b,OK");
        }catch(NullPointerException e){
            System.out.println("into catch");
            e.printStackTrace();
        }catch(ArrayIndexOutOfBoundsException d){
            System.out.println("into ArrayE");;
        }

        //处理工作 - 流
        finally{
            System.out.println("into finally");
        }
    }
    
    public static Integer devision(Integer a,Integer b){
        return a/b;
    }
    
}
