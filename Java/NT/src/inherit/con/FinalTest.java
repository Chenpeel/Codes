package con;

public class FinalTest {
    public static void main(String[] args) {
        final int DEFAULT_VALUE = 10;
        System.out.println(DEFAULT_VALUE);
        
        final  Order order = new Order();
        order.setOrderId("tb001");
        System.out.println("xinxi"+order.getOrderId());

    }
}


class Order {
    public Order(){}


    private String orderId;
    
    public String getOrderId(){
        return orderId;
    }

    public void setOrderId(String orderId){
        this.orderId = orderId;
    }
}