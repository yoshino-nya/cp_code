// Date: 2025-03-15
// Time: 14:31:31

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LNF = 1e18;

struct SegTree {
// 需要知道每一段的最大的前缀 最大的后缀
// 以及这一段的和 可能还需要其他的信息
// 还有这一段的最大子段和
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)
    struct info {
        ll sum, pre, suf, res;
    };
    vector<info> tr;
    info merge(info x, info y)
    {
        info res = { 0, 0, 0, 0 };
        res.pre = max(x.pre, x.sum + y.pre);
        res.suf = max(y.suf, y.sum + x.suf);
        res.sum = x.sum + y.sum;
        res.res = max({ res.pre, res.suf, x.suf + y.pre, x.res, y.res });
        return res;
    }
    info query(int p, int l, int r, int lx, int rx)
    {
        if (l >= lx && r <= rx)
            return tr[p];
        if (lx <= mid && rx > mid)
            return merge(query(ls, l, mid, lx, rx), query(rs, mid + 1, r, lx, rx));
        if (lx <= mid)
            return query(ls, l, mid, lx, rx);
        if (rx > mid)
            return query(rs, mid + 1, r, lx, rx);
    }
    void upd(int p, int l, int r, int x, int val)
    {
        if (l == r) {
            tr[p] = { val, val, val, val };
            return;
        }
        if (x <= mid)
            upd(ls, l, mid, x, val);
        else
            upd(rs, mid + 1, r, x, val);
        tr[p] = merge(tr[ls], tr[rs]);
    }
    SegTree(vector<int>& a)
    {
        tr = vector<info>(a.size() << 2);
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) {
                tr[p] = { a[l], a[l], a[l], a[l] };
                return;
            }
            self(self, ls, l, mid);
            self(self, rs, mid + 1, r);
            tr[p] = merge(tr[ls], tr[rs]);
        };
        build(build, 1, 1, a.size() - 1);
    }
};

void ChatGptDeepSeek()
{
    // 实际上就是要查询区间的最大子段和
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegTree C(a);
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int l, r;
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            cout << C.query(1, 1, n, l, r).res << '\n';
        } else {
            int x, val;
            cin >> x >> val;
            C.upd(1, 1, n, x, val);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}