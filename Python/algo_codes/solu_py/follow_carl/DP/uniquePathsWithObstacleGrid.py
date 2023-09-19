def uniquePathsWithObstacles(self,obstacleGrid:list[list[int]])->int:
    m,n = len(obstacleGrid),len(obstacleGrid[0])
    dp = [[0]*n for _ in range(m)]

    for i in range (m):
        for j in range(n):
            if i ==0 and j== 0 and not obstacleGrid[i][j]:
                dp[i][j]= 1
            elif i ==0 and not obstacleGrid[0][j]:
                dp[i][j] = dp[i][j-1]
            elif j==0 and not obstacleGrid[i][0]:
                dp[i][j] = dp[i-1][j]
            elif not obstacleGrid[i][j]:
                dp[i][j] =dp[i][j-1]+dp[i-1][j]
            else:
                continue
    return dp[m-1][n-1]


obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]

print(uniquePathsWithObstacles(None,obstacleGrid))
