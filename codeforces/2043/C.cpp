// Author: Zhangwuji
// Date: 2025-01-22
// Time: 23:05:38

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
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)
            pos = i;
    }
    int mn1 = 0, mx1 = 0, s = 0, l1 = 0, r1 = 0;
    for (int i = pos - 1; i >= 1; i--) {
        s += a[i];
        cmax(mx1, s);
        cmin(mn1, s);
        cmax(r1, s - mn1);
        cmin(l1, s - mx1);
    }
    int mn2 = 0, mx2 = 0, l2 = 0, r2 = 0;
    s = 0;
    for (int i = pos + 1; i <= n; i++) {
        s += a[i];
        cmax(mx2, s);
        cmin(mn2, s);
        cmax(r2, s - mn2);
        cmin(l2, s - mx2);
    }
    set<int> st;
    for (int i = l1; i <= r1; i++)
        st.insert(i);
    for (int i = l2; i <= r2; i++)
        st.insert(i);
    s = 0, l1 = 0, r1 = 0;
    for (int i = pos - 1; i >= 1; i--) {
        s += a[i];
        cmax(r1, s);
        cmin(l1, s);
    }
    s = 0, l2 = 0, r2 = 0;
    for (int i = pos + 1; i <= n; i++) {
        s += a[i];
        cmax(r2, s);
        cmin(l2, s);
    }
    for (int i = a[pos] + l1 + l2; i <= a[pos] + r1 + r2; i++)
        st.insert(i);
    cout << sz(st) << '\n';
    for (auto x : st)
        cout << x << " ";
    cout << '\n';
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