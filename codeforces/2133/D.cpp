#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<LL> dp(n + 1, LLONG_MAX);
    dp[0] = 0;
    dp[1] = h[1];
    for(int i = 2; i <= n; i++){
        dp[i] = min(dp[i - 1] + h[i] - 1, dp[i - 2] + h[i - 1] + max(0, h[i] - i + 1));
    }
    cout << dp[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}