/*
date: 2026-10-14 23:11:45
path: ~/Projects/cp_code/codeforces/2276/D.cpp
*/

#include <ios>
#include <iostream>
#include <vector>

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> color(n + 1, -1);
    bool ok = false;
    auto dfs = [&](auto&& self, int u) -> void {
        for (auto v : g[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                if (g[v].size() > 1 && g[u].size() > 1)
                    ok = true;
                self(self, v);
            }
        }
    };
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (g[i].empty()) {
                std::cout << "Brain Melt\n";
                return;
            }
            color[i] = 0;
            cnt++;
            dfs(dfs, i);
        }
    }
    if (ok || cnt > 1)
        std::cout << "Many\n";
    else
        std::cout << "2\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}