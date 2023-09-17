public abstract class Animal {

    private String name;

    public String getname(){
        return name;
    }
    public void setname(String name){
        this.name = name;
    }
    public Animal(){

    }
    public Animal(String name){
        this.name = name;
    }
    public abstract void eat(Food food);
}
