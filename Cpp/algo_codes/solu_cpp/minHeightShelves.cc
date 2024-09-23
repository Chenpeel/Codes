#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1, INT_MAX / 2);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i++) {
      int h = 0, w = 0;
      for (int j = i; j < n; j++) {
        w += books[j][0];
        if (w > shelfWidth) break;
        h = max(h, books[j][1]);
        dp[i] = min(dp[i], dp[j + 1] + h);
      }
    }
    return dp[0];
  }
};