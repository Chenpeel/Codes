class AddOver{
    public int add1(int a,int b){
        return a+b;
    }
    public int add2(int a,int b,int c){
        return a+b+c;
    }
}
public class Black{
    public static void main(String[] args){
        AddOver a= new AddOver();
        System.out.println(a.add1(1, 2));
        System.out.println(a.add2(1, 2, 3));
    }
    
}