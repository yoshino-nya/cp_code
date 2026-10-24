
/*
date: 2026-10-24 19:08:16
path: ~/Projects/cp_code/codeforces/2277/A.cpp
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0 || cnt[i] + sum < (i + 1) * k) {
            print("{}\n", i);
            break;
        }
        sum += cnt[i];
    }
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