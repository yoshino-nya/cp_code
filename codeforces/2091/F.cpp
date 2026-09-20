// Date: 2025-03-26
// Time: 10:03:56
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

ll dp[2002][2002][2], pre[2002][2002][2];

void ChatGptDeepSeek()
{
    int n, m, d;
    cin >> n >> m >> d;
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<char>> s(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    /*
    dp[i][j][0] i j
    */
    for (int i = 1; i <= m; i++)
    {
        pre[n][i][0] = dp[n][i][0] = s[n][i] == 'X' ? 1 : 0;
        pre[n][i][0] = (pre[n][i - 1][0] + pre[n][i][0]) % mod;
        dp[n][i][1] = 0;
    }
    auto get0 = [&](int i, int j, int di)
    {
        return (pre[i][min(m, j + di)][0] - pre[i][max(0, j - di - 1)][0] + mod) % mod;
    };
    auto get1 = [&](int i, int j, int di)
    {
        return (pre[i][min(m, j + di)][1] - pre[i][max(0, j - di - 1)][1] + mod) % mod;
    };
    for (int j = 1; j <= m; j++)
    {
        pre[n][j][1] = pre[n][j - 1][1];
        if (s[n][j] != 'X')
            continue;
        dp[n][j][1] = (get0(n, j, d) - dp[n][j][0] + mod) % mod;
        pre[n][j][1] = (pre[n][j][1] + dp[n][j][1]) % mod;
    }
    int d1 = d;
    while (d1 * d1 + 1 > d * d)
        d1--;
    // cerr << d1 << '\n';
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            /* x*x+1*1<=d*d */
            /* (d-1)*(d-1)+1<=d*d */
            pre[i][j][0] = pre[i][j - 1][0];
            if (s[i][j] != 'X')
            {
                dp[i][j][0] = 0;
                continue;
            }
            dp[i][j][0] = (get1(i + 1, j, d1) + get0(i + 1, j, d1)) % mod;
            pre[i][j][0] = (pre[i][j][0] + dp[i][j][0]) % mod;
        }
        for (int j = 1; j <= m; j++)
        {
            pre[i][j][1] = pre[i][j - 1][1];
            if (s[i][j] != 'X')
            {
                dp[i][j][1] = 0;
                continue;
            }
            dp[i][j][1] = (get0(i, j, d) - dp[i][j][0] + mod) % mod;
            pre[i][j][1] = (pre[i][j][1] + dp[i][j][1]) % mod;
        }
    }
    cout << (pre[1][m][0] + pre[1][m][1]) % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}