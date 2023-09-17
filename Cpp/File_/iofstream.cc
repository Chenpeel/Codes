#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/**
 * ios::in      为读文件打开
 * ios::out     为写文件打开
 * ios::ate     初始位置：尾
 * ios::app     追加方式写文件
 * ios::trunc   如果文件存在，先删除再创建
 * ios::binary  二进制方式
 * 
 */

void writefile(){
    ofstream ofs;
    ofs.open("./1.txt",ios::trunc);
    ofs<<"1"<<endl;
    ofs<<"2"<<endl;
    ofs<<"3"<<endl;
}

void readfile(){
    ifstream ifs;
    ifs.open("./1.txt",ios::in);
    if(!ifs.is_open()) return ;
    //1
    char buf_1[1024]={ 0 };
    while (ifs >> buf_1)
    {
        cout<<buf_1 <<endl;
    }
    /**
    //2
    ifs.open("./1.txt",ios::in);
    if(!ifs.is_open()) return ;
    char buf_2[1024]={ 0 };
    while (ifs.getline(buf_2,sizeof(buf_2)))
    {
        cout<<buf_2<<endl;
    }

    //3
    string buf_3;
    while (getline(buf_3))
    {
        cout<<buf_3<<endl;
    }
    //4
    char c;
    while ((c= ifs.get())!=EOF)
    {
        cout<<c<<endl;
    }
    */
    
}
int main(){
    writefile();
    readfile();
    return 0;
 }