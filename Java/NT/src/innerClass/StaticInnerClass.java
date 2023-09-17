public class StaticInnerClass {
    static int count = 10;
    static class InnerClass{
        static int count = 20;

        public void showStaticMemberInfo(int count){
            System.out.println("xingcan "+ count);
            System.out.println("neijing "+ InnerClass.count);
            System.out.println("waijing " + StaticInnerClass.count);
        }
    }
}
