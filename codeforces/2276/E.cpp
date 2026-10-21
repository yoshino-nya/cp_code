/*
date: 2026-10-14 23:47:59
path: ~/Projects/cp_code/codeforces/2276/E.cpp
*/

#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <set>
#include <vector>

void solve()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::array<int, 10>> nxt(n);
    std::array<int, 10> lst;
    lst.fill(-1);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = lst;
        lst[s[i] - '0'] = i;
    }
    std::vector<std::pair<int, int>> five, six;
    std::multiset<int> six_s, five_s;
    int five_idx = 0, six_idx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            int idx = nxt[i][0];
            if (idx == -1)
                continue;
            idx = nxt[idx][2];
            if (idx == -1)
                continue;
            if (nxt[idx][5] != -1) {
                five.push_back({ i, nxt[idx][5] });
                five_s.insert(nxt[idx][5]);
            }
            if (nxt[idx][6] != -1) {
                six.push_back({ i, nxt[idx][6] });
                six_s.insert(nxt[idx][6]);
            }
        }
    }

    std::vector<long long> diff1(n), diff2(n);
    std::vector<long long> res(n + 1);
    for (int i = 0; i < n; i++) {
        while (five_idx < five.size() && five[five_idx].first < i) {
            five_s.erase(five_s.find(five[five_idx].second));
            five_idx++;
        }
        while (six_idx < six.size() && six[six_idx].first < i) {
            six_s.erase(six_s.find(six[six_idx].second));
            six_idx++;
        }
        if (five_s.empty()) {
            break;
        }
        int r1 = *five_s.begin();
        int r2 = n;
        if (!six_s.empty()) {
            r2 = std::min(r2, *six_s.begin());
        }

        if (r1 > r2) {
            continue;
        }
        int cnt = r2 - r1;

        diff1[i] += cnt;
        if (r1 + 1 < n) {
            diff2[r1 + 1] -= 1;
        }
        if (r2 < n) {
            diff1[r2] -= 1;
            diff2[r2] += 1;
        }
    }
    // std::cerr << format("{} \n {} \n", diff1, diff2);
    long long cur = 0, add = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff1[i - 1];
        add += diff2[i - 1];
        cur += add;
        // std::cerr << std::format("{} {} | {}", cur, add, " \n"[i == n]);
        // cur += add;
        long long ans = 1LL * i * (n - i + 1) - cur;
        std::cout << ans << " \n"[i == n];
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