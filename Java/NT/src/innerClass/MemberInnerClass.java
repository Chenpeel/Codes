public class MemberInnerClass {
    
    private String name;

    public MemberInnerClass(String name){
        this.name = name;
    }

    class InnerClass{
        //内部类不能有静态量
        private String name;

        public InnerClass(String name){
            this.name = name;
        }

        public void showMemberInfo(String name){
            System.out.println("x = " + name);
            System.out.println("y = " + this.name);
            System.out.println("z = " + MemberInnerClass.this.name);
            
        }

    }




}