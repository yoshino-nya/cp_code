// Author: Zhangwuji
// Date: 2024-12-22
// Time: 23:21:37

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/templates/debug.hpp"
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

ll dp[70][70][2];
void solve()
{
    ll n;
    int k;
    cin >> n >> k;
    dp[1][1][1] = dp[1][0][0] = 1;
    for (int i = 2; i < 63; i++)
        for (int j = 0; j <= i; j++) {
            if (j)
                dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
            dp[i][j][0] = dp[i - 1][j][1] + dp[i - 1][j][0];
        }
    ll ans = 0;
    for (int i = 1; i <= __lg(n); i++)
        ans += dp[i][k][1];
    int t = 1;
    for (int i = __lg(n); i >= 1; i--) {
        if (n >> (i-1) & 1) {
            ans += dp[i][k - t][0];
            t++;
            if (t > k)
                break;
        }
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}