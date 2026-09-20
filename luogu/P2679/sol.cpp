// Date: 2025-04-01
// Time: 19:12:38
#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;

int dp[2][202][202];
void ChatGptDeepSeek()
{
    int n, m, k;
    cin >> n >> m >> k;

    // 匹配了i长度，用了 j 段
    vector<char> A(n + 1), B(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= m; i++)
        cin >> B[i];
    vector<vector<int>> DP(m + 1, vector<int>(k + 1));
    dp[0][0][0] = DP[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {

        vector nDP = DP;
        for (int j = 1; j <= min(i, m); j++)
        {
            if (A[i] == B[j])
            {
                for (int l = 1; l <= min(k, j); l++)
                {
                    dp[i & 1][j][l] = (dp[i & 1][j][l] + DP[j - 1][l - 1]) % mod;
                    nDP[j][l] = (nDP[j][l] + DP[j - 1][l - 1]) % mod;

                    dp[i & 1][j][l] = (dp[i & 1][j][l] + dp[(i ^ 1) & 1][j - 1][l]) % mod;
                    nDP[j][l] = (nDP[j][l] + dp[(i ^ 1) & 1][j - 1][l]) % mod;
                }
            }
        }
        for (int j = 0; j <= min(i, m); j++)
            for (int l = 1; l <= min(k, j); l++)
                dp[(i ^ 1) & 1][j][l] = 0;
        DP = nDP;
    }
    cout << DP[m][k] << '\n';
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}