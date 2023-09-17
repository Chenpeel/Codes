#include<iostream>
using std::cin;
using std::cout;
using std::endl;
//basic
long long factorial(int n){
    if(n = 0 ){return 1;}
    return factorial(n-1);
}

//dp
#include<vector>
using std::vector;
long long factorial(int n){
    if(n == 0 || n==1) return 1;
    vector<long long>v(n+1);
    v[0] = 1;
    v[1] = 1;
    for(int i =2 ; i<n+2;i++){
        v[i]= v[i-1]*i; 
    }
    return v[n+1];
}

//three nums
long long factorial(int n){
    long long res = 1;
    if(n==0||n==1) return res;
    long long pre =1, ppre=1;
    for(int i = 2;i<n+1;i++){
        ppre = res;
        pre = i;
        res = pre * ppre;
    }
    return res;
}