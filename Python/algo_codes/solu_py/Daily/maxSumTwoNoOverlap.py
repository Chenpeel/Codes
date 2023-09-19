class Solution:
    def maxSumTwoNoOverlap(self, nums: list[int], firstLen: int, secondLen: int) -> int:
        breakpoint()
        pre_sum = [0]
        for num in nums:
            pre_sum.append(pre_sum[-1]+num)
        n = len(nums)
        ans = 0
        for i in range(n - firstLen + 1):
            sum1 = pre_sum[i+firstLen] - pre_sum[i]
            for j in range(n - secondLen+1):
                if i <= j < i+firstLen or j <= i < j+secondLen:
                    continue
                ans = max(ans, sum1+pre_sum[j+secondLen]-pre_sum[j])
        return ans
    nums = [0,6,5,2,2,5,1,9,4]
    firstLen = 1
    secondLen=2
    print(maxSumTwoNoOverlap(None,nums,firstLen,secondLen))