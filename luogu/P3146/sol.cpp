#include <bits/stdc++.h>
using namespace std;

int dp[250][250];

void ChatGptDeepSeek() // Date: 2025-04-08
{                      // Time: 15:04:31
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i][i] = a[i];
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                if (dp[l][k] > 0 && dp[k + 1][r] > 0 && dp[l][k] == dp[k + 1][r])
                    dp[l][r] = max(dp[l][r], dp[l][k] + 1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) ans=max(ans,dp[i][j]);
    cout<<ans<<'\n';
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