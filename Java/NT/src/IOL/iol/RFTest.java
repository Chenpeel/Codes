package iol;

import java.io.FileInputStream;
import java.io.IOException;

public class RFTest {
    public static void main(String[] args) throws IOException{
        String filePath ="/Users/chen/Desktop/Java/QAQ.txt" ;
        // int rdt= 0;
        byte[] buf = new byte[8];
        int rel = 0;
        FileInputStream fileInputStream = null;
        try{
            fileInputStream = new FileInputStream(filePath);
            while((fileInputStream.read())!=-1){
                System.out.println(new String( buf,0,rel));
            } 
        }catch(IOException e){
            e.printStackTrace();
    }finally{
        fileInputStream.close();
    }



    }
}


