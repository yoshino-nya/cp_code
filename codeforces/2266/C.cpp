/*
date: 2026-09-23 22:07:55
path: ~/Projects/cp_code/codeforces/2266/C.cpp
*/

#include "ios"
#include "iostream"
#include "string"
#include "vector"
#include <algorithm>
#include <format>

#define eprint(...) std::print(stderr, __VA_ARGS__)
#define eprintln(...) std::println(stderr, __VA_ARGS__)

constexpr int INF = 1'000'000'000;
void solve()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> pre(n, INF), suf(n, INF);
    if (s[0] == '0') {
        pre[0] = 0;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (s[i] == '0' ? 0 : 1);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = (i + 1 < n ? suf[i + 1] : 0) + (s[i] == '1' ? 0 : 1);
    }
    int ans = std::min(pre.back(), suf.front());
    for (int i = 1; i < n; i++) {
        ans = std::min(ans, pre[i - 1] + suf[i]);
    }
    std::cout << std::format("{}\n", ans);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}