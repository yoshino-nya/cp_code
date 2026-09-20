// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define int long long
#define rep(N) for(int i = 1; i <= N; i++)

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
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-06-06
// Time: 20:21:22
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vl a(n + 1), e(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vc<vc<pii>> g(n + 1);
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int x, y;
    cin >> x >> x >> y;
    vi fa(n + 1);
    vl dis(n + 1);
    auto dfs = [&](auto &&self, int u, int pre) -> void{
        e[u] = a[u];
        for(auto [v, w] : g[u]){
            if(v == pre) continue;
            dis[v] = dis[u] + w;
            self(self, v, u);
            fa[v] = u;
            cmax(e[u], e[u] + e[v] - 2 * w);
        }
    };
    dfs(dfs, x, 0);
    dbg(e);
    vi p;
    for(int i = y; i != x; i = fa[i])
        p.push_back(i);
    dbg(p);
    reverse(all(p));
    dbg(e);
    for(auto z : p){
        ll w = dis[z] - dis[fa[z]];
        dbg(z, w, e[z]);
        if(e[z] - 2 * w > 0){
            e[fa[z]] -= e[z] - 2 * w;
        }
    }
    dbg(e);
    for(int i = p.size() - 1; i >= 0; i--){
        int z = p[i];
        ll w = dis[z] - dis[fa[z]];
        e[fa[z]] += e[z] - w;
    }
    dbg(e);
    cmax(e[x], -1);
    cout << e[x] << '\n';
}

signed main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}