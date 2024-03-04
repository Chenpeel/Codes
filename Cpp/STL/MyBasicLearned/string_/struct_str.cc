#include <iostream>
//#include <string>

using namespace std;
/**
 * string() //默认构造
 * string(const char * str) //字符串s初始化
 * string(const string & str)  //使用一个string初始化另一个string
 * string(int n,char c) //使用n个字符c初始化
 */

void test01(){
    //
    string s1;
    //
    const char * str ="hello world ?";
    string s2(str);
    cout<<s2<<endl;
    //
    string s3(s2);
    cout<<s3<<endl;
    //
    string s4(10,'a');
    cout<<s4<<endl;
}

int main (){
    test01();
    return 0;
}