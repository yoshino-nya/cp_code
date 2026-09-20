#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<vector<LL>> dp(n + 1, vector<LL> (n + 1));
    for(int k = 2; k <= n; k++){
        for(int l = 1; l <= n; l++){
            int r = l + k - 1;
            if(r <= n)
                dp[l][r] = a[r] - a[l] + min(dp[l + 1][r], dp[l][r - 1]);
        }
    }
    cout << dp[1][n] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}