/*
date: 2026-10-21 12:22:30
path: ~/Projects/cp_code/codeforces/2275/E.cpp
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
    auto dst = [](int x, int y) -> int {
        return x == y ? 2 : 1;
    };
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    int ans = 0, cur = dst(a.back(), b.back());
    for (int i = 0; i + 1 < n; i++)
        cur += dst(a[i], b[i + 1]) + dst(b[i], a[i + 1]);
    ans = cur;
    for (int i = 0; i + 1 < n; i++) {
        cur -= dst(a[i], b[i + 1]);
        cur += dst(a[i], b[i]);
        ans = std::max(ans, cur);
    }
    std::print("{}\n", ans);
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