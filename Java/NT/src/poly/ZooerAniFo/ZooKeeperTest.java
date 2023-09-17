public class ZooKeeperTest {
 
    public static void main(String[] args) {

        ZooKeeper zooKeeper = new ZooKeeper();

        Animal animal = new Monkey("金丝猴");
       //向下转型
        Monkey monkey = (Monkey)animal;
        monkey.play();

        Food food = new Banana("泰国香蕉");
        zooKeeper.feed(animal, food);
        
        animal = new Tiger("东北虎");
        if(animal instanceof Tiger){
            //解决类型转换异常
            // Tiger tiger = (Tiger) animal;
        }
        food = new Meat("野猪肉");
        zooKeeper.feed(animal, food);


        //形参多态和返回值多态
        Animal animalReturnValue = zooKeeper.getAnimal(monkey);
            System.out.println("动物信息:" + animalReturnValue.getname());
 
    }
}
