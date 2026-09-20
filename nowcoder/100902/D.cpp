// Author: Zhangwuji
// Date: 2025-02-02
// Time: 19:21:55

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
    string s;
    cin >> s;
    set<int> pri { 2, 3, 5, 7, 11, 13, 17 };
    string ans;
    int n = sz(s);
    if (s[0] == '1') {
        ans = string(n, '0');
        ans[0] = '2';
        cout << ans << '\n';
        return;
    }
    if (n <= 3) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x *= 10;
            x += s[i] - '0';
        }
        // cerr<<x<<'\n';
        auto check = [&](int x) {
            if (x == 1)
                return false;
            if (x == 2)
                return true;
            for (int i = 2; i < x; i++) {
                if (x % i == 0)
                    return false;
            }
            return true;
        };
        for (int i = x; i <= 2 * x; i++) {
            if (check(i)) {
                cout << i << '\n';
                return;
            }
        }
        cout << "-1\n";
        return;
    }
    if (s[0] >= '6') {
        ans = string(n + 1, '0');
        ans[0] = '1', ans[n] = '1';
        cout << ans << '\n';
        return;
    } else {
        ans = string(n, '0');
        ans[0] = s[0] + 1;
        int now = s[0] - '0' + 1;
        for (int i = 0; i <= 9; i++) {
            if (pri.count(now + i)) {
                ans[n - 1] = '0' + i;
                cout << ans << '\n';
                return;
            }
        }
        cout << "-1\n";
        return;
    }
    // 1 ,2
    // 2 ,5
    // 3 ,4
    // 4 ,3
    // 5, 2
    // 6, 1
    // 7, 0
    // 8, 3
    // 9, 2
    // 10,
    cout<<"-1\n";
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