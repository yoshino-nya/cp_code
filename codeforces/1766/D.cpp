// Author: Zhangwuji
// Date: 2025-02-23
// Time: 22:41:06

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

constexpr int N = 1e7 + 5;
int mind[N + 5];

void init()
{
    for (int i = 1; i <= N; i++)
        mind[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (mind[i] != i)
            continue;
        for (int j = i * i; j <= N; j += i)
            cmin(mind[j], i);
    }
}
vi get_primes(int x)
{
    vi res;
    while (x > 1) {
        res.push_back(mind[x]);
        while (x % res.back() == 0)
            x /= res.back();
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == x + 1) {
            cout << "-1\n";
            continue;
        }
        if (__gcd(x, y) != 1) {
            cout << "0\n";
            continue;
        }
        int z = y - x;
        int ans = INF;
        auto calc = [&](int t) {
            return (x / t + 1) * t;
        };
        for (auto v : get_primes(z)) {
            cmin(ans, calc(v) - x);
        }
        cout << ans << '\n';
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}