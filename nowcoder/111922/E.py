def solve():
    n = int(input())
    s = ' ' + input()
    c = [0] + list(map(int, input().split()))
    dp = [[0] * 2 for _ in range(n + 1)]
    if s[1] == '1':
        dp[1][0] = c[1]
    else:
        dp[1][1] = c[1]
    for i in range(2, n + 1):
        if s[i] == s[i - 1]:
            dp[i][0] = dp[i - 1][0]
            dp[i][1] = min(dp[i - 1][0] + c[i], dp[i - 1][1])
        else:
            dp[i][0] = dp[i - 1][0] + c[i]
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + c[i])
        # print(dp)
    print(min(dp[n][1], dp[n][0]))
for _ in range(int(input())):
    solve()