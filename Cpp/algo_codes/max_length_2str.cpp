#include <iostream>
using std::string;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

string max_length_2str(string str1, string str2) {
  int l1 = str1.size(), l2 = str2.size();
  int n = min(l1, l2);
  int dp[n][n];
  string res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = n - 1; j > 0; j--) {
      if (str1[i] == str2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        res = str1[i] + res;
      }
      dp[i][i] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  return res;
}

int main() {
  string str1 = "ftgashasmd";
  string str2 = "gjlah ibpqywnc";
  std::cout << max_length_2str(str1, str2) << std::endl;
  return 0;
}