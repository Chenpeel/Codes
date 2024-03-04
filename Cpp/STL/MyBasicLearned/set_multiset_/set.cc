#include <iostream>
#include <string>
#include <set>

using namespace std;
class Person{

public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};
//仿函数
class m_compare{
public:

    bool operator()(const Person&p1,const Person&p2){
        return p1.age > p2.age;
    }

    // bool operator()(const int a,const int b){
    //     return a>b;
    // }
    

};

// void print(set<int>s){
//         for(set<int>::iterator it =s.begin();it!=s.end();it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;
// }
void print(set<Person,m_compare>s){
        for(set<Person,m_compare>::iterator it =s.begin();it !=s.end();it++){
        cout<<it->name<<":"<<it->age<<" ";
    }
    cout<<endl;
}

void test_person(){
    set<Person,m_compare> s;

    Person p1("恁爹",40);
    Person p2("恁娘",38);
    Person p3("你",12);
    Person p4("恁哥",20);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    print(s);
}




void test_default(){
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);

    // set<int,m_compare> s1;
    // s1.insert(1);
    // s1.insert(3);
    // s1.insert(2);

    //swap(set1,set2);
    //find(key) ; which return iterater ifnfound return set.end();
    //count(key) ;

}

int main(){
    test_person();
    // test_default();
    return 0;
}