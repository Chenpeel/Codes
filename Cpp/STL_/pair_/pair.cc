#include <iostream>
#include <string>
using namespace std;

void test(){
    pair<string,int> p("Tom",20);
    pair<string,int>p2=make_pair("Jerry",20);
    cout<<p.first<<p.second;
}


int main(){
    test();
    return 0; 
}