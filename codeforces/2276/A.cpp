/*
date: 2026-10-14 22:37:57
path: ~/Projects/cp_code/codeforces/2276/A.cpp
*/

#include <ios>
#include <iostream>

void solve()
{
    int a, b;
    std::cin >> a >> b;
    if (a <= b) {
        std::cout << "-1\n";
        return;
    }
    if (2 * b <= a) {
        std::cout << b << "\n";
        return;
    }
    for (int i = b; i >= 0; i--) {
        if (2 * i + b - i < a) {
            std::cout << i + 1 << "\n";
            return;
        }
    }
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