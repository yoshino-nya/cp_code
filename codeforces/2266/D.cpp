/*
date: 2026-09-22 23:04:06
path: ~/Projects/cp_code/codeforces/2266/D.cpp
*/

#include <algorithm>
#include <cstdio>
#include <print>
#include <vector>

#define eprint(...) std::print(stderr, __VA_ARGS__)
#define eprintln(...) std::println(stderr, __VA_ARGS__)

void solve()
{
    int n;
    scanf("%d", &n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    std::sort(a.begin() + 1, a.end());
    a.erase(std::unique(a.begin() + 1, a.end()), a.end());
    int ans = 0;
    // std::println(stderr, "{}", a);
    for(int i = 1, len = 0; i < a.size(); i++) {
        if(a[i] != a[i - 1] + 1)
            len = 0;
        len++;
        ans = std::max(ans, len);
    }
    std::println("{}", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}