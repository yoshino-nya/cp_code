// Author: Zhangwuji
// Date: 2025-02-18
// Time: 23:01:53

// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vl> dp(n + 1, vl(3));
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (a[i] == 1)
            dp[i][0]++;
        else if (a[i] == 2) {
            dp[i][1] = (dp[i][1] + dp[i - 1][0] + dp[i][1]) % mod;
        } else
            ans += dp[i][1], ans %= mod;
        // if (a[i] == 3)
        // cerr << dp[i][0] << " " << dp[i][1] << '\n';
    }
    cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}