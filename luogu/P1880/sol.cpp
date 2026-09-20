#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2][114][114];

void ChatGptDeepSeek() // Date: 2025-04-07
{                      // Time: 20:35:26
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    auto get = [&](int l, int r)
    {
        if (l <= r)
            return pre[r] - pre[l - 1];
        else
            return pre[n] - pre[l - 1] + pre[r];
    };
    { // 先把最小值求了吧
        for (int i = 0; i < 114; i++)
            for (int j = 0; j < 114; j++)
                dp[0][i][j] = 1e9;
        for (int i = 1; i <= n; i++)
            dp[0][i][i] = 0;
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1; l <= n; l++)
            {
                int r = l + len - 1;
                if (r > n)
                    r -= n;
                for (int k = l; k != r; k++)
                {
                    if (k > n)
                    {
                        k = 0;
                        continue;
                    }
                    dp[0][l][r] = min(dp[0][l][r], dp[0][l][k] + dp[0][(k + 1 > n ? k + 1 - n : k + 1)][r] + get(l, r));
                    dp[1][l][r] = max(dp[1][l][r], dp[1][l][k] + dp[1][(k + 1 > n ? k + 1 - n : k + 1)][r] + get(l, r));
                }
            }
        }
        ll ans[]{1000000000, 0};
        for (int l = 1; l <= n; l++)
        {
            int r = l + n - 1;
            if (r > n)
                r -= n;
            ans[0] = min(ans[0], dp[0][l][r]), ans[1] = max(ans[1], dp[1][l][r]);
        }
        cout << ans[0] << '\n'
             << ans[1] << '\n';
    }
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