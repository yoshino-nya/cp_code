/*
date: 2026-10-14 23:00:13
path: ~/Projects/cp_code/codeforces/2276/C.cpp
*/

#include "vector"
#include <ios>
#include <iostream>

void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), pre(n + 1), cnt(k);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % k;
        cnt[pre[i]]++;
    }
    int idx = 1;
    long long ans = 0;
    for (int l = 1; l + k <= n; l++) {
        // [l + k, n] 里有多少个 pre[l - 1]
        while (idx < l + k) {
            cnt[pre[idx]]--;
            idx++;
        }
        ans += cnt[pre[l - 1]];
    }
    std::cout << ans << "\n";
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