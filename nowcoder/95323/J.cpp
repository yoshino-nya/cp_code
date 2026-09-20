// Author: Zhangwuji
// Date: 2025-01-22
// Time: 18:42:36

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

const int N = 2e6 + 5;

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // map<int,int>mp;
    vector<int> mp(N);
    auto work = [&](int x) {
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (gcd(x, x ^ i) == i)
                    mp[x ^ i]++;
                int j = x / i;
                if (i != j && gcd(x, x ^ j) == j)
                    mp[j ^ x]++;
            }
        }
    };
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += mp[a[i]];
        work(a[i]);
    }
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}