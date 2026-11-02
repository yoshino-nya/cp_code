/*
date: 2026-11-02 17:07:31
path: ~/Projects/cp_code/codeforces/2271/D.cpp
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

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<long long, long long>> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i].first >> vec[i].second;
    }
    std::deque<std::pair<long long, long long>> dq;
    long long cnt = 0;
    for (auto [i, x] : vec | std::views::enumerate) {
        auto [l, r] = x;
        while (!dq.empty() && dq.front().second + m - 1 <= l) {
            cnt -= dq.front().second - dq.front().first + 1;
            dq.pop_front();
        }
        while (!dq.empty() && cnt + r - l + 1 - (dq.front().second - dq.front().first + 1) >= k) {
            cnt -= dq.front().second - dq.front().first + 1;
            dq.pop_front();
        }
        dq.push_back({ l, r });
        cnt += r - l + 1;
        if (cnt >= k) {
            long long L = 
        }
    }
    print("-1\n");
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