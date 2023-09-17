// import java.lang.*;
import java.util.*;


class Apes{
    // public final double PI = 3.1415926;
    private double xpoint;
    private double ypoint;
    private double radius;
    
    public void Name(double xpoint,double ypoint,double radius){
        this.xpoint=xpoint;
        this.ypoint=ypoint;
        this.radius=radius;
    } 
    public double getArea(double radius){
        return Math.PI *radius *radius;
    }
    public double getCircumference(double radius){
        return 2* Math.PI * radius;
    }

    public String toString(){
        return  " 坐标 "+"("+this.xpoint+","+this.ypoint+")  "+"半径 "+this.radius;
    }
}

public class Circle{
    public static void main(String[] args){
        double x ,y,r;
        double area;
        double Circumference;
        System.out.println("键入星x,y,r");
        System.in.close(x,y,r);
        Apes C1 = new Apes();
        area = C1.getArea(r);
        Circumference = C1.getCircumference(r);
        System.out.println(" 面积 " + area);
        System.out.println(" 周长 " + Circumference) ;
        C1.Name(x, y, r);
        System.out.println(C1);
    }
}