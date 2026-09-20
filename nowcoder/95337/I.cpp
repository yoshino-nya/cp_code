// Author: Zhangwuji
// Date: 2025-02-08
// Time: 13:30:43

// #define YUANSHEN
// #include <windows.h>
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
    int n, m;
    cin >> n >> m;
    set<ll> st;
    st.insert(1);
    for (int i = 1;; i++) {
        st.insert(*st.rbegin() * 2);
        if (*st.rbegin() > m)
            break;
    }
    if (n == 0 && m != 0) {
        cout << "No\n";
        return;
    }
    if (n == m) {
        cout << "Yes\n";
        return;
    }
    if (m == 0) {
        cout << "No\n";
        return;
    }
    map<ll, bool> vis;
    bool ans = false;
    auto sqrti = [](ll x) {
        ll lo = 0, hi = INF + 1;
        while (lo < hi - 1) {
            ll mid = (lo + hi) >> 1;
            if (mid * mid <= x)
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    };
    auto dfs = [&](auto&& self, ll x) {
        // cerr << x << '\n';

        if (vis[x])
            return;
        vis[x] = true;
        if (m % x == 0 && st.count(m / x)) {
            ans = true;
            return;
        }
        if (sqrti(x) < m)
            self(self, x * 2);
        self(self, sqrti(x));
    };
    dfs(dfs, n);

    cout << (ans ? "Yes\n" : "No\n");
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