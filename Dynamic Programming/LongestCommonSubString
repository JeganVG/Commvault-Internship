def func(i, j, s, t, dp):
    if(i<0 or j<0): return 0

    if(dp[i][j]!=-1): return dp[i][j]

    if(s[i] == t[j]): 
        dp[i][j] = 1 + func(i-1, j-1, s, t, dp)
        return dp[i][j]
    else: dp[i][j] = 0
    
    return dp[i][j]

def lcs(s, t):
    n = len(s)
    m = len(t)
    dp=[[-1 for _ in range(m)] for _ in range(n)]
    return func(n-1, m-1, s, t, dp)

s = "jegan"
t = "je"

length = lcs(s, t)
print("lcs:"+str(length))
