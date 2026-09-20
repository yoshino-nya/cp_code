// Author: Zhangwuji
// Date: 2025-02-20
// Time: 23:16:10

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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vi c(n + 1);
    vl pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = 2; i <= n; i++)
        c[i] = c[i - 1] + (a[i - 1] != a[i]);
    for (int i = 1; i <= n; i++) {
        int ans = n + 1;
        if (a[i - 1] > a[i])
            ans = 1;
        if (i + 1 <= n && a[i + 1] > a[i])
            ans = 1;
        if (pre[i - 1] > a[i] && c[i - 1]) {
            int lo = 0, hi = i;
            while (lo < hi - 1) {
                int mid = (lo + hi) >> 1;
                if (pre[i - 1] - pre[mid - 1] > a[i] && c[i - 1] - c[mid])
                    lo = mid;
                else
                    hi = mid;
            }
            cmin(ans, i - lo);
        }
        if (i != n && pre[n] - pre[i] > a[i] && c[n] - c[i + 1]) {
            int lo = i, hi = n + 1;
            while (lo < hi - 1) {
                int mid = (lo + hi) >> 1;
                // cerr<<mid<<" "<<pre[mid]-pre[i]<<'\n';
                if (pre[mid] - pre[i] > a[i] && c[mid] - c[i + 1])
                    hi = mid;
                else
                    lo = mid;
            }
            cmin(ans, hi - i);
        }
        if (ans == n + 1)
            ans = -1;
        cout << ans << " \n"[i == n];
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