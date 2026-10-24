/*
date: 2026-10-24 19:43:10
path: ~/Projects/cp_code/codeforces/2277/C.cpp
*/

#include "bits/stdc++.h"

template <class... Args>
inline void print(std::format_string<Args...> fmt, Args&&... args)
{
    std::cout << std::format(fmt, std::forward<Args>(args)...);
}

template <class... Args>
inline void eprint(std::format_string<Args...> fmt, Args&&... args)
{
    std::cerr << "\033[31m" << std::format(fmt, std::forward<Args>(args)...) << "\033[0m";
}

#ifdef DEBUG
#define dbg(...) eprint("[ {} ] ", __LINE__), eprint(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

constexpr int N = 500'000;
std::array<std::array<int, 20>, N + 1> fa;
void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int v;
        std::cin >> v;
        g[v].push_back(1);
        g[1].push_back(v);
    }
    std::vector<bool> vis(n + 1);
    int ans = 0;
    auto dfs = [&](auto &&self, int u, int dis) {
        if (u == 1) {
            ans = std::max(ans, dis);
            return;
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                self(self, v, dis + 1);
                vis[v] = false;
            }
        }
    };
    vis[n] = true;
    dfs(dfs, n, 0);
    print("{}\n", ans);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int testcases;
    std::cin >> testcases;
    for (int _ = 0; _ < testcases; _++)
        solve();
}