def func(i, j, s, t, dp):
    if(i<0 or j<0): return 0

    if(dp[i][j]!=-1): return dp[i][j]

    if(s[i] == t[j]): 
        dp[i][j] = 1 + func(i-1, j-1, s, t, dp)
        return dp[i][j]

    dp[i][j] = max(func(i-1, j, s, t, dp), max(i, j-1, s, t, dp))
    return dp[i][j]

def lcs(s, t):
    n = len(s)
    m = len(t)
    dp=[[-1 for _ in range(m)] for _ in range(n)]
    func(n-1, m-1, s, t, dp)
    length = dp[n-1][m-1]
    ans = [''] * length
    
    index = length - 1
    i = n
    j = m
    
    while i > 0 and j > 0:
        if s[i - 1] == t[j - 1]:
            ans[index] = s[i - 1]
            index -= 1
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    return ''.join(ans)

s = "jegan"
t = "an"

length = lcs(s, t)
print("lcs:"+length)
