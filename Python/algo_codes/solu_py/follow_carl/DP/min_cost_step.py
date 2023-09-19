# https://leetcode.cn/problems/min-cost-climbing-stairs/submissions/

def minCostClimbingStairs(self,cost:list[int])->int:
    def min(a:int,b:int)->int:
        return a if a<=b else b
    res = [0]*(len(cost)+1)

    for i in range(2,len(cost)+1):
        res[i] = min(res[i-1]+cost[i-1],res[i-2]+cost[i-2])

    return res[len(cost)]

cost = [10,15,20]
print(minCostClimbingStairs(None,cost))

