public class BankAccount {
    public static void main(String[] args) {
        Account account =new Account("A", 1111, 0);

        account.setBalance(account.getBalance()+1000);
        System.out.println(account);
        account.deposit(100);
        System.out.println(account);
        account.withdraw(200);
        System.out.println(account);
    }
}




class Account{
    private String name;
    private int number;
    private float balance;


    public Account(String name,int number,float balance){
        this.name = name;
        this.number= number;
        this.balance= balance;
    }
    
    public Account(){
        this("",0,0);
    }


    public String getName(){
        return name;
    }
    public int getnumSber(){
        return number;
    }
    public float getBalance(){
        return balance;
    }


    public void setName(String newName){
        name  = newName;
    }
    public void setNumber(int newNumber){
        number  = newNumber;
    }
    public void setBalance(float newBalance){
        balance = newBalance;
    }

    //方法
    public float deposit(float amount){
        balance += amount;
        return balance;
    }


    public float withdraw(int amount){
        balance -= amount;
        return balance;
    }

    
    public String toString(){
        return ("用户名:"+ name + " 账号:" +number+ " 余额:"+ balance);
    }

}