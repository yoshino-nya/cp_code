// Author: Zhangwuji
// Date: 2025-01-05
// Time: 20:08:37

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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
    int n, c, m;
    cin >> n >> c >> m;
    vi a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    vi f(n + 1), val(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        f[u] = v;
        f[v] = u;
        val[u] = val[v] = w;
    }
    vector<vl> dp(c + 1, vl(5));
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        vector ndp = dp;
        for (int j = 0; j + a[i] <= c; j++)
            for (int l = 0; l < 4; l++)
                cmax(ndp[j + a[i]][l + 1], dp[j][l] + b[i]);
        if (f[i]) {
            int k = f[i];
            for (int j = 0; j + a[k] <= c; j++)
                for (int l = 0; l < 4; l++)
                    cmax(ndp[j + a[k]][l + 1], dp[j][l] + b[k]);
            for (int j = 0; j + a[k] + a[i] <= c; j++)
                for (int l = 0; l < 3; l++)
                    cmax(ndp[j + a[k] + a[i]][l + 2], dp[j][l] + b[k] + b[i] + val[i]);
            vis[k] = true;
        }
        dp = ndp;
    }
    cout << dp[c][4] << '\n';
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