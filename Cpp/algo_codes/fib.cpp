#include<iostream>

//basic
long long fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return fib(n-1)+fib(n-2);
}

//math
#include <math.h>
long long fib(int n){
    return (long long int)(1/sqrt(5))*(pow((1+sqrt(5)),n)/2 -(pow((1-sqrt(5)),n)/2));
}

//dp
#include<vector>
using std::vector;
long long fib(int n){
    if(n == 0 || n==1) return 1;
    vector<long long>v(n+1);
    v[0] = 0;
    v[1] = 1;
    for(int i =2 ; i<n+2;i++){
        v[i]= v[i-1] + v[i-2]; 
    }
    return v[n+1];
}

//three nums
long long fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    long long res=0 , pre =1, ppre=0;
    for(int i = 2;i<n+1;i++){
        res = pre + ppre;
        ppre=pre;
        pre = res;
    }
    return res;
}
