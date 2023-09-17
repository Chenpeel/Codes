import java.io.*;

public class ReadTXT{

    public static void main(String[] args) {
        //文本信息转为字符串，输入信息流
        String fileName = "/Users/chen/Desktop/Java/QAQ.txt",line;
        try {
            //输入流方法，读取文本信息
            BufferedReader in = new BufferedReader(new FileReader(fileName));
            line  = in.readLine();
            while (line != null) {
                System.out.println(line);
                //readLine()方法:读取输入流中信息，遇到回车截止
                line = in.readLine();
            }
            in.close();
        } catch (IOException e){
            System.out.println("Problem reading "+fileName);
        }
    }
    
}
