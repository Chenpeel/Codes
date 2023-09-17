#include <iostream>


int max(int a, int b) {
  return a > b ? a : b;
}
//0-1背包问题
int bool_knapsack(int v[], int w[], int n, int W) {
  int dp[n + 1][W + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (w[i - 1] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][W];
}

//背包问题
 
int* percent(int v[], int w[], int n) {
  int* p = new int[n];
  for (int i = 0; i < n; i++) {
    p[i] = (double)(v[i] / w[i]);
  }
  return p;
}


int knapsack(int v[], int w[], int n, int W) {
  int* p = percent(v, w, n);
  std::sort(p, p+n);
  int res = 0;
  int ww = 0;
  for (int i = 0; i < n; i++) {
    if (ww >= W) { break; }
    if (W - ww >= w[i]) {
      ww += w[i];
      res += v[i];
    }
    if (W - ww < w[i]) {
      res += (W - ww) * p[i];
      ww = W;
    }
  }
  delete[] p;
  return res;
}

int main(){
  return 0;
}