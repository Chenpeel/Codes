#include <iostream>
#include <map>

using namespace std;

class mycompare{
public:
    bool operator()(int i ,int j){
        return i>j;
    }
};

void test_default(){
    map <int,int,mycompare>m;     
    //the  m.first is the key of map
    m.insert(make_pair(1,10)); 
    //m.insert(pair<int,int>(1,10)) while use my_compare only you could use the "make_pair()"
    m.insert(make_pair(2,11));
    m.insert(make_pair(5,9));

    for(map<int,int,mycompare>::iterator it =m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    //empty()
    //size()
    //swap()
    //find()
    //count()
}




int main(){
    test_default();
    return 0;
}