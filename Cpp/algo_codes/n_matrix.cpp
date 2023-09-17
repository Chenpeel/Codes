// 函数仅实现dp的过程 输入默认为二维数组 代表矩阵的行列
#include <iostream>

#include "random.h"

int n_matrix(int n, int *m) {
  int dp[n + 1][n + 1];
  int res[n];
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
    dp[i][i + 1] = m[i] * m[i + 1] * m[i + 2];
  }
  int k = 0, temp = 0;
  // 垃圾代码改的 能不能跑看命
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 1; j < n - i + 1; j++) {
      k = i + j;
      dp[j][k] = dp[j][j] + dp[j + 1][k] + m[j] * m[j + 1] * m[j + 2];
      res[j] = j;
      for (int l = j + 1; l < k; l++) {
        temp = dp[j][l] + dp[l + 1][k] + m[j] * m[l + 1] * m[k + 2];
        if (temp < dp[j][k]) {
          dp[j][k] = temp;
          res[k] = k;
        }
      }
    }
  }
  return res[n];
}
int main() {
  int a[5];
  for (int i = 0; i < 5; i++) {
    a[i] = rd_int();
  }
  cout << n_matrix(4, a) << endl;
  return 0;
}