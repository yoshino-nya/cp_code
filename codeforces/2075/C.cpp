// Date: 2025-03-17
// Time: 22:51:47

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// struct Fenwick {
//     vector<int> b;
//     Fenwick(int n)
//     {
//         b = vector<int>(n + 1);
//     }
//     int lowbit(int x) { return (x) & (-x); }
//     void upd(int i, int x)
//     {
//         // i = max(1, i);
//         while (i < b.size()) {
//             b[i] += x;
//             i += lowbit(i);
//         }
//     }
//     int query(int i)
//     {
//         int res = 0;
//         while (i) {
//             res += b[i];
//             i -= lowbit(i);
//         }
//         return res;
//     }
// };
struct SegmentTree {
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)
    vector<ll> tr, t;
    SegmentTree(int n)
    {
        tr = t = vector<ll>(n << 2, 0);
    }
    void push_down(int p, int l, int r)
    {
        if (t[p]) {
            t[ls] += t[p];
            t[rs] += t[p];
            tr[ls] += t[p] * (mid - l + 1);
            tr[rs] += t[p] * (r - (mid + 1) + 1);
            t[p] = 0;
        }
    }
    void upd(int p, int l, int r, int lx, int rx, int x)
    {
        if (l >= lx && r <= rx) {
            tr[p] += (r - l + 1) * x;
            t[p] += x;
            return;
        }
        push_down(p, l, r);
        if (lx <= mid)
            upd(ls, l, mid, lx, rx, x);
        if (rx > mid)
            upd(rs, mid + 1, r, lx, rx, x);
        tr[p] = tr[ls] + tr[rs];
    }
    ll query(int p, int l, int r, int lx, int rx)
    {
        if (l >= lx && r <= rx)
            return tr[p];
        push_down(p, l, r);
        ll res = 0;
        if (lx <= mid)
            res += query(ls, l, mid, lx, rx);
        if (rx > mid)
            res += query(rs, mid + 1, r, lx, rx);
        return res;
    }
};

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    //[1,a[i]]是有贡献的
    ll ans = 0;
    SegmentTree C(n + 1);
    for (int i = 1; i <= m; i++) {
        if (a[i] == n)
            a[i]--;
        ans += C.query(1, 1, n, n - a[i], n - 1);
        C.upd(1, 1, n, 1, a[i], 1);
    }
    cout << ans * 2 << '\n';
}
/*
5 2
2 4

12 3
5 8 9
[1,5]

*/

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