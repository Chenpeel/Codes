package CarModel;

abstract class Car {

    private String carName;
    private int carID;

    public Car(String carName1, int carID1) {
        carID=carID1;
        carName1= carName;
    }

    public void Car1(String carName,int carID){
        this.carName = carName;
        this.carID = carID;
    }    

    public String getCarName(){
        return carName;
    }
    public int getCarID(){
        return carID;
    }

    public abstract String getCapacity();

}

interface IHumanNum{

    public int getHumanNum();
    public String setHumanNum();
}


class PassageCar extends Car implements IHumanNum{
    private int humanNum;

    public PassageCar(int carID,String carName,int humanNum){
        super(carName,carID);
        this.humanNum=humanNum;
    }

    public void setHumanNum(int humanNum) {
        this.humanNum = humanNum;
    }
    
    @Override
    public int getHumanNum(){
        return humanNum;
    }

    @Override
    public String getCapacity() {
        return "载人数"+humanNum + "人";
    }


    @Override
    public String setHumanNum() {
        return null;
    }
}


public class CarTest{
    
    public static void main(String[] args) {
        
        Car[] cars ={new PassageCar(1,"AaoDi_A4",5),new PassageCar(2,"WuLing ",7)};
        int peopleNumTotal= 0;
        for (Car a : cars) {
            if (a instanceof PassageCar) {
                peopleNumTotal +=(((PassageCar) a).getHumanNum());
            }
        }
        System.out.println("共载" + peopleNumTotal + "人\n");   
    }
}