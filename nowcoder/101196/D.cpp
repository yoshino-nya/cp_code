// Author: Zhangwuji
// Date: 2025-02-09
// Time: 19:05:44

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
    string s;
    cin >> s;
    ll cnt = 0, ans = 0, x = 0, y = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (!ans && s[i] == '0')
            res += n - i - 1;
        if (s[i] == '1')
            cnt++;
        if (cnt < i + 1 - cnt) {
            if (ans) {
                if (x) {
                    cout << "0\n";
                    return;
                } else {
                    x = i;
                    cnt++;
                }
            } else {
                y = i;
                ans = i + 1 - cnt;
                cnt++;
            }
        }
    }
    if (ans) {
        if (x) {
            //[0,y] [0,x]
            int c = 0;
            ll resu = 0;
            for (int i = x; i >= 0; i--) {
                c += (s[i] == '0');
            }
            for (int i = 0; i <= y; i++) {
                c -= (s[i] == '0');
                resu += c;
            }
            cout << resu << '\n';
        } else
            cout << 1ll * ans * (n - 1) << '\n';
    } else
        cout << 1ll * n * (n - 1) / 2 << '\n';
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