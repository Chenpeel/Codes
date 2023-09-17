package abstacts.test;

public class AbstractClassTest {
    public static void main(String[] args) {
        Cat1 cat = new Cat1();
        cat.eat();

        Panda1 panda = new Panda1();
        panda.eat();


        Panda1 china = new Panda1("中国");
        china.sleep(china.getnationality());
    }
}
