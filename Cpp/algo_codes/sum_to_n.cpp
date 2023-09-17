#include<iostream>

int Q(int n,int m){
    if(m==1||n==1) return 1;  //边界1: Q(1,m)=Q(n,1)=1
    if(m==n&&n>1){            //边界2: Q(n,n)=Q(n,n-1)
        return Q(n,n-1)+1;
    }
    else{
        return Q(n-m,m)+Q(n,m-1);
    }                         //递归式
}
int sum_to_n(int n){
    if(n<0){
        std::cout<<"Illegal Input"<<std::endl;
    }
    return Q(n,n);//
}
