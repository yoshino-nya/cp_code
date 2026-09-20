// Author: Zhangwuji
// Date: 2025-01-20
// Time: 23:39:32

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
    // vi a(n + 1);
    // vi b(m + 1);
    multiset<int> st1, st2;
    for (int i = 1; i <= n; i++) {
        // cin >> a[i];
        int x;
        cin>>x;
        st2.insert(x);
    }
    for (int i = 1; i <= m; i++) {
        // cin >> b[i];
        int x;
        cin>>x;
        st1.insert(x);
    }
    while (sz(st1) < sz(st2) && !st1.empty() && !st2.empty()) {
        int x = *st1.begin();
        auto it = st2.lower_bound(x);
        st1.erase(st1.begin());
        if (it != st2.end() && *it == x)
            st2.erase(it);
        else {
            st1.insert(x / 2);
            if (x & 1)
                st1.insert(x / 2 + 1);
            else
                st1.insert(x / 2);
        }

        // cerr << x << '\n';
    }
    if (st1 == st2)
        cout << "Yes\n";
    else
        cout << "No\n";
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