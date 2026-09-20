// Date: 2025-03-30
// Time: 17:25:14
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244853;

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    vector<ll> dp(m);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<ll> ndp(m);
        for (int j = 0; j < m; j++)
        {
            ndp[(j + a[i]) % m] = (ndp[(j + a[i]) % m] + dp[j] * p[i]) % mod;
            ndp[j] = (ndp[j] + dp[j] * (1 - p[i])) % mod;
            ndp[j] = (ndp[j] + mod) % mod;
            ndp[(j + a[i]) % m] = (ndp[(j + a[i]) % m] + mod) % mod;
        }
        dp = ndp;
    }
    cout << (dp[0] + mod) % mod << '\n';
    return 0;
}