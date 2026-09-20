/*
date: 2026-09-20 09:56:27
path: ~/Projects/cp_code/luogu/P1447/main.cpp
*/

#include <cstdio>
#include <print>
#include <array>
#include <algorithm>

constexpr int N = 100'000;
std::array<long long, N + 1> cnt;
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    int l = std::max(n, m);
    for (int i = 1; i <= l; i++)
        cnt[i] = 1LL * (n / i) * (m / i);
    long long res = 0;
    for(int i = l; i >= 1; i--) {
        for(int j = i * 2; j <= l; j += i)
            cnt[i] -= cnt[j];
        res += cnt[i] * i;
    }
    std::println("{}", 2 * res - 1LL * n * m);
}