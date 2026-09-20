#include <bits/stdc++.h>
using namespace std;

int dp[2][20002];

void ChatGptDeepSeek() // Date: 2025-04-07
{                      // Time: 19:29:06
    int s, n, m;
    cin >> s >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(s + 1));
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    }

    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin() + 1, a[i].end());
        for (int j = 1; j <= s; j++)
        {
            int need = 2 * a[i][j] + 1;
            if (need > m)
                break;
            for (int k = m; k >= need; k--)
            {
                dp[i & 1][k] = max(dp[i & 1][k], dp[i & 1 ^ 1][k - need] + i * j);
                // cerr << dp[k] << " ";
            }
            // cerr << '\n';
        }
        for (int k = 0; k <= m; k++)
            dp[i & 1 ^ 1][k] = dp[i & 1][k];
        // cout << *max_element(dp + 1, dp + m + 1) << '\n';
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max(ans, dp[n & 1][i]);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}