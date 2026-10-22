/*
date: 2026-10-22 22:40:51
path: ~/Projects/cp_code/codeforces/2258/C.cpp
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
    auto ask = [](int u, int v, int d) -> int {
        print("? {} {} {}\n", u, v, d);
        std::cout.flush();
        int res;
        std::cin >> res;
        return res;
    };
    int n;
    std::cin >> n;
    int start = 0, cur = 0, end = 1;
    for (int i = 2; i <= n; i++) {
        while (ask(1, i, cur + 1)) {
            start = i;
            cur++;
        }
    }
    for (int i = 1; i <= n; i++) {
        while (ask(start, i, cur + 1)) {
            end = i;
            cur++;
        }
    }
    print("! {} {} {}\n", start, end, cur);
    std::cout.flush();
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