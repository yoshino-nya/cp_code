/*
哦哦 ，实际上这玩意是重复元素的个数吧
我们需要找一个最长的子段 这个子段

如果出现次数为1
那么贡献+1 否则-1
*/
// Author: Zhangwuji
// Date: 2025-02-16
// Time: 22:57:31

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
    vi cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;
    int l = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == 1) {
            int j = i;
            while (j <= n && cnt[a[j]] == 1)
                j++;
            cmax(mx, j - i);
            if (j - i == mx)
                l = i;
            i = j;
        }
    }
    if (mx)
        cout << l << " " << l + mx - 1 << '\n';
    else
        cout << "0\n";
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