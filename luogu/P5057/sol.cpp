#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
    vector<int> tr, tag;
    SegmentTree(int n)
    {
        tr = vector<int>(n << 2);
        tag = vector<int>(n << 2);
    }
    void op(int p, int l, int r)
    {
        tr[p] = r - l + 1 - tr[p];
        tag[p] ^= 1;
    }
    void push_down(int p, int l, int r)
    {
        if (tag[p])
        {
            op(ls, l, mi), op(rs, mi + 1, r);
            tag[p] ^= 1;
        }
    }
    void flip(int p, int l, int r, int lx, int rx)
    {
        if (l >= lx && r <= rx)
        {
            op(p, l, r);
            return;
        }
        push_down(p, l, r);
        if (lx <= mi)
            flip(ls, l, mi, lx, rx);
        if (mi < rx)
            flip(rs, mi + 1, r, lx, rx);
        tr[p] = tr[ls] + tr[rs];
    }
    int ask(int p, int l, int r, int i)
    {
        if (l == r)
            return tr[p];
        push_down(p, l, r);
        if (i <= mi)
            return ask(ls, l, mi, i);
        return ask(rs, mi + 1, r, i);
    }
};
void ChatGptDeepSeek() // Date: 2025-04-08
{                      // Time: 14:34:58
    int n, q;
    cin >> n >> q;
    SegmentTree Tr(n + 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            Tr.flip(1, 1, n, l, r);
        }
        else
        {
            int i;
            cin >> i;
            cout << Tr.ask(1, 1, n, i) << "\n";
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