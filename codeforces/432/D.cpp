/*
date: 2026-10-23 23:42:10
path: ~/Projects/cp_code/codeforces/432/D.cpp
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
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    dbg("{}\n", z);
    std::vector<int> ans, f(n + 1);
    for (int i = 0; i < n; i++) {
        if (z[i] == n - i) {
            ans.push_back(n - i);
        }
        if (z[i]) {
            f[1]++;
            if (z[i] + 1 <= n)
                f[z[i] + 1]--;
        }
    }
    dbg("{}\n", f);
    for (int i = 0, cur = 0; i <= n; i++) {
        cur += f[i];
        f[i] = cur;
    }
    print("{}\n", ans.size());
    for (auto x : ans | std::views::reverse) {
        print("{} {}\n", x, f[x]);
    }
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