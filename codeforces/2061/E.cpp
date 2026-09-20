// Author: Zhangwuji
// Date: 2025-01-21
// Time: 00:15:22

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
#define int long long
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<multiset<int>> num(m + 1, multiset<int>());
    // num[1] &b[1]之后 减少的值
    // 然后我们需要知道谁和b1&了之后可以减少这么多
    // mp[1][val]
    vi a(n + 1);
    vi b(m + 1);
    vector<map<int, multiset<int>>> mp(m + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = a[i] - (a[i] & b[j]);
            num[j].insert(x);
            mp[j][x].insert(i);
        }
    }
    while (k--) {
        int mx = 0;
        for (int i = 1; i <= m; i++) {
            cmax(mx, *num[i].rbegin());
            // assert(num[i].size());
        }
        if (!mx)
            continue;
        for (int i = 1; i <= m; i++) {
            if (*num[i].rbegin() == mx) {
                // assert(mp[i][mx].size());
                int l = *mp[i][mx].begin();
                int x = a[l];
                a[l] &= b[i];
                sum -= mx;
                for (int j = 1; j <= m; j++) {
                    int y = x - (x & b[j]);
                    int z = a[l] - (a[l] & b[j]);
                    // assert(num[j].size());
                    auto it = num[j].lower_bound(y);
                    if (it != num[j].end() && *it == y)
                        num[j].erase(num[j].lower_bound(y));
                    num[j].insert(z);
                    it = mp[j][y].lower_bound(l);
                    if (it != mp[j][y].end() && *it == l)
                        mp[j][y].erase(l);
                    mp[j][z].insert(l);
                }
                break;
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += a[i];
    assert(res == sum);
    // cerr<<'\n';
    cout << sum << '\n';
}

signed main()
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