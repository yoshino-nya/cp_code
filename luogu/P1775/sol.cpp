#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[303][303];

void ChatGptDeepSeek() // Date: 2025-04-07
{                      // Time: 20:41:23
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= 302; i++)
        for (int j = 0; j <= 302; j++)
            dp[i][j] = 1e9;
    for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i][i] = 0;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
        }
    }
    cout << dp[1][n] << '\n';
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