# def integerBreak(self,n:int)->int:
#     dp = [0]*(n+1)
#     dp[2] = 1
#     for i in range(3,n+1):
#         for j in range(1,i//2 +1):
#             dp[i] = max(j*(i-j),j*dp[i-j],dp[i])

#     return dp[n]

def integerBreak(self, n: int) -> int:
    if n <= 3:
        return n-1

    q, r = n//3, n % 3
    if r == 0:
        return 3**q
    elif r == 1:
        return 3**(q-1)*4
    else:
        return 3**q*2


n = 10
print(integerBreak(None, n))
