class Solutions:
    '''645'''
    # math_mathod

    def _findErrorNums(self, nums: list[int]) -> list[int]:
        sum1 = sum2 = 0
        n = len(nums)
        sum1 = sum(nums)
        for i in nums:
            sum2 += i*i
        a = n*(n+1)/2 - sum1
        b = n*(n+1)*(2*n+1)/6 - sum2
        return [int((b-a*a)/(2*a)), int((b+a*a)/(2*a))]
    # set()去重

    def findErrorNums(self, nums: list[int]) -> list[int]:
        s = sum(set(nums))
        n = sum(nums)
        temp = 0
        for i in range(1, len(nums)+1):
            temp += i
        return [n-s, temp-s]

    '''697'''

    def findShortestSubArray(self, nums: list[int]) -> int:
        addr = {}   # addr 标记位置
        for i in range(len(nums)):
            if nums[i] not in addr:
                addr[nums[i]] = [i]
            else:
                addr[nums[i]].append(i)  # 标记每个元素出现的位置
            times_max = 0
        for i in addr:
            times_max = max(times_max, len(addr[i]))  # 最大出现次数
        res = len(nums)
        for i in addr:
            if len(addr[i]) == times_max:
                res = min(res, addr[i][-1]-addr[i][0]+1)  # 找出最短末位减初位
        return res

    '''
    448
    https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
    '''

    def _findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        # extra_list to mark
        n = len(nums)
        l = [1] * n
        res = []
        for i in nums:
            l[i-1] = 0
        for i in range(n):
            if l[i] == 0:
                res.append(i+1)
        return res

    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        nums_sta = [i for i in range(1, len(nums)+1)]
        return list(set(nums_sta)-set(nums))    # use set() to optimize

    '''
    442
    https://leetcode.cn/problems/find-all-duplicates-in-an-array/
    '''

    def _findDuplicates(self, nums: list[int]) -> list[int]:
        n = len(nums)
        res = []
        nums.sort()  # sort()时间复杂度O(nlog(n))
        for i in range(n):
            if i+1 < n and nums[i] == nums[i+1]:
                res.append(nums[i])
        return res

    def findDuplicates(self, nums: list[int]) -> list[int]:
        # 遍历一次,相应位置的数加上长度,筛选出2n~3n+1的数字,当然,数字太大会溢出
        n = len(nums)
        res = []
        for i in nums:
            nums[(i-1) % n] = nums[(i-1) % n]+n
        for i in range(n):
            if 2*n < nums[i] < 3*n+1:
                res.append(i+1)
        return res

    '''
    41
    https://leetcode.cn/problems/first-missing-positive/
    '''

    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)
        for i in range(n):
            # 第一趟所有负数置为n+1
            if nums[i] <= 0:
                nums[i] = n+1

        for i in range(n):
            # 第二趟把所有的num用num-1的下标置为负数为正的num的num+1就是结果
            num = abs(nums[i])
            if num <= n:
                nums[num-1] = -abs(nums[num-1])

        for i in range(n):
            # 第三趟找出num
            if nums[i] > 0:
                return i+1
        return n+1

    '''
    274
    https://leetcode.cn/problems/h-index/
    '''

    def hIndex(self, citation: list[int]) -> int:
        n = len(citation)
        citation.sort()
        for i in range(n):
            h = n - i
            if h <= citation[i]:
                return h
        return 0
