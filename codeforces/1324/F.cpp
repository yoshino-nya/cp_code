/*
date: 2026-09-20 14:06:49
path: ~/Projects/cp_code/codeforces/1324/F.cpp
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <print>
#include <vector>

constexpr int N = 200'000;
std::array<int, N + 1> a, dp, ans;
// std::array<std::array<int, 2>, N + 1> dp, ans;
std::array<std::vector<int>, N + 1> g;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto&& self, int u, int p) -> void {
        dp[u] = a[u] ? 1 : -1;
        for (int v : g[u]) {
            if (v == p)
                continue;
            self(self, v, u);
            if (dp[v] > 0)
                dp[u] += dp[v];
        }
    };
    dfs(dfs, 1, 0);
    ans[1] = dp[1];
    auto dfs1 = [&](auto&& self, int u, int p) -> void {
        for (int v : g[u]) {
            if (v == p)
                continue;
            if (dp[v] < 0)
                ans[v] = std::max(dp[v], ans[u] - 1);
            else {
                ans[v] = std::max(dp[v], ans[u]);
            }
            self(self, v, u);
        }
    };
    dfs1(dfs1, 1, 0);
    for (int i = 1; i <= n; i++) {
        std::print("{} ", ans[i]);
    }
}