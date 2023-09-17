#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Person {
public:
    Person(string name,int score){
        this->score = score;
        this->name = name;
    }
    string name;
    int id;
    int score;
};

void creatPerson(vector<Person>&v){
    //引用传递&v
    string nameSeed = "ABCDE";
    for(int i =0;i<5;i++){
        string name = "xuanshou : ";
        name += nameSeed[i];

        int score = 0;

        Person p(name,score);
        v.push_back(p);
    }
}

void test(){
    vector<Person> v;
    creatPerson(v);
    for(vector<Person>::iterator it=v.begin();it!= v.end();it++){
        cout<< (*it).name<<"     : "<<(*it).score<<endl;
    }

    for(vector<Person>::iterator it=v.begin();it!= v.end();it++){
        deque<int>d;
        for(int i =0;i<10;i++){
            int score = rand()%41 +60 ;
            d.push_back(score);
        }
        for(deque<int>::iterator it=d.begin();it!= d.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;

        //sort
        sort(d.begin(),d.end());
        //remove highest lowest
        d.pop_back();
        d.pop_front();

        //取平均
        int sum  =0;
        for(deque<int>::iterator it=d.begin();it!= d.end();it++){
            sum += *it;
        }
        int avg = sum / d.size();//8个
        it->score = avg;
    }
    for(vector<Person>::iterator it=v.begin();it!= v.end();it++){
        cout<< (*it).name<<"     : "<<(*it).score<<endl;
    }

}
int main(){
    test();
    return 0;
}