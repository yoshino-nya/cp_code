// Author: Zhangwuji
// Date: 2024-12-30
// Time: 15:31:33

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
    int n, m;
    cin >> n >> m;
    auto check = [&](vi& b) {
        multiset<int> st;
        vi pre(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            if (b[i] > b[i - 1])
                pre[i] = pre[i - 1] + 1;
        }
        for (int i = m; i <= n; i++)
            st.insert(b[i]);
        for (int i = m; i <= n; i++) {
            st.erase(st.lower_bound(b[i]));
            if (pre[i] >= m) {
                auto i1 = st.lower_bound(b[i]);
                if (i1 == st.begin())
                    return true;
                auto i2 = prev(i1);
                if (*i2 <= b[i - m + 1])
                    return true;
            }
            st.insert(b[i - m + 1]);
        }
        return false;
    };
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> vis;
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) {
            cout << "NO\n";
            return;
        }
        vis[a[i]] = 1;
    }
    if (check(a)) {
        cout << "YES\n";
        return;
    }
    reverse(ALL(a));
    if (check(a)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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