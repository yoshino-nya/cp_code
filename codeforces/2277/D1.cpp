/*
date: 2026-10-24 20:39:32
path: ~/Projects/cp_code/codeforces/2277/D1.cpp
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

constexpr int MOD = 998'244'353;
void solve()
{
    long long l, r;
    std::cin >> l >> r;
    long long ans = 0;
    
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