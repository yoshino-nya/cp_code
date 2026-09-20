// Author: Zhangwuji
// Date: 2025-01-23
// Time: 14:43:06

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
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j - 1] - '0';
    }
    vector<pii> dir { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    auto check = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    vector<pii> zeros;
    auto dfs = [&](auto&& self, int x, int y) -> void {
        vis[x][y]=true;
        for (auto [p, q] : dir) {
            int nx = x + p, ny = y + q;
            if (check(nx, ny) && !a[nx][ny]) {
                a[nx][ny] = -1;
                zeros.push_back({ nx, ny });
            }
        }
        for (auto [p, q] : dir) {
            int nx = x + p, ny = y + q;
            if (check(nx, ny) && a[nx][ny] == 1 && !vis[nx][ny]) {
                self(self, nx, ny);
                // vis[nx][ny] = false;
            }
        }
    };
    int ans=INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1 && !vis[i][j]) {
                dfs(dfs, i, j);
                cmin(ans,sz(zeros));
                while(!zeros.empty()){
                    auto [x,y]=zeros.back();
                    a[x][y]=0;
                    zeros.pop_back();
                }
            }
        }
    }
    cout<<ans<<'\n';
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