#include <iostream>

int resource_alloc(int w[], int v[], int n, int a) {
  int dp[a + 1];
  std::fill(dp, dp + a + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = a; j >= w[i]; j--) {
      dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  return dp[a];
}

int main() { return 0; }
