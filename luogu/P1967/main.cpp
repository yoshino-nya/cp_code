// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

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

// Date: 2025-05-27
// Time: 17:01:29
int fa[10005][21], e[10005][21];

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edge(m);
    for(int i = 0; i < m; i++)
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    vi f(n + 1);
    vc<vc<array<int, 2>>> g(n + 1);
    auto find = [&](auto &&self, int x) -> int{
        return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    auto kruskal = [&](){
        ranges::sort(edge, [](array<int, 3> x, array<int, 3> y){
            return x[2] > y[2];
        });
        for(int i = 1; i <= n; i++)
            f[i] = i;
        for(auto [u, v, w] : edge){
            if(find(find, u) != find(find, v)){
                f[f[v]] = f[u];
                g[u].push_back({v, w});
                g[v].push_back({u, w});
            }
        }
    };
    kruskal();
    vi dep(n + 1);
    auto dfs = [&](auto &&self, int u, int pre) -> void{
        dep[u] = dep[pre] + 1;
        for(auto [v, w] : g[u]){
            if(v == pre) continue;
            fa[v][0] = u, e[v][0] = w;
            self(self, v, u);
        }
    };
    
    for(int i = 1; i <= n; i++){
        if(dep[i] == 0){
            dfs(dfs, i, 0);
            fa[i][0] = i;
            e[i][0] = INF;
        }
    }
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n; j++){
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            e[j][i] = min(e[j][i - 1], e[fa[j][i - 1]][i - 1]);
        }
    }
    auto lca = [&](int x, int y){
        if(find(find, x) != find(find, y)) return -1;
        if(dep[x] < dep[y]) swap(x, y);
        int res = INF;
        for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1){
            if(z & 1){
                cmin(res, e[x][i]);
                x = fa[x][i];
            }
        }
        if(x == y) return res;
        for(int i = 20; x != y && i >= 0; i--){
            if(fa[x][i] != fa[y][i]){
                cmin(res, min(e[x][i], e[y][i]));
                x = fa[x][i], y = fa[y][i];
            }
        }
        cmin(res, min(e[x][0], e[y][0]));
        return res;
    };
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}