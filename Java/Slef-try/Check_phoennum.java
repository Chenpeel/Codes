import java.util.*;

public class Check_phoennum {
    public static void main(String[] args){
        System.out.println("请输入：");
		Scanner a = new Scanner(System.in);
		String x=a.next();
		String b="(\\d){11}";
		boolean check = x.matches(b);
		if(check) {
			System.out.println("输出正确");
			System.out.println("*******"+x.substring(7));

		}
		else {
			System.out.println("输入错误");

		}
   
    }
}