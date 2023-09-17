import java.util.*;

public class GuessNum {
    public static void main(String[] args) {
        Random r = new Random();//生成随机数
        int number = r.nextInt(100) + 1;
        while (true) {
            Scanner sc_in = new Scanner(System.in);//键入猜数
            System.out.println("输入你要猜的:");
            int guessNum = sc_in.nextInt();
            if (guessNum > number) {
                System.out.println("猜大了");
            } else if (guessNum < number) {
                System.out.println("猜小了");
            } else if (guessNum == number) {
                System.out.println("猜中了!");
                break;
            }
        }
    }
}