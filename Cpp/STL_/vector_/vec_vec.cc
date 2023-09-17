#include <iostream>
#include <vector>

using namespace std;

void test01(){
    //<int> 后必须有" "
    vector<vector<int> >v;

    // 内层vec
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    //载入外层vec
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //遍历
    for(vector<vector<int> >::iterator It= v.begin();It!=v.end();It++){
        for(vector<int>::iterator it = (*It).begin();it!=(*It).end();it++){
            cout<< *it <<" ";
        }
        cout<<endl;
    }
    
}
int  main (){
    test01();
    return 0;
}