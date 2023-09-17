public class Prie {
    public static void main(String[] args) {
        String text = "I love you";
        byte[] array =text.getBytes();
        for(int i =0 ; i<array.length;i++){
            array[i]&=110;
        };
        System.out.println("Before:"+ text);
        System.out.println("After:"+ new String(array));
    }
}
