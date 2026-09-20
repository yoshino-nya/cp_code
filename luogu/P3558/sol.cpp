#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-07
{                      // Time: 17:51:48
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 枚举每一位变成 -1 0 1 的答案
    vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));
    // ... 好像想复杂了的
    dp[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int x = -1; x <= 1; x++)
        {
            for (int z = 0; z <= 2; z++)
            {
                int y = a[i] + z * x;
                if (y < x || y > 1)
                    continue;
                dp[i][y + 1] = min(dp[i][y + 1], dp[i - 1][x + 1] + z);
            }
        }
    }
    int ans = min({dp[n][0], dp[n][1], dp[n][2]});
    if (ans == 1e9)
        cout << "BRAK\n";
    else
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