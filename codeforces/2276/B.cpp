/*
date: 2026-10-14 22:50:20
path: ~/Projects/cp_code/codeforces/2276/B.cpp
*/

#include <ios>
#include <iostream>

void solve()
{
    std::string s;
    std::cin >> s;
    // 1010101 -> 1 -> 2 -> 3
    int x = 0, y = 0;
    for (int i = 1; i + 1 < s.size(); i++) {
        if (s[i] != s[i - 1] && s[i] != s[i + 1])
            x = 1;
        else if (s[i - 1] == s[i + 1])
            y = 1;
    }
    std::cout << x + y + 1 << "\n";
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