/*
1100
11
10 1
只有前面全是1 才会多一次操作
否则位一定减少一位

但是通过操作2 如果末尾是1 那么除二后的结果会加1

*/
// Date: 2025-03-21
// Time: 08:13:17

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int x, n, m;
    cin >> x >> n >> m;
    n = min(35, n), m = min(35, m);
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 1e9 + 1));
    dp1[0][0] = x, dp2[0][0] = x;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i) {
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] / 2);
                dp2[i][j] = min(dp2[i][j], dp2[i - 1][j] / 2);
            }
            if (j) {
                dp1[i][j] = max(dp1[i][j], (dp1[i][j - 1] & 1) + dp1[i][j - 1] / 2);
                dp2[i][j] = min(dp2[i][j], (dp2[i][j - 1] & 1) + dp2[i][j - 1] / 2);
            }
            // cerr << dp1[i][j] << '\n';
        }
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= m; j++)
    //         cerr << dp1[i][j] << " \n"[j == m];
    // cerr << '\n';
    cout << dp2[n][m] << " " << dp1[n][m] << '\n';
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