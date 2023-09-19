#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int max(int a,int b){
	return a >= b?a:b;
}

int max(int a , int b ,int c){
	return max(a,b) >= c ? max(a,b) : c;
}

int integerBreak(int n){
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	for(int i = 3;i<n+1;i++){
		for(int j = 1 ; j<=i/2;j++){
			dp[i] = max(j*dp[i-j],j*(i-j),dp[i]);
			cout<<i<<":" <<dp[i]<<endl;
		}
	}
	cout<<dp[3]<<endl;
	return dp[n];

}

int main(){
	int n = 10;
	cout<<integerBreak(n)<<endl;
	return 0;
}
