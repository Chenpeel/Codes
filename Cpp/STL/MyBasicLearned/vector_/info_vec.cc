#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MyPrint(int val){
    cout<<val<<endl;
}
void test01(){
    vector <int> v;
    //向容器插入元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    //通过迭代器访问容器的元素
    vector<int>::iterator it_begin=v.begin();//访问容器中的首元素
    vector<int>::iterator it_end = v.end();//访问容器中的最后元素的下个位置，类似stack中的stack.top()

    //遍历
    while (it_begin != it_end)
    {
        cout<<*it_begin<<endl;
        it_begin++;
    }
    
    //常用遍历
    for(vector<int>::iterator it= v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    for_each(v.begin(),v.end(),MyPrint); 

}
int  main(){
    test01();
    return 0;
}