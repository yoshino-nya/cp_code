// Author: Zhangwuji
// Date: 2025-01-21
// Time: 13:24:13

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
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int idx = min_element(ALL(a)) - a.begin();
    // a[idx] *= 2;
    auto check = [&](ll val) {
        // 如果极差不满足条件 就把当前最小值 *2
        set<pii> st;
        int l = idx, r = idx, y = 2 * a[idx];
        for (int i = 1; i <= n; i++) {
            if (i != idx)
                st.insert({ a[i], i });
            cmax(y, a[i]);
        }
        while (!st.empty()) {
            auto [x, i] = *st.begin();
            if (y - x > val) {
                cmin(l, i);
                cmax(r, i);
                st.erase(st.begin());
                cmax(y, 2 * x);
            } else
                break;
        }
        int mx_val = 0, mn_val = 2 * INF;
        for (int i = 1; i <= n; i++) {
            if (i >= l && i <= r) {
                cmax(mx_val, 2 * a[i]);
                cmin(mn_val, a[i] * 2);
            } else {
                cmax(mx_val, a[i]);
                cmin(mn_val, a[i]);
            }
        }
        return mx_val - mn_val <= val;
    };
    if (check(0)) {
        cout << "0\n";
        return;
    }
    ll lo = 0, hi = INF + 1;
    while (lo < hi - 1) {
        ll mid = (lo + hi) >> 1;
        // cerr<<mid<<'\n';
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
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