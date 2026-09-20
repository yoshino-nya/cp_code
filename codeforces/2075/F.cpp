// Date: 2025-03-19
// Time: 21:35:44

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)
    vector<int> tr, t;
    SegmentTree(int n)
    {
        tr = t = vector<int>((n + 2) << 2, 0);
    }
    void push_down(int p, int l, int r)
    {
        if (t[p]) {
            t[ls] += t[p];
            t[rs] += t[p];
            tr[ls] += t[p];
            tr[rs] += t[p];
            t[p] = 0;
        }
    }
    void upd(int p, int l, int r, int lx, int rx, int x)
    {
        if (l >= lx && r <= rx) {
            tr[p] += x;
            t[p] += x;
            return;
        }
        push_down(p, l, r);
        if (lx <= mid)
            upd(ls, l, mid, lx, rx, x);
        if (rx > mid)
            upd(rs, mid + 1, r, lx, rx, x);
        tr[p] = max(tr[ls], tr[rs]);
    }
    int query(int p, int l, int r, int lx, int rx)
    {
        if (l >= lx && r <= rx)
            return tr[p];
        push_down(p, l, r);
        int res = 0;
        if (lx <= mid)
            res = max(res, query(ls, l, mid, lx, rx));
        if (rx > mid)
            res = max(res, query(rs, mid + 1, r, lx, rx));
        return res;
    }
};
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), l, r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        if (l.empty() || a[l.back()] > a[i])
            l.push_back(i);
        if (!l.empty() && a[l.back()] < a[i])
            ans = 2;
    }
    if (ans == 1) {
        cout << "1\n";
        return;
    }
    for (int i = n; i >= 1; i--) {
        if (r.empty() || a[r.back()] < a[i])
            r.push_back(i);
    }

    // vector<array<int, 4>> q;
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> q;
    reverse(r.begin(), r.end());
    for (int i = 1; i <= n; i++) {
        int xl = upper_bound(l.begin(), l.end(), i, [&](int x, int y) {
            return a[x] > a[y];
        }) - l.begin(); // 找到第一个小于 a[i]的
        int xr = lower_bound(l.begin(), l.end(), i) - l.begin();
        int yl = upper_bound(r.begin(), r.end(), i) - r.begin();
        int yr = lower_bound(r.begin(), r.end(), i, [&](int x, int y) {
            return a[x] > a[y];
        }) - r.begin(); // 找到第一个小于等于a[i]的
        if (xl < xr && yl < yr) {
            q.push({ xl, 1, yl + 1, yr });
            q.push({ xr, -1, yl + 1, yr });
            // q.push_back({ xl, 1, yl + 1, yr });
            // q.push_back({ xr, -1, yl + 1, yr });
        }
    }
    SegmentTree C(n);
    // sort(q.begin(), q.end());
    for (int i = 0; i <= n; i++) {
        while (!q.empty() && q.top()[0] == i) {
            auto [_, x, l, r] = q.top();
            q.pop();
            C.upd(1, 1, n, l, r, x);
        }
        ans = max(ans, 2 + C.query(1, 1, n, 1, n));
    }
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
/*

*/