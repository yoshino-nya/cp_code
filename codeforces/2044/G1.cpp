// Author: Zhangwuji
// Date: 2025-02-21
// Time: 10:10:03

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
    int n;
    cin >> n;
    vi r(n + 1), a(n + 1, 1), de(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        de[r[i]]++;
    }
    /*
    只有在环上的点是不会变的
    否则就得找最长的链是多长
    */
    vi t = de;
    vector<bool> circle(n + 1);
    vi L(n + 1);
    auto topsort = [&]() {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (!de[i])
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            // cerr<<x<<'\n';
            circle[x] = true;
            q.pop();
            // assert(x>=1&&x<=n);
            if (!(--de[r[x]]))
                q.push(r[x]);
        }
        // cerr<<sz(q)<<'\n';
        while (!q.empty()) {
            assert(q.front() >= 1 && q.front() <= n);
            circle[q.front()] = true;
            q.pop();
        }
    };
    topsort();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!t[i]) {
            auto dfs = [&](auto&& self, int u) {
                // cerr<<u<<'\n';
                // assert(len<=n);
                // assert(u<=n);
                if (!circle[u] || L[u])
                    return;
                self(self, r[u]);
                cmax(L[u], L[r[u]] + 1);
                cmax(ans, L[u]);
            };
            dfs(dfs, i);
        }
    }
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