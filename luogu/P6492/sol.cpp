// Author: Zhangwuji
// Date: 2024-12-20
// Time: 11:36:20

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/templates/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

#define ls p << 1
#define rs p << 1 | 1
#define m ((l + r) >> 1)
const int N = 2e5 + 10;
struct node {
    int first, last, pre, suf, len;
    bool ok;
};
node tr[N << 2];
node merge(node x, node y)
{
    if (!x.len)
        return y;
    if (!y.len)
        return x;
    node res;
    res.first = x.first;
    res.last = y.last;
    if (x.ok && y.ok && x.last != y.first) {
        res.len = res.pre = res.suf = x.len + y.len;
        res.ok = true;
    } else {
        res.pre = x.pre;
        res.suf = y.suf;
        res.len = max({ res.pre, res.suf, x.len, y.len });
        if (x.last != y.first) {
            cmax(res.len, x.suf + y.pre);
            if (x.ok)
                res.pre += y.pre;
            if (y.ok)
                res.suf += x.suf;
        }
        res.ok = false;
    }
    return res;
}
void build(int p, int l, int r)
{
    tr[p].first = tr[p].last = 0;
    tr[p].pre = tr[p].suf = tr[p].len = 1;
    if (l == r) {
        tr[p].ok = true;
        return;
    }
    tr[p].ok = false;
    build(ls, l, m);
    build(rs, m + 1, r);
}
void upd(int p, int l, int r, int i)
{
    if (l == r) {
        tr[p].first ^= 1;
        tr[p].last ^= 1;
        return;
    }
    if (i <= m)
        upd(ls, l, m, i);
    else
        upd(rs, m + 1, r, i);
    tr[p] = merge(tr[ls], tr[rs]);
    // cerr<<l<<" "<<r<<" "<<tr[p].pre<<"\n";
}
node query(int p, int l, int r, int lx, int rx)
{
    if (l >= lx && r <= rx)
        return tr[p];
    if (l > rx || r < lx)
        return { 0, 0, 0, 0, 0, 0 };
    node x = query(ls, l, m, lx, rx);
    node y = query(rs, m + 1, r, lx, rx);
    node res = merge(x, y);
    // cerr<<l<<" "<<r<<" "<<res.len<<" \n";
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    while (q--) {
        int i;
        cin >> i;
        upd(1, 1, n, i);
        cout << query(1, 1, n, 1, n).len << '\n';
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}