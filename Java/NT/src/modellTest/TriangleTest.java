import java.util.Scanner;

class TriangleException extends Exception {
    public TriangleException(double a, double b, double c) {
        System.out.println("Exception: the sum of two sides " + "is greater than the third one");
        System.out.println("a:  " + a + "\n b:  " + b + "\n c:" + c);
    }
}

class TriangleExceptionTest {
    // 计算面积
    public static double showArea(double a, double b, double c) throws TriangleException {
        if (a + b < c || a + c < b || b + c < a) {
            throw new TriangleException(a, b, c);
        }
        double p = (a + b + c) / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));

    }

    public static void main(String[] args) {
        double a, b, c;
        System.out.println("Input:a,b,c");
        Scanner in = new Scanner(System.in);
        a = in.nextDouble();
        b = in.nextDouble();
        c = in.nextDouble();
        try {
            System.out.println("Area:" + showArea(a, b, c));
        } catch (TriangleException e) {
            System.out.println(e);
        }
    }
}
