/*
date: 2026-09-20 10:53:08
path: ~/Projects/cp_code/luogu/P2257/main.cpp
*/

#include <cstdio>
#include <print>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include <utility>

constexpr int N = 10'000'000;
std::vector<int> primes;
std::array<bool, N + 1> vis;
std::array<int, N + 1> mu;
std::array<long long, N + 1> f;
void solve()
{
    int n, m; scanf("%d%d", &n, &m);
    if(n > m) std::swap(n ,m);
    long long ans = 0;
    for (int i = 1, j; i <= n; i = j + 1) {
        j = std::min(n / (n / i), m / (m / i));
        ans += (f[j] - f[i - 1]) * (n / i) * (m / i);
    }
    std::println("{}", ans);
}
int main()
{
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) {
            primes.push_back(i);
            mu[i] = -1;
            f[i] = 1;
        }
        for (int p : primes) {
            if(i * p > N) break;
            vis[i * p] = true;
            if (i % p == 0) {
                /*
                mu[i] = 0 -> f[i * p] = mu[i]
                else -> f[i * p] = mu[i]
                */
                mu[i * p] = 0;
                f[i * p] = mu[i];
                break;
            }

            mu[i * p] = -mu[i];
            f[i * p] = -f[i] + mu[i];
        }
        f[i] += f[i - 1];
    }
    int t; scanf("%d", &t);
    while(t--) solve();
}