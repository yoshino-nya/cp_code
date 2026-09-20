// Author: Zhangwuji
// Date: 2025-01-24
// Time: 01:27:55

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

constexpr int mod = 998244353;

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res;
}

ll inv(ll x) { return ksm(x, mod - 2); }
void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    /*
    1 1 2
    3 2 1
    1 2 3
    1*1*2=2
    */
    ll ans = 1;
    vi c = b;
    vi d = a;
    sort(ALL(c));
    sort(ALL(d));
    for (int i = 1; i <= n; i++) {
        ans = ans * min(d[i], c[i]) % mod;
    }
    cout << ans << ' ';
    while (q--) {
        int o, x;
        cin >> o >> x;
        if (o == 2) {
            int i = lower_bound(ALL(c), b[x] + 1) - c.begin() - 1;
            ans = ans * inv(min(d[i], c[i])) % mod;
            c[i]++, b[x]++;
            ans = ans * min(d[i], c[i]) % mod;
            // cerr<<inv(min(d[i],c[i]))<<'\n';
        } else {
            int i = lower_bound(ALL(d), a[x] + 1) - d.begin() - 1;
            ans = ans * inv(min(d[i], c[i]))%mod;
            d[i]++, a[x]++;
            ans = ans * min(d[i], c[i]) % mod;
            // cerr<<inv(min(d[i],c[i]))<<'\n';
        }
        // ans = (ans + mod) % mod;
        cout << ans << ' ';
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