// Author: Zhangwuji
// Date: 2024-12-17
// Time: 13:05:00

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

constexpr int mod = 1e9 + 7;
void solve()
{
    ll n;
    int k;
    cin >> n >> k;
    n %= mod;
    if (k == 1) {
        cout << n << '\n';
        return;
    }
    vector<ll> f(6 * k + 1);
    f[1] = f[2] = 1;
    for (int i = 3; i <= 6 * k; i++) {
        f[i] = f[i - 1] + f[i - 2];
        // cerr<<f[i]<<" ";
        f[i] %= k;
        // cerr << f[i] << " ";
        if (f[i] % k == 0) {
            cout << n * i % mod << '\n';
            return;
        }
    }
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