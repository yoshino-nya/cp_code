/*
date: 2026-09-25 20:47:22
path: ~/Projects/cp_code/codeforces/126/B_1.cpp
*/

#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
#include <vector>

#define eprint(...) std::print(stderr, __VA_ARGS__)
#define eprintln(...) std::println(stderr, __VA_ARGS__)

void solve()
{
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = std::min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    // std::println(stderr, "{}", z);
    std::set<int> st;
    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        // 小于等于 z[i]
        auto it = st.upper_bound(z[i]);
        if (it != st.begin())
            ans = std::max(*prev(it), ans);
        if (i + z[i] == n)
            st.insert(z[i]);
    }
    if (ans > 0) {
        std::cout << s.substr(0, ans) << "\n";
    } else {
        std::cout << "Just a legend\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
}