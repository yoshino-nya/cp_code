#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];
    // vector<int> tmp(vec);
    // sort(tmp.begin() + 1, tmp.end());
    // for(int i = 1; i <= n; i++)
    //     vec[i] = lower_bound(tmp.begin() + 1, tmp.end(), vec[i]) - tmp.begin();
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        if (vec[i] <= n)
            cnt[vec[i]]++;
    vector<LL> dp(n + 1);
    dp[1] = 1LL * (cnt[1] - 1) * cnt[1] / 2 % mod;
    for (int i = 2; i <= n; i++)
    {
        if (cnt[i] >= 2)
        {
            LL add = 1LL * (cnt[i] - 1) * cnt[i] / 2 % mod;
            dp[i] = dp[i - 1] * add % mod;
        }
        else
        {
            break;
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + dp[i]) % mod;
    cout << ans << "\n";
}
// 11 22 33
// 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}