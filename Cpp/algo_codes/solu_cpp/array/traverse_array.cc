#ifndef CPP_TRAVERSE_ARRAY
#define CPP_TRAVERSE_ARRAY

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  // 485
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0, count = 0;
    for (auto c : nums) {
      if (c) count++;
      max = max > count ? max : count;
      if (!c) count = 0;
    }
    return max;
  }

  // 495
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int time_sum = 0;
    int n = timeSeries.size();
    for (int i = 0; i < n - 1; i++) {
      if ((timeSeries[i + 1] - timeSeries[i]) > duration)
        time_sum += duration;
      else
        time_sum += timeSeries[i + 1] - timeSeries[i];
    }
    time_sum += duration;
    return time_sum;
  }

  // 414
  int thirdMax(vector<int>& nums) {
    long max = LONG_MIN, mid_max = max, min_max = max;
    for (long n : nums) {
      if (n > max) {
        min_max = mid_max;
        mid_max = max;
        max = n;
      } else if (max > n && n > mid_max) {
        min_max = mid_max;
        mid_max = n;
      } else if (mid_max > n && n > min_max) {
        min_max = n;
      }
    }
    return min_max == LONG_MIN ? max : min_max;
  }
  int _thirdMax(vector<int>& nums) {
    set<int> s;
    for (auto num : nums) {
      s.insert(num);
    }
    set<int>::iterator it = s.end();
    return s.size() < 3 ? *(--it) : *(--(--(--it)));
  }

  // 628 本题是414的继承
  int maximumProduct(vector<int>& nums) {
    long max = LONG_MIN, mid_max = max, min_max = max, min = INT_MAX,
         pre_min = min;
    for (long n : nums) {
      if (n >= max) {
        min_max = mid_max;
        mid_max = max;
        max = n;
      } else if (max > n && n >= mid_max) {
        min_max = mid_max;
        mid_max = n;
      } else if (mid_max > n && n >= min_max) {
        min_max = n;
      }
      if (n < min) {
        pre_min = min;
        min = n;
      } else if (n >= min && n < pre_min) {
        pre_min = n;
      }
    }
    return min * pre_min * max > max * mid_max * min_max
               ? min * pre_min * max
               : max * mid_max * min_max;
  }
};

#endif