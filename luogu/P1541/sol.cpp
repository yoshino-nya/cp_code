// Date: 2025-04-04
// Time: 01:17:23
#include <bits/stdc++.h>
using namespace std;

int dp[41][41][41][41];

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(4);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        b[x - 1]++;
    }
    dp[0][0][0][0] = a[1];
    for (int i = 0; i <= b[0]; i++)
        for (int j = 0; j <= b[1]; j++)
            for (int k = 0; k <= b[2]; k++)
                for (int l = 0; l <= b[3]; l++)
                {
                    int len = i * 1 + j * 2 + k * 3 + l * 4;
                    // dp[i][j][k][l] = a[1];
                    // cerr << len << '\n';
                    if (i - 1 >= 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[len + 1]);
                    if (j - 1 >= 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[len + 1]);
                    if (k - 1 >= 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[len + 1]);
                    if (l - 1 >= 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[len + 1]);
                }
    cout << dp[b[0]][b[1]][b[2]][b[3]] << '\n';
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