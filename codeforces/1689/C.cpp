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

// Date: 2025-05-06
// Time: 15:47:12
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vc<vi> g(n + 1, vi());
    for(int  i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    vi dp(n + 1), siz(n + 1);
    auto dfs1 = [&](auto &&self, int u, int pre) -> void{
        siz[u] = 1, dp[u] = 0;
        // dp_i 表示 i 节点感染 的最大得分
        // 如果有一个节点被删除了 那么它的子树就都不用考虑了
        int s = 0;
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
            siz[u] += siz[v];
            s += dp[v];
        }
        for(auto v : g[u]){
            if(v == pre) continue;
            cmax(dp[u], s - dp[v] + siz[v] - 1);
        }
    };
    dfs1(dfs1, 1, 0);
    cout << dp[1] << '\n';
}

int main()
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