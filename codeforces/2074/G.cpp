// Date: 2025-03-25
// Time: 16:58:19
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int len = 3; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int m = l + 1; m < r; m++)
                dp[l][r] = max(dp[l][r], dp[l + 1][m - 1] + dp[m + 1][r - 1] + a[l] * a[m] * a[r]);

            for (int m = l; m + 1 <= r; m++)
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
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
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}