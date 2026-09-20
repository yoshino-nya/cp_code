// Author: Zhangwuji
// Date: 2025-01-12
// Time: 23:10:23

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
    string s;
    cin >> s;
    vector<vl> a(n + 1, vl(m + 1));
    vl sr(n + 1), sc(m + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sr[i] += a[i][j];
            sc[j] += a[i][j];
        }
    // cerr << sr[1] << " " << sc[1] << '\n';
    vi r(n + 1), c(m + 1);
    int tx = 1, ty = 1;
    r[1] = c[1] = 1;
    for (auto i : s) {
        if (i == 'R')
            ty++;
        else
            tx++;
        r[tx]++;
        c[ty]++;
    }
    auto work = [&](int x, int y) {
        // if (x == 1 && y == 1)
        //     cerr << a[x][y] << " " << sr[x] << " " << sc[y] << '\n';

        if (r[x] == 1) {
            a[x][y] = -sr[x];
        } else {
            a[x][y] = -sc[y];
        }
        sr[x] += a[x][y];
        sc[y] += a[x][y];
        r[x]--;
        c[y]--;
        // if (x == 1 && y == 1)
        //     cerr << a[x][y] << " " << sr[x] << " " << sc[y] << '\n';
    };
    tx = 1, ty = 1;
    work(1, 1);
    for (auto i : s) {
        if (i == 'R')
            ty++;
        else
            tx++;
        work(tx, ty);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " \n"[j == m];
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