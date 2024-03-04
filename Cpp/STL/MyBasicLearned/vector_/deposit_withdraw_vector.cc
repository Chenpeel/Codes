#include<iostream>
#include<vector>

using namespace std;

void test(){
    vector<int> v1;
    for (int i = 0;i<10;i++){
        v1.push_back(i);
    }



    for (int i = 0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    //at(i)访问
    for(int i = 0;i<v1.size();i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;



    cout<<"first: "<<v1.front()<<endl;
    cout<<"last: "<<v1.back()<<endl;
    
}

int main(){
    test();
    return 0;
}