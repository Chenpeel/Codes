#include<iostream>
using std::cout;
using std::endl;

long fib(int n) {
  long dp[n + 1];
  dp[0] = 0;
  if (n == 0) return 0;
  dp[1] = 1;
  if (n == 1) return 1;
  for (int i = 2; i < n + 1; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main(){
	int n = 50;
	for(int i = 0;i<n+1;i++){
	cout<<fib(i)<<endl;
	}
}

