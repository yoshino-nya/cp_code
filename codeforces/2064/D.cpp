// Author: Zhangwuji
// Date: 2025-02-17
// Time: 16:57:08

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
    int n, q;
    cin >> n >> q;
    vi w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    // 找到下一个最高位大于等于x的
    vector<vi> lst(n + 1, vi(32, 0));
    for (int i = 1; i <= n; i++) {
        lst[i] = lst[i - 1];
        for (int j = __lg(w[i]); j >= 0; j--)
            lst[i][j] = i;
    }
    vi pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] ^ w[i];
    // lst[i][j]指 [1,i]之间离i最近的最高位大于等于j的数字
    while (q--) {
        int x;
        cin >> x;
        int idx = n;
        while (idx > 0 && x) {
            int nxt = lst[idx][__lg(x)];
            x ^= pre[nxt] ^ pre[idx];
            // cerr<<x<<" "<<nxt<<" "<<idx<<"\n";
            idx = nxt;
            if (x < w[nxt] || idx == 0)
                break;
            x ^= w[nxt];
            idx--;
            // cerr<<nxt<<'\n';
        }
        cout << n - idx << ' ';
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