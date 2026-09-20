// Date: 2025-03-19
// Time: 18:19:17

#include <bits/stdc++.h>
// #include "C:/usr/codes/cp/template/debug.hpp"
using namespace std;

struct Fenwick {
    vector<int> b;
    Fenwick()
    {
        b.resize(1e6 + 1, 0);
    }
    int lowbit(int x) { return (x) & (-x); }
    void add(int i, int x)
    {
        while (i && i < b.size()) {
            b[i] += x;
            i += lowbit(i);
        }
    }
    int ask(int i)
    {
        int res = 0;
        while (i) {
            res += b[i];
            i -= lowbit(i);
        }
        return res;
    }
} C;

constexpr int N = 1e6 + 10;
int fst[N], lst[N];

void ChatGptDeepSeek()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), pre(n + 1), suf(n + 1);
    pre[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = min(pre[i - 1], a[i]);
        lst[a[i]] = i;
    }
    suf[n] = a[n];
    fst[a[n]] = n;
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = max(suf[i + 1], a[i]);
        fst[a[i]] = i;
    }

    int ans = 1;
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
    vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
    auto work = [&]() {
        vector<int> result(n + 1);
        for (int i = 1; i <= n; i++) {
            while (!pq.empty() && pq.top()[0] == i) {
                // dbg(pq.top());
                auto [l, r, x, j] = pq.top();
                pq.pop();
                result[j] -= C.ask(x);
            }
            C.add(a[i], 1);
            for (auto [x, j] : g[i]) {
                result[j] += C.ask(x);
            }
        }
        for (int i = 1; i <= n; i++)
            C.add(a[i], -1);
        // 计算区间[l,r] 小于等于x的数量
        return result;
    };
    for (int i = 1; i < n; i++) {
        // 查询前缀最小值和后缀最大值
        int min_val = pre[i], max_val = suf[i + 1];

        if (min_val < max_val) {
            pq.push({ fst[min_val], lst[max_val], max_val - 1, i });
            g[lst[max_val]].push_back({ max_val - 1, i });
        }
    }
    // dbg(pq);
    /* 先查询值小于max_val的，然后直接减去小于等于min_val的就行 */
    vector<int> res = work();
    // dbg(g);
    // dbg(res);
    assert(pq.empty());
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++) {
        // 查询前缀最小值和后缀最大值
        int min_val = pre[i], max_val = suf[i + 1];

        if (min_val < max_val) {
            res[i] += 2;
            pq.push({ fst[min_val], lst[max_val], min_val, i });
            g[lst[max_val]].push_back({ min_val, i });
        }
    }
    vector<int> tmp = work();
    for (int i = 1; i <= n; i++) {
        fst[a[i]] = lst[a[i]] = 0;
        // if (res[i])
        ans = max(ans, res[i] - tmp[i]);
    }

    // 需要查询 [l,r] 之间的 值在 [x,y]的 数字的数量
    // 怎么扫描线来着？又不太记得了。。
    // 那就先算小于 y 的数量，再减一下小于x的数量
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}