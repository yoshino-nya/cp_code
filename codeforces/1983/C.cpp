// Author: Zhangwuji
// Date: 2025-01-08
// Time: 23:45:41

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
    int n;
    cin >> n;
    vector<vi> a(3, vi(n + 1));
    vector<vl> pre(3, vl(n + 1));
    ll need = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], pre[i][j] = pre[i][j - 1] + a[i][j];
    need = pre[0][n];
    need = (need - 1) / 3 + 1;
    vector<pii> ans(3);
    bool ok = false;
    cerr<<need<<'\n';
    auto dfs = [&](auto&& self, int st, ll l) {
        // cerr<<st<<'\n';
        if (st == 7) {
            ok = true;
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (st >> i & 1)
                continue;
            int r = lower_bound(pre[i].begin() + l, pre[i].end(), pre[i][l] + need) - pre[i].begin();
            // assert(r!=l);
            if (r > n)
                continue;
            ans[i] = { l + 1, r };
            self(self, st | (1 << i), r);
            if (ok) {
                return;
            }
        }
    };
    dfs(dfs, 0, 0);
    if (ok) {
        // ans[2].se = n;
        for (auto [x, y] : ans)
            cout << x << " " << y << " ";
        cout << '\n';
    } else {
        cout << "-1\n";
    }
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