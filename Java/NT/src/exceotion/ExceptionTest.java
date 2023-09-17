public class ExceptionTest {
    public static void main(String[] args) {
        System.out.println("start");
        //引发异常 //  '/' by zero //at ExceptionTest.main(ExceptionTest.java:7)
        System.out.println(1/0);
        //该语句未执行
        System.out.println("end");
    }

}