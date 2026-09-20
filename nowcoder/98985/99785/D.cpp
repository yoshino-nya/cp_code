// Author: Zhangwuji
// Date: 2025-01-17
// Time: 19:24:01

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

void solve()
{
    int n, m;
    cin >> n >> m;
    // 只需要知道这一天的val总和 和最小的 b-val的值
    vector<pii> c(n + 1, { 0, 0 });
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int b, v;
        cin >> b >> v;
        int j = a[i];
        c[j].fi += v;
        cmin(c[j].se, b - v);
    }
    vl pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + c[i].fi;
    vl dp(n + 1, LNF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cmin(dp[i], dp[i - 1] + c[i].fi);
        if (i + m - 1 <= n)
            cmin(dp[i + m - 1], dp[i - 1] + pre[i + m - 1] - pre[i - 1] + c[i].se);
    }
    cout<<dp[n]<<'\n';
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