// Author: Zhangwuji
// Date: 2025-02-22
// Time: 21:13:40

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

void solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    for (int i = 0; i < n - i - 1; i++) {
        if (s[i] != s[n - i - 1]) {
            s = s.substr(i, n - i - 1 - i + 1);
            break;
        }
    }
    if (sz(s) == n && s.front() == s.back()) {
        cout << "0\n";
        return;
    }
    cerr << s << "\n";
    n = sz(s);
    s = " " + s;

    vector<vi> pre(n + 1, vi(26));
    auto check = [&](int len) {
        if (len < n / 2) {
            for (int i = len + 1; i <= n / 2; i++) {
                if (s[i] != s[n - i + 1])
                    return false;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (len >= n / 2) {
                if (pre[len][i] < pre[n][i] - pre[len][i])
                    return false;
            } else {
                if (pre[len][i] > pre[n][i] - pre[len][i])
                    return false;
            }
        }
        return true;
    };
    int ans = n;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1], pre[i][s[i] - 'a']++;
    int lo = 1, hi = n;

    while (lo < hi - 1) {
        int mid = (lo + hi) >> 1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cmin(ans, hi);
    reverse(ALL(s));
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1], pre[i][s[i] - 'a']++;
    lo = 1, hi = n;

    while (lo < hi - 1) {
        int mid = (lo + hi) >> 1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cmin(ans, hi);
    cout << ans << '\n';
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