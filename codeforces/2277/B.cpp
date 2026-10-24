/*
date: 2026-10-24 19:24:05
path: ~/Projects/cp_code/codeforces/2277/B.cpp
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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < n) {
            print("{}\n", n);
            return;
        }
    }
    print("0\n");
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