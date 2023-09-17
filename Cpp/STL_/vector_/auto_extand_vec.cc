#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>&v){
    for (vector<int>::iterator it = v.begin();it !=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test(){
    vector<int> v1;
    for (int i = 0; i<10;i++){
        v1.push_back(i);
    }
    print(v1);
    vector<int>v2(v1.begin(),v1.end());//构造
    print(v2);
    vector<int>v3(10,100);//十个100
    print(v3);
    v3 = v2;
    print(v3);
    v3.assign(10,100);//赋值 
    print(v3);
    
    v1.insert(v1.end(),10);   //插入,首参是迭代器
    print(v1);
    
    v1.pop_back();//尾删
    print(v1);

    v1.erase(v1.begin()+9,v1.end());
    //v1.erase(v1.begin(),v1.end() == v1.clear()) 必须提供迭代器参数
    print(v1);
    v1.erase(v1.begin());

}
int main(){
    test();
    return 0;
}