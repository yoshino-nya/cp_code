// Author: Zhangwuji
// Date: 2025-02-27
// Time: 23:25:40

// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/usr/codes/cp/template/debug.hpp"
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

constexpr int mod = 998244353; // 998244353

void solve()
{
    int n;
    cin >> n;
    vi p(n + 1);
    vector<vi> adj(n + 1, vi());
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    vi d(n + 1);
    // vector<vi> g(n + 1, vi());
    vi cnt(n+1);
    auto dfs1 = [&](auto&& self, int u) -> void {
        // g[d[u]].push_back(u);
        cnt[d[u]]++;
        for (auto v : adj[u]) {
            d[v] = d[u] + 1;
            self(self, v);
        }
    };
    dfs1(dfs1, 1);
    vector<ll> res(n + 1);
    ll ans = 1;
    res[1] = 1;
    // auto dfs = [&](auto&& self, int u) -> void {
    //     for (auto v : g[d[u] + 1]) {
    //         if ((u != 1) && (p[v] == u))
    //             continue;
    //         // ans=(ans+res[u])%mod;
    //         res[v] = (res[v] + res[u]) % mod;
    //         // self(self, v);
            
    //     }
    // };
    // dfs(dfs, 1);
    // for(int i=0;i<n;i++){
    //     if(g[i].empty()) break;
    //     for(auto v:g[i])
    //         dfs(dfs,v);
    // }

    //每一层其实都是固定的 只要深度相同 那么贡献一定相同

    //
    ans+=cnt[1];
    res[2]=1;
    for(int i=2;i<=n;i++){
        //每一个深度为i的点 到达的方式数都为 cnt[i-1]*res[i-1]
        res[i]=(cnt[i-1]-1)*res[i-1]%mod;
        ans=(ans+res[i]*cnt[i]%mod)%mod;
    }
    cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}