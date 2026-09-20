// Date: 2025-03-02
// Time: 19:27:13

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1e18));
    // vector<vector<long long>>dp(k+1,vector<long long>(7,-1e18));
    dp[0][0] = 0;
    long long ans = -1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= min(6, i); l++) {
                dp[i][j] = max(dp[i][j], dp[i - l][j - 1] + a[i]);
            }
        }
        // cerr<<dp[i][1]<<" "<<dp[i][2]<<'\n';
        ans = max(ans, dp[i][k]);
    }
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
        solve();
    return 0;
}