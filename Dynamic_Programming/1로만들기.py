n = int(input())

dp = [0] * (10**6 + 1)

for i in range(2, n+1):
    if i % 6 == 0:
        tempMin = min(dp[i//3] + 1, dp[i//2] + 1)
        dp[i] = min(dp[i-1]+1, tempMin)
    elif i % 3 == 0:
        dp[i] = min(dp[i-1] + 1, dp[i//3] + 1)
    elif i % 2 == 0:
        dp[i] = min(dp[i-1] + 1, dp[i//2] + 1)
    else:
        dp[i] = dp[i-1] + 1

print(dp[n])
