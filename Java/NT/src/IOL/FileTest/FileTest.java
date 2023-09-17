package FileTest;
import java.io.File;
// import java.sql.Date;
public class FileTest {
    public static void main(String[] args) throws Exception {

    // File directory = new File("/Users/chen/Desktop/Auto./java/cc.txt");
    // System.out.println(""+directory);
    /**
     * 创建新文件（指明路径）
     */
    // File file = new File("/Users/chen/Desktop/Auto./java/1.txt");
    // boolean rst = file.createNewFile();
    // System.out.println(rst);

    /**
     * 创建新文件（未指明路径）路径:/Desktop/Java/TAT.txt
     */
    // File file3 =new File("TAT.txt");
    // boolean rst1 = file3.createNewFile();
    // System.out.println(rst1);

    /**
     * 创建新文件夹（指明路径）
     */
    // File file1 = new File("/Users/chen/Desktop/Auto./java/cc/c1");
    // boolean rst2 = file1.mkdir();
    // System.out.println(rst2);
    /**
     * 创建多级新文件夹（指明路径）
     */
    // File file1 = new File("/Users/chen/Desktop/Auto./java/cc/c1");
    // boolean rst3 =  file1.mkdirs();
    // System.out.println(rst3);
    /**
     * 改名
     */
    // File file2 = new File("/Users/chen/Desktop/Java/QAQ.txt");
    // file2.renameTo(new File ("QAQ.txt"));
    /**
     * 获取路径
     *
     */
    // String  absolutePath = file2.getAbsolutePath();
    // System.out.println(absolutePath);
    /**
     * 获取文件长度
     */
    // System.out.println(file2.length());

    /**
     * 获取最后更改时间（过时）
     */
    // long time = file2.lastModified(); 
    // Date t = new Date(time);
    // System.out.println(t.toLocaleString());


    /**
     * 读取下属文件
     */
    File file4 = new File("/Users/chen/Desktop/Auto./离散");
    File[] listFiles = file4.listFiles();
    for (File file5 : listFiles) {
        System.out.println(file5);
    }


    
}
}
