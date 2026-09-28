/*
date: 2026-09-28 20:40:40
path: ~/Projects/cp_code/codeforces/1837/F_1.cpp
*/

#include <ios>
#include <iostream>
#include <queue>
#include <vector>

#define eprint(...) std::print(stderr, __VA_ARGS__)
#define eprintln(...) std::println(stderr, __VA_ARGS__)

void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    /*
    把选择的数字分成两部分，并且和尽量小，并且数量不超过 k
    */
    auto check = [&](long long val) {
        std::vector<int> pre(n + 1);
        long long sum = 0;
        std::priority_queue<int> pq;
        for (int i = 1; i <= n; i++) {
            pq.push(a[i]);
            sum += a[i];
            while (sum > val) {
                sum -= pq.top();
                pq.pop();
            }
            pre[i] = pq.size();
        }
        if (pre[n] >= k)
            return true;
        while (!pq.empty())
            pq.pop();
        sum = 0;
        for (int i = n; i > 1; i--) {
            pq.push(a[i]);
            sum += a[i];
            while (sum > val) {
                sum -= pq.top();
                pq.pop();
            }
            if (pre[i - 1] + pq.size() >= k)
                return true;
        }
        return false;
    };
    long long lo = 0, hi = (long long)3e14 + 1;
    while (lo < hi - 1) {
        long long mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    std::cout << hi << "\n";
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