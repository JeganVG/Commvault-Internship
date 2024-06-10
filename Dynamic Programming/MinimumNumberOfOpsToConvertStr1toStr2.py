def lcs(s, t):
    n = len(s)
    m = len(t)
    dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[n][m]

s = "jegan"
t = "ja"

ops = len(s)+len(t)-2*lcs(s, t)
print(ops)

