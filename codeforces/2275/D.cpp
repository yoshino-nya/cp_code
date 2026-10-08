/*
date: 2026-10-08 11:13:42
path: ~/Projects/cp_code/codeforces/2275/D.cpp
*/

#include <array>
#include <iostream>
#include <vector>

void solve()
{
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            std::cin >> a[i][j];
    }
    auto check = [&](long long val) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long cur = 0LL + a[i][0] + a[i][1] + a[i][2];
            if (cur >= val)
                continue;
            int diff = std::max({ a[i][0] - a[i][1], a[i][0] - a[i][2], a[i][1] - a[i][2] });
            if (diff <= 0) {
                if (a[i][0] == a[i][2])
                    return false;
                sum += -diff + 1;
                cur -= -diff + 1;
                // std::cerr << diff << "\n";
                if (sum > k)
                    return false;
            }
            sum += val - cur;
            if (sum > k)
                return false;
        }
        return sum <= k;
    };
    long long lo = -(long long)1e18 * 2, hi = (long long)1e18 * 2;
    while (lo < hi - 1) {
        long long mid = (lo + hi) >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    std::cout << lo << "\n";
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