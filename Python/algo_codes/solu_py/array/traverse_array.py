class Solutions:
    
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        _max = count = 0
        for i in nums:
            count = (count + i) * i  # 遇0得0,遇1加1
            if count > _max:
                _max = count
        return _max

    def findPoisonedDuration(self, timeSeries: list[int], duration: int) -> int:
        t = 0
        if len(timeSeries) == 1:
            return duration
        last = timeSeries[0]
        for fast in timeSeries[1:]:
            if fast - last > duration:
                t += duration
            else:
                t += fast - last
            last = fast
        return t + duration

    def thirdMax(self, nums: list[int]) -> int:
        nums = list(set(nums))
        nums.sort(reverse=True)
        return nums[0] if len(nums) < 3 else nums[2]

    def maximumProduct(self , nums :list[int])->int:
        nums.sort(reverse=True)
        k = nums[0]*nums[1]*nums[2]
        i = nums[0]*nums[-1]*nums[-2]
        return i if i>k else k
        