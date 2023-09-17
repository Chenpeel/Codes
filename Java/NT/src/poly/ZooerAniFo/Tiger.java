public class Tiger extends Animal {
    public Tiger(String name){
        super(name);
    }
    public void eat(Food food){
        System.out.println(this.getname()+"在吃"+food.getname());
    }
    
}
