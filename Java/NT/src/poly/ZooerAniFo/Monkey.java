public class Monkey extends Animal {
    public Monkey(String name){
        super(name);
    }
    public void eat(Food food){
        System.out.println(this.getname()+"在吃"+food.getname());
    }
    public void play(){
        System.out.println(this.getname()+"正在玩杂耍");
    }


}
