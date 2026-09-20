// Author: Zhangwuji
// Date: 2024-12-22
// Time: 11:18:14

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
// #define int long long
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
    ll sx, sy;
    cin >> n >> m >> sx >> sy;
    map<ll, set<ll>> X, Y;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    int ans = 0;
    while (m--) {
        char d;
        int c;
        cin >> d >> c;
        if (d == 'U') {
            if (X.count(sx)) {
                auto& st = X[sx];
                while (!st.empty()) {
                    auto it = st.lower_bound(sy);
                    if (it == st.end() || *it > sy + c) {
                        break;
                    }
                    Y[*it].erase(sx);
                    st.erase(it);
                    ans++;
                }
            }
            sy += c;
        } else if (d == 'D') {
            if (X.count(sx)) {
                auto& st = X[sx];
                while (!st.empty()) {
                    auto it = st.lower_bound(sy - c);
                    if (it == st.end() || *it > sy)
                        break;
                    Y[*it].erase(sx);
                    st.erase(it);
                    ans++;
                }
            }
            sy -= c;
        } else if (d == 'R') {
            if (Y.count(sy)) {
                auto& st = Y[sy];
                while (!st.empty()) {
                    auto it = st.lower_bound(sx);
                    if (it == st.end() || *it > sx + c) {
                        break;
                    }
                    ans++;
                    X[*it].erase(sy);
                    st.erase(it);
                }
            }
            sx += c;
        } else {
            if (Y.count(sy)) {
                auto& st = Y[sy];
                while (!st.empty()) {
                    auto it = st.lower_bound(sx - c);
                    if (it == st.end() || *it > sx)
                        break;
                    X[*it].erase(sy);
                    st.erase(it);
                    ans++;
                }
            }
            sx -= c;
        }
        // cerr<<sx<<" "<<sy<<'\n';
    }
    cout << sx << " " << sy << " " << ans << '\n';
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