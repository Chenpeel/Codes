#include <iostream>
#include <vector>
#include <string>

using namespace std;
//存放自定义类型
class Person{
    public :
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void test01(){
    vector<Person> v;
    Person p1("aaa",11);
    Person p2("bbb",22);
    Person p3("ccc",33);
    Person p4("ddd",44);
    Person p5("eee",55);
    //
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for(vector<Person>::iterator it= v.begin();it!=v.end();it++){
        cout<<"name:"<<it->m_Name<<"  age:"<<it->m_Age<<endl;
    }
}

int main(){
    test01();
    return 0;
}