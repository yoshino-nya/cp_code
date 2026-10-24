/*
date: 2026-10-24 21:13:44
path: ~/Projects/cp_code/codeforces/580/D.cpp
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

std::array<std::array<int, 18>, 18> add;
std::array<std::array<long long, 18>, 1 << 18> dp;
void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++)
        dp[i].fill(-1);
    for (int i = 1; i <= k; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        add[x - 1][y - 1] = c;
    }
    std::queue<std::array<int, 3>> q;
    q.push({ 0, -1, 0 });
    long long ans = 0;
    while (!q.empty()) {
        auto [stat, lst, cnt] = q.front();
        q.pop();
        if (cnt == m) {
            ans = std::max(dp[stat][lst], ans);
            continue;
        }
        for (int i = 0; i < n; i++) {
            int new_stat = stat | (1 << i);
            if (new_stat != stat) {
                long long val = a[i];
                if (lst != -1) {
                    val += dp[stat][lst] + add[lst][i];
                }
                if (val > dp[new_stat][i]) {
                    dp[new_stat][i] = val;
                    q.push({ new_stat, i, cnt + 1 });
                }
            }
        }
    }
    print("{}\n", ans);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int testcases;
    // std::cin >> testcases;
    // for (int _ = 0; _ < testcases; _++)
    solve();
}