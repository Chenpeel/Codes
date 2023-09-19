class Solutions:
    def longestArithSeqLength(self, nums: list[int]) -> int:
        n = len(nums)
        dp = [[1]*1001 for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for k in range(i):
                j = nums[i]-nums[k] + 500 #等差下标
                dp[i][j] = max(dp[i][j], dp[k][j]+1)
                ans = max(ans, dp[i][j])
        return ans
