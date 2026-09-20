// Author: Zhangwuji
// Date: 2024-12-25
// Time: 00:48:18

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
    vector<array<int, 3>> a(m + 1);
    vector<vi> b(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
        b[a[i][2]].push_back(i);
    }
    auto merge = [](array<int, 3> x, array<int, 3> y, array<int, 3> z = { 0, 0, 0 }) {
        return make_pair(x[0] + y[0] + z[0], x[0] * x[1] + y[0] * y[1] + z[0] * z[1]);
    };
    vector<vector<pii>> items;
    for (int i = 1; i <= m; i++) {
        vector<pii> tmp;
        for (auto x : b[i])
            tmp.push_back(merge(a[i], a[x]));
        if (sz(b[i]) == 2) {
            tmp.push_back(merge(a[i], a[b[i][0]], a[b[i][1]]));
        }
        if (!a[i][2])
            tmp.push_back({ a[i][0], a[i][0] * a[i][1] });
        if (!tmp.empty())
            items.push_back(tmp);
    }
    // for(auto [p,v]:items) cerr<<p<<" "<<v<<'\n';
    vi dp(n + 1);
    m = sz(items);
    for (int i = 0; i < m; i++) {
        auto &vec = items[i];
        vi ndp = dp;
        for (auto [p, v] : vec) {
            // cerr << v << " " << p << '\n';
            for (int j = 0; j + p <= n; j++) {
                cmax(ndp[j + p], dp[j] + v);
            }
        }
        dp = ndp;
    }
    cout << dp[n] << '\n';
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