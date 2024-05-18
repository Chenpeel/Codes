#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int max_num(vector<int>&arr){
        int max_num = 0;
        for(int num:arr){
            max_num = std::max(num,max_num);
        }
        return max_num;
    }


int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(n<=k) return max_num(arr); 
        std::queue<int> q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
        
        int res = q.front(), times = 0,tmp = 0;
        q.pop();

        while(times<k){
            if(res>=q.front()){
                tmp = q.front();
                q.pop();
                q.push(tmp);
                times++;
                cout<<"res"<<res<<",times"<<times<<endl;

            }
            else{
                q.push(res);
                res = q.front();
                q.pop();
                times=1;
            }
        }
        return res;
    }

int main(){
    vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;
    cout<<getWinner(arr,k)<<endl;
}
