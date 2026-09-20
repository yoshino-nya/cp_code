// Author: Zhangwuji
// Date: 2025-02-02
// Time: 13:40:02

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
    vi a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vi c1(n + 1), c2(m + 1);
    for (int i = 1; i <= n; i++) {
        if (!a[i])
            continue;
        int j = i;
        while (j <= n && a[j]) {
            j++;
        }
        for (int len = 1; len <= j - i; len++)
            c1[len] += j - i + 1 - len;
        i = j - 1;
    }
    for (int i = 1; i <= m; i++) {
        if (!b[i])
            continue;
        int j = i;
        while (j <= m && b[j]) {
            j++;
        }
        for (int len = 1; len <= j - i; len++)
            c2[len] += j - i + 1 - len;
        i = j - 1;
    }
    ll ans = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            if (i <= n && k / i <= m)
                ans += 1ll * c1[i] * c2[k / i];
            if (i * i != k && k / i <= n && i <= m)
                ans += 1ll * c1[k / i] * c2[i];
        }
    }
    cout << ans << "\n";
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