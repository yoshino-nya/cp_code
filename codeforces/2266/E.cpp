/*
date: 2026-09-22 22:03:22
path: ~/Projects/cp_code/codeforces/2266/E.cpp
*/

#include <array>
#include <climits>
#include <cstdio>
#include <print>
#include <vector>

constexpr int N = 200'000;
std::array<int, N + 1> minp, a, cost;
std::vector<int> primes;

std::vector<int> get_primes(int x)
{
    std::vector<int> res;
    while (x > 1) {
        int p = minp[x];
        while (x % p == 0)
            x /= p;
        res.push_back(p);
    }
    return res;
}
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        a[i] = cost[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x > k)
            a[x]++;
    }

    long long ans = 0;
    for (int i = k + 1; i <= n; i++) {
        cost[i] = INT_MAX;
        for (int p : get_primes(i)) {
            cost[i] = std::min(cost[i], 1 + cost[i / p] * p);
        }
        ans += 1LL * cost[i] * a[i];
    }
    // for (int i = 1; i <= n; i++)
    //     std::print(stderr, "{} ", cost[i]);
    // std::println(stderr);
    std::println("{}", ans);
}
int main()
{
    for (int i = 2; i <= N; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > N)
                break;
            minp[i * p] = p;
            if (i % p == 0)
                break;
        }
    }
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}