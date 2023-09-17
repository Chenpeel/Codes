package abstacts.test;

public abstract class Animal {
    
    private String nationality;
    
    public String getnationality(){
        return nationality;
    }
    
    public void setnationality(String nationality){
        this.nationality=nationality;
    }

    public Animal(){

    }

    public Animal(String nationality){
        this.nationality = nationality;
    }


    public abstract void eat();
    

    public abstract void sleep();
    
}
