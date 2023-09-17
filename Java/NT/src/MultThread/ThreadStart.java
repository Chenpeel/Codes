// // import java.util.Random;

// public class ThreadStart  {
//     public static void main(String[] args) {
        
//         new CustomThread().start();
//         new Thread(new Reverce()).start();

//         // CustomThread customThread = new CustomThread();
//         // customThread.run();
//         // System.out.println("");
//         // Reverce reverce = new Reverce();
//         // reverce.run();
//         // System.out.println("");
//     }
// }


// class CustomThread extends Thread{
//     public void run(){
//         for (int i = 2; i <= 100; i++) {
//             boolean isPrime = true;
//             for (int j = 2; j <= i - 1; j++) {
//                 if (i % j == 0 ) {
//                     isPrime = false;
//                 }
//             }
//             if (isPrime) {
//                 System.out.print(i + "\t");
//             }
//              //随机休眠1-1000ms
//             //  Random rd = new Random();
//             //  int b = rd.nextInt(1000)+1;
//             int b = (int)(Math.random()*1000);
//              try{
//                  Thread.sleep(b);
//              }catch(InterruptedException s){
//                  s.printStackTrace();
//              }
//         }
//     }
// }
// class Reverce  implements Runnable {
//     public void run(){
//         for(int i =20 ; i>0 ;i--){

//             System.out.print(i+"\t");
//             //随机休眠1-1000ms
//             // Random rd = new Random();
//             // int b = rd.nextInt(1000)+1;
//             int b = (int )(Math.random()*1000);
//             try{
//                 Thread.sleep(b);
//             }catch(InterruptedException s){
//                 s.printStackTrace();
//             }
//         }
//     }
// }
