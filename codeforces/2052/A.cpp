// Author: Zhangwuji
// Date: 2025-01-06
// Time: 13:13:38

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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 首先 每一个比它大的 要把他超过
    vector<pii> ans;
    vector<bool> vis(n + 1);
    for (int i = n; i >= 1; i--) {

        for (int j = a[i] - 1; j >= 1; j--) {
            if (vis[j])
                continue;
            ans.push_back({ a[i], j });
            // ans.push_back({j,a[i]});
        }
        for (int j = 1; j < a[i]; j++) {
            if (vis[j])
                continue;
            ans.push_back({ j, a[i] });
        }
        for (int j = a[i] + 1; j <= n; j++) {
            // cerr<<a[i]<<" "<<j<<'\n';
            if (vis[j])
                continue;
            ans.push_back({ j, a[i] });
        }
        vis[a[i]] = true;
    }
    // 你只能超过比你大的人
    // 所以需要比你小的先超过你
    // 然后你来超过所有人
    //
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans)
        cout << x << " " << y << '\n';
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