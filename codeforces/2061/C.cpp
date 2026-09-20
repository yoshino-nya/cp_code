// Author: Zhangwuji
// Date: 2025-01-20
// Time: 22:53:56

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

constexpr int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vl> dp(n + 1, vl(2));
    dp[0] = { 0, 1 }; // 0是骗子 1不是
    vector<vl> cnt(n + 1, vl(2));
    cnt[0] = { 0, 0 };
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        cnt[i][0] = a[i - 1] + 1;
        if (cnt[i - 1][0] == a[i])
            dp[i][1] = dp[i - 1][0];
        if (cnt[i - 1][1] == a[i])
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
        cnt[i][1] = a[i];
    }
    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    // cnt[i][0]表示前一个人说谎的话 当前骗子的数量
    // cnt[i-1][1]表示
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
// 0 1
// 11 10
// 110 101
// 1010 1011 1101
// 10101x 10111 10110 11011 11010