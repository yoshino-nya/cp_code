/*
date: 2026-09-21 23:53:52
path: ~/Projects/cp_code/codeforces/2266/E.cpp
*/

#include <array>
#include <cassert>
#include <cstdio>
#include <format>
#include <print>
#include <vector>
constexpr int N = 200'000;
std::array<int, N + 1> minp, maxp;
std::array<long long, N + 1> a;
std::vector<int> primes;

int calc(int x, int k) {
    while(x / maxp[x] > k) {
        x /= maxp[x];
    }
    return maxp[x];
}
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if(x < k) continue;
        a[x] += 1;
    }
    long long ans = 0;

    for (int i = n; i > k; i--) {
        ans += a[i];
        int p = calc(i, k);
        a[i / p] += 1LL * a[i] * p;
        a[i] = 0;
    }
    for (int i = 1; i <= k; i++)
        a[i] = 0;
    std::println("{}", ans);
}
/*
有点麻烦，难道我们去看最终保留多少个 哪几个质因子？
我们只关注数量来着
如果数量一样 那我们希望删掉的质因子尽量的小吧？

尽量是先删小的再删大的
6 -> 1 要删掉三个因子 先删小的，

但是删的次数也很关键。。。删的多肯定不如删一次大的。。

怎么算呀 好难，直接找删的次数最少是多少，然后尽量去把大的质因子拿掉？（

或者单独考虑对每个数字操作怎么弄最合适？或者。。。

瞎搞一下试一下。。。不管了先睡觉吧
*/
int main()
{
    for (int i = 2; i <= N; i++) {
        if (!minp[i]) {
            primes.push_back(i);
            minp[i] = maxp[i] = i;
        }
        for (int p : primes) {
            if (i * p > N)
                break;
            minp[i * p] = p;
            maxp[i * p] = maxp[i];
            if (i % p == 0)
                break;
        }
        // std::println("{} {} {}", i, minp[i], maxp[i]);
    }
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}