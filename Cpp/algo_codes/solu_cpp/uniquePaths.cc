#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int uniquePaths(int m, int n) {
  int dp[m][n];
  // 由于每个格子的第一行第一列都只有一种走法
  for (int i = 0; i < m; i++) dp[i][0] = 1;
  for (int j = 0; j < n; j++) dp[0][j] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}

int main() {
  int m, n;
  m = 3;
  n = 7;
  cout << uniquePaths(m, n) << endl;
  return 0;
}
