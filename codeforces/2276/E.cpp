/*
date: 2026-10-14 23:47:59
path: ~/Projects/cp_code/codeforces/2276/E.cpp
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <ios>
#include <iostream>
#include <print>
#include <set>
#include <vector>

constexpr int N = 300'001;
long long tr[N << 2], tag[N << 2];

void init(int p, int l, int r)
{
    tag[p] = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    init(p << 1, l, mid), init(p << 1 | 1, mid + 1, r);
}
void add(int p, int l, int r, int lx, int rx, int x)
{
    if (l >= lx && r <= rx) {
        tag[p] += x;
        return;
    }
    int mid = (l + r) >> 1;
    if (lx <= mid)
        add(p << 1, l, mid, lx, rx, x);
    if (rx > mid)
        add(p << 1 | 1, mid + 1, r, lx, rx, x);
}
void push_down(int p, int l, int r)
{
    int mid = (l + r) >> 1;
    tag[p << 1] += tag[p];
    tag[p << 1 | 1] += tag[p];
    tag[p] = 0;
}
long long query(int p, int l, int r, int i)
{
    if (l == r)
        return tag[p];
    if (tag[p]) {
        push_down(p, l, r);
    }
    int mid = (l + r) >> 1;
    if (i <= mid)
        return query(p << 1, l, mid, i);
    return query(p << 1 | 1, mid + 1, r, i);
}
void solve()
{
    /*
    把 bad string 找出来，然后删除这个 string 影响到的答案。
    把有 2025/2026 的最短子串找出来
    按 [l, r] 排序，
    对于 i，以它开头的 bad string
    r2 是在右侧的 2026 的最小的 r
    r1 是右侧的 2025 的最小的 r
    那么 bad string 就是 [i, r1] -> [i, r2]
    那么 [r1, r2] 区间 -1
    */
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::array<int, 10>> nxt(n);
    std::array<int, 10> lst;
    for (int i = 0; i < 10; i++)
        lst[i] = -1;
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = lst;
        lst[s[i] - '0'] = i;
    }
    std::vector<std::pair<int, int>> five, six;
    std::multiset<int> six_s, five_s;
    int five_idx = 0, six_idx = 0;
    for (int i = 0; i < n; i++) {
        // 先找一个 2，再找一个 0，再找一个 2，再找一个 5 and 6
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
    // std::println(stderr, "{} \n{}", five, six);
    // 所有 l >= i，然后找里面最大的 r，那就是用一个 set
    std::vector<long long> add_vec(n + 1);
    std::vector<long long> res(n + 1);
    for (int i = 0; i < n;) {
        // std::cerr << i << "\n";
        while (five_idx < five.size() && five[five_idx].first < i) {
            five_s.erase(five_s.find(five[five_idx].second));
            five_idx++;
        }
        while (six_idx < six.size() && six[six_idx].first < i) {
            six_s.erase(six_s.find(six[six_idx].second));
            six_idx++;
        }
        if (five_s.empty()) {
            // 说明后面没有 bad string 了
            // continue;
            break;
        }
        int r1 = *five_s.begin();
        int r2 = n - 1;
        if (!six_s.empty()) {
            r2 = std::min(r2, *six_s.begin() - 1);
        }
        // std::cerr << r1 << " " << r2 << '\n';
        // [r1, r2] 区间 -1

        if (r1 > r2) {
            i++;
            continue;
        }
        int val = r2 - r1 + 1;
        // add(1, 1, n, i + 1, r1 + 1, val);
        // [r1 + 2, r2]
        // 分别加 val - 1, ... 1
        // 差分一下就行，，好像没必要用线段树？

        add(1, 1, n, i + 1, r1 + 1, val);
        /*
        [r1 + 2, r2 + 1] 需要修正一下
        -1 -2 -3
        */
        /*
        不对，我们这里记的应该只是以 i 开头，因为我们只能确定，[i + 1, r1 + 1] -> -val
        后面那一部分的话…… bad string 的数量确实是 1,2,3 这样子呀，减少的话（
        所以区间更新没毛病，差分也没毛病

        不对。。。
        r1 + 2 是 val - 1，后面是 val - 2
        所以是一个 反着的差分

        还有点问题吗？
        既然这里出现了 bad，贡献也在这里count了，那之后是不是，按道理可以直接 skip 到 r1 + 1 去
        ……

        唉唉 不知道 瞎搞一下得了
        */
        add_vec[r2 + 1] += 1;
        add_vec[r1 + 1] -= 1;
        i = r1 + 2;
    }
    long long add_val = 0;
    for (int i = n; i >= 1; i--) {
        add_val += add_vec[i];
        res[i] = add_val;
    }
    // 区间修改，单点查询
    for (int i = 1; i <= n; i++) {
        long long ans = 1LL * i * (n - i + 1) - query(1, 1, n, i) - res[i];
        std::cout << ans << " \n"[i == n];
    }
    init(1, 1, n);
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