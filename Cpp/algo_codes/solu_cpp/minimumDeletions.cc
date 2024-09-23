#include<iostream>
#include<string>
using namespace std;
/**
 * @brief 
 * This solutions is the 1653.Minimum Deletions to Make String Balanced
 * 
 */
class Sollution{
public:
    int miniDeletions_1(string s){
        int n = s.size();
        int f[n+1];
        memset(f,0,sizeof(f));
        int b = 0;
        for(int i = 1;i<=n;i++){
            //i=0导致越界
            if(s[i-1] =='b'){
                f[i]=f[i-1];
                ++b;
            }
            else{
                f[i] = min(f[i-1]+1,b);
            }
        }
        return f[n];
    }

    int miniDeletions_2(string s){
        int ans=0,n=0;
        for (char& c :s){
            if(c=='b'){
                n++;
            }
            else{
                ans= min(ans+1,n);
            }
        }
        return ans;   
    }

};


int main(){
    cout<<"a or b only!"<<endl;
    string s;
    cin>>s;
    Sollution str;
    cout<<str.miniDeletions_1(s)<<endl;
    cout<<str.miniDeletions_2(s)<<endl;
    return 0;
}
