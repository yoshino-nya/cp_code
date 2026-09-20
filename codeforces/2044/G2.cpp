// Author: Zhangwuji
// Date: 2025-02-21
// Time: 10:56:34

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

void solve()
{
    /*
    因为不会丢了，n条边 一定会有环
    那么必须保证每个环上每个点上的值一直相同
    即同一环上每一个点连的点的数量要是相同的
    。。。不对，唐了
    每次只会给一个 所以无论如何环上是不会变的
    */
    int n;
    cin >> n;
    vi r(n + 1), a(n + 1, 1), de(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        de[r[i]]++;
    }
    vi t = de;
    vector<bool> circle(n + 1);
    // vi L(n + 1);
    auto topsort = [&]() {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (!de[i])
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            circle[x] = true;
            q.pop();
            if (!(--de[r[x]]))
                q.push(r[x]);
        }
    };
    topsort();
    int ans = 0;
    vi cnt(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!t[i]) {
            auto dfs = [&](auto&& self, int u) -> void {
                if (f[u])
                    return;
                if (!circle[r[u]]) {
                    f[u] = u;
                    cnt[u] = 1;
                    return;
                }

                self(self, r[u]);
                f[u] = f[r[u]];
                cnt[f[u]]++;
                // cerr << u<<" "<<f[u] << " " << cnt[f[u]] << '\n';
                // assert(f[u]&&(f[u]!=u)&&(!circle[f[u]]));
                cmax(ans, cnt[f[u]]);
            };
            dfs(dfs, i);
        }
    }
    cmax(ans, *max_element(ALL(cnt)));
    cout << ans + 2 << '\n';
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