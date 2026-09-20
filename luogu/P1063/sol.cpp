#include <bits/stdc++.h>
using namespace std;

int dp[202][202];
void ChatGptDeepSeek() // Date: 2025-04-08
{                      // Time: 16:03:12
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i];
    for (int len = 2; len <= n + 1; len++)
        for (int l = 1; l + len - 1 <= 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++)
            {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
                // cerr << l << " " << r << " " << dp[l][r] << '\n';
            }
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i + n]);
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