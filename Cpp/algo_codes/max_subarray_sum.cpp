#include <iostream>
// 分治
int max(int a, int b, int c) {
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int maxCrossingSubarraySum(int A[], int low, int mid, int high) {
  int left_sum = 0;
  int right_sum = 0;
  int sum = 0;

  for (int i = mid; i >= low; i--) {
    sum += A[i];
    if (sum > left_sum) left_sum = sum;
  }

  sum = 0;
  for (int i = mid + 1; i <= high; i++) {
    sum += A[i];
    if (sum > right_sum) right_sum = sum;
  }

  return left_sum + right_sum;
}


int max_subarray_sum(int A[], int low, int high) {
  if (low == high) return A[low];

  int mid = (low + high) / 2;

  int left_sum = max_subarray_sum(A, low, mid);  // 递归计算左子序列最大子段和
  int right_sum = max_subarray_sum(A, mid + 1, high);  // 递归计算右子序列最大子段和
  int cross_sum =
      maxCrossingSubarraySum(A, low, mid, high);  // 跨越中间位置的最大子段和

  return max(left_sum, right_sum, cross_sum);  // 返回三者中的最大值
}

// dp
int max(int a, int b) {
  return a > b ? a : b;
}
int max_subarray_sum(int list[], int n) {
  int dp[n + 1];
  dp[0] = 0;
  int res = list[0];
  for (int i = 1; i < n + 1; i++) {
    dp[i] = max(dp[i - 1] + list[i - 1], dp[i - 1]);
    res = max(dp[i], res);
  }
  return res;
}


int main(){
  
  return 0;
}