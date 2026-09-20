// Author: Zhangwuji
// Date: 2025-02-19
// Time: 00:03:21

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
    int n, m, k;
    cin >> n >> m >> k;
    vi b(n + 1);
    for (int i = 1; i <= k; i++) {
        priority_queue<pii> pq;
        for (int j = 1; j <= n; j++)
            pq.push({ b[j], j });
        for (int j = 1; j <= m - (n % m); j++) {
            cout << n / m << " ";
            for (int l = 1; l <= n / m; l++) {
                // assert(!pq.empty());
                auto x = pq.top().se;
                pq.pop();
                cout << x << " ";
            }
            cout << '\n';
        }
        for (int j = 1; j <= n % m; j++) {
            cout << n / m + 1 << " ";
            for (int l = 1; l <= n / m + 1; l++) {
                // assert(!pq.empty());

                auto x = pq.top().se;
                pq.pop();
                cout << x << " ";
                b[x]++;
            }
            cout << '\n';
        }
    }
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