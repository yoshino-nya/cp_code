// Date: 2025-03-25
// Time: 12:15:27
#include <bits/stdc++.h>
using namespace std;
// 确实，我刚刚的思路完全是错的😅

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, n));
    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (s[r] == s[l])
                dp[l][r] = min(dp[l][r], dp[l][r - 1]);
            for (int m = l; m + 1 <= r; m++)
            {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
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