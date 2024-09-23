#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int min(int a,int b){
	return a<b?a:b;
}
int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int> dp;
	dp.push_back(0);
	dp.push_back(0);
	for(int i=2;i<n;i++){
	dp.push_back(min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]));
	cout<<dp[i]<<" " ;
	}
	cout<<dp[n]<<endl;
	return dp[n];
}

int main() {
  vector<int> cost;
  int len = rand()%100;
  for (int i = 0; i < len+1; i++) {
  	cost.push_back(rand() % 50 + 1);
  	cout<<cost[i]<<" ";
  }
  cout<<endl;
  minCostClimbingStairs(cost);
  return 0;
}
