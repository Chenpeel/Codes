#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  if (obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0]) return 0;

  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m && !obstacleGrid[i][0]; i++) dp[i][0] = 1;
  for (int j = 0; j < n && !obstacleGrid[0][j]; j++) dp[0][j] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (obstacleGrid[i][j]) continue;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

int main() { return 0; }
