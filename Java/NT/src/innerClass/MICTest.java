public class MICTest {
    public static void main(String[] args) {
        MemberInnerClass memberInnerClass = new MemberInnerClass("外部类");
        MemberInnerClass.InnerClass innerClass = memberInnerClass.new InnerClass("内部类");
        innerClass.showMemberInfo("形参");
        
    }
    
}
