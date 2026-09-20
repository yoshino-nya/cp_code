// Author: Zhangwuji
// Date: 2024-12-23
// Time: 00:06:29

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
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

constexpr int mod = 1e7 + 7;
ll dp[70][70][2];

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    dp[1][1][1] = dp[1][0][0] = 1;
    for (int i = 2; i < 63; i++)
        for (int j = 0; j <= i; j++) {
            if (j)
                dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
        }
    ll n;
    cin >> n;
    n++;
    ll ans = 1;
    vl cnt(64);
    for (int i = 1; i <= __lg(n); i++)
        for (int j = 1; j <= i; j++)
            cnt[j] += dp[i][j][1];
    int c = 1;
    for (int i = __lg(n); i >= 1; i--) {
        if (n >> (i - 1) & 1) {
            for (int j = c; j <= 63; j++) {
                cnt[j] += dp[i][j - c][0];
            }
            c++;
        }
    }
    // dbg(cnt);
    for (int i = 1; i <= 63; i++)
        ans = ans * ksm(i, cnt[i])%mod;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}