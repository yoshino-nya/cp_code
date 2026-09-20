// Date: 2025-04-03
// Time: 23:24:36
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

constexpr int mod = 998244353;
constexpr int N = 5e5 + 114;
int f[N];

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
ll inv(ll x) { return ksm(x, mod - 2); }
void ChatGptDeepSeek()
{
    array<int, 26> c;
    int n = 0;
    for (int i = 0; i < 26; i++)
        cin >> c[i], n += c[i];
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (!c[i])
            continue;
        for (int j = n; j >= c[i]; j--)
            dp[j] = (dp[j] + dp[j - c[i]]) % mod;
    }
    ll ans = (dp[n / 2] * f[n / 2] % mod) * f[(n + 1) / 2] % mod;
    for (int i = 0; i < 26; i++)
        ans = ans * inv(f[c[i]]) % mod;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = 1LL * f[i - 1] * i % mod;
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}