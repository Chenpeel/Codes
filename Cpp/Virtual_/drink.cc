#include <iostream>
using namespace std;

//多态 虚函数

class AbstractDrinking{
    public:
    virtual ~AbstractDrinking(){
        //
    }

    virtual void Boiled() = 0;
    virtual void Brew()=0;
    virtual void PourInCup()=0;
    virtual void PutSomeTing()=0;
    
    void MakeDrink(){
        Boiled();
        Brew();
        PourInCup();
        PutSomeTing();
    }
};
//coffee
class Coffee : public AbstractDrinking{
    public:
    virtual void Boiled(){ cout << "1"<<endl;}
    virtual void Brew(){ cout << "2"<<endl;}
    virtual void PourInCup(){ cout << "3"<<endl;}
    virtual void PutSomeTing(){ cout << "4"<<endl;}
};

void doWork(AbstractDrinking *abs){
    abs->MakeDrink();
    delete abs;
}

void test01(){
    doWork(new Coffee);
    cout <<"5"<<endl;
}

int main(){
    test01();
    return 0;
}