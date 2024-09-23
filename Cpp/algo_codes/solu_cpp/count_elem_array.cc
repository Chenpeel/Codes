#ifndef COUNT_ELEM_ARRAY
#define COUNT_ELEM_ARRAY

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solutions {
 public:
  // 645
  // with the mathematical method perfectly solve:
  vector<int> findErrorNums(vector<int>& nums) {
    long long sum1 = 0;
    long long sum2 = 0;
    long long n = nums.size();
    for (auto n : nums) {
      sum1 += n;
      sum2 += n * n;
    }
    long long a = n * (n + 1) / 2 - sum1;
    long long b = n * (n + 1) * (2 * n + 1) / 6 - sum2;
    return {(int)((b - (a * a)) / 2 * a), (int)((b + a * a) / 2 * a)};
  }

  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (mp.count(nums[i])) {
        mp[nums[i]][0]++;
        mp[nums[i]][2]++;
      } else {
        mp[nums[i]] = {1, i, i};
      }
    }
    int maxNum = 0, minLen = 0;
    for (auto& [_, vec] : mp) {
      if (maxNum < vec[0]) {
        maxNum = vec[0];
        minLen = vec[2] - vec[1] + 1;
      } else if (maxNum == vec[0]) {
        if (minLen > vec[2] - vec[1] + 1) {
          minLen = vec[2] - vec[1] + 1;
        }
      }
    }
    return minLen;
  }
};

#endif