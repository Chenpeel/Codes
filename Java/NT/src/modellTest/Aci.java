public class Aci {
    public static void main(String[] args) {
    String str = " ahsjw wklq eosnca aw uubq";
    (new Aci()).VomNums(str);
    }


    // 方法实现
    public void VomNums(String str){

        int numVoms = 0;
        int numSpace= 0;
        // 定义标准
        String stadand = "[aAeEiIoOuU]";
        for (int i = 0; i < str.length(); i++) {
            //通过charAt()方法返回对应的字符
            char ch = str.charAt(i);
            if(ch == ' '){
                numSpace++;
            }
            //将字符转化成字符串类型调用matches()
            // matches()方法用于检测字符串是否匹配给定正则表达式
            else if((String.valueOf(ch)).matches(stadand)==true){
                numVoms++;
            }
        }
        System.out.println("VomNums:"+numVoms+"\n"+"Space:"+numSpace);

    }


}
