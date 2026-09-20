// Author: Zhangwuji
// Date: 2025-02-18
// Time: 22:49:28

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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n + 1, vi(m + 1));
    vi cnt(n * m + 1);
    set<int> st;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
            cmax(mx, cnt[a[i][j]]);
            st.insert(a[i][j]);
        }
    vector<bool> ok(n * m + 1);
    auto check = [&](int x, int y) {
        vector<pii> dirs { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        for (auto [xx, yy] : dirs) {
            int nx = xx + x, ny = yy + y;
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (a[nx][ny] == a[x][y])
                return true;
        }
        return false;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check(i, j))
                ok[a[i][j]] = true;
        }
    }
    int ans = 0;
    for (auto x : st)
        ans += (ok[x] ? 2 : 1);
    if (ans != sz(st))
        ans -= 2;
    else
        ans -= 1;
    cout << ans << '\n';
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