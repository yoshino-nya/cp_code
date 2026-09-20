// Author: Zhangwuji
// Date: 2025-01-01
// Time: 23:07:13

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
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    // auto calc = [&](auto&& self, int l, int r) -> void {
    //     if ((r - l + 1 < k))
    //         return;
    //     int m = (1ll * l + r) >> 1;
    //     if ((r - l + 1) & 1) {//111
    //         ans+=m;
    //         if (l != r) {
    //             self(self, l, m - 1);
    //             self(self, m + 1, r);
    //         }
    //     } else {
    //         self(self, l, m);
    //         self(self, m + 1, r);
    //     }
    // };
    // calc(calc, 1, n);
    ll t=(1+n);
    int x=n;
    while(x>=k){
        if(x&1){
            ans+=t;
        }
        t<<=1;
        x/=2;
    }
    cout << ans/2 << '\n';
    //1011
    //6 6*2
    //
    // 110111 28
    // 56
    // 112
    // [1,27] [29,]
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    // cerr<<38416403456028-38416399073312<<'\n';
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}