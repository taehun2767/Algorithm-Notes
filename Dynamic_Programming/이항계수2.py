import sys
sys.setrecursionlimit(10**7)

n, k = map(int, input().split())

dp = [[-1] * _ for _ in range(1, n+2) ]

for i in range(1, n+1):
    dp[i][0] = 1
    dp[i][-1] = 1

def comb(n, k):

    if dp[n][k] != -1:
        return dp[n][k]
    else:
        dp[n][k] = (comb(n-1, k) + comb(n-1, k-1))%10007
        return dp[n][k]

print(comb(n, k))
