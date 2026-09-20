// Author: Zhangwuji
// Date: 2024-12-16
// Time: 10:08:53

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
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

const int N = 1e6 + 10;
int a[N];
#define ls p << 1
#define rs p << 1 | 1
#define m ((l + r) >> 1)
struct node {
    ll mx, add, x;
};
node tree[N << 2];
void push_down(int p, int l, int r)
{

    if (tree[p].x < LNF) {
        tree[ls].x = tree[rs].x = tree[p].x;
        tree[ls].mx = tree[rs].mx = tree[p].x;
        tree[ls].add = tree[rs].add = 0;
        tree[p].x = LNF;
    }
    if (tree[p].add) {
        // if (tree[ls].x < LNF)
        //     tree[ls].x += tree[p].add;
        // else
            tree[ls].add += tree[p].add;
        tree[ls].mx += tree[p].add;
        // if (tree[rs].x < LNF)
        //     tree[rs].x += tree[p].add;
        // else
            tree[rs].add += tree[p].add;
        tree[rs].mx += tree[p].add;
        tree[p].add = 0;
    }
}
void build(int p, int l, int r)
{
    // cerr << l << " " << r << '\n';
    if (l == r) {
        // cerr<<l<<" "<<r<<'\n';
        tree[p].mx = a[l];
        tree[p].add = 0;
        tree[p].x = LNF;
        return;
    }
    build(ls, l, m);
    build(rs, m + 1, r);
    tree[p].mx = max(tree[ls].mx, tree[rs].mx);
    tree[p].x = LNF;
    tree[p].add = 0;
}
void upd1(int p, int l, int r, int lx, int rx, int x)
{
    if (l >= lx && r <= rx) {
        tree[p].add = 0;
        tree[p].x = x;
        tree[p].mx = x;
        return;
    }
    push_down(p, l, r);
    if (lx <= m)
        upd1(ls, l, m, lx, rx, x);
    if (rx > m)
        upd1(rs, m + 1, r, lx, rx, x);
    tree[p].mx = max(tree[ls].mx, tree[rs].mx);
}
void upd2(int p, int l, int r, int lx, int rx, int x)
{
    if (l >= lx && r <= rx) {
        // if (tree[p].x < LNF)
        //     tree[p].x += x;
        // else
            tree[p].add += x;
        tree[p].mx += x;
        return;
    }
    push_down(p, l, r);
    if (lx <= m)
        upd2(ls, l, m, lx, rx, x);
    if (rx > m)
        upd2(rs, m + 1, r, lx, rx, x);
    tree[p].mx = max(tree[ls].mx, tree[rs].mx);
}
ll query(int p, int l, int r, int lx, int rx)
{
    if (l >= lx && r <= rx) {
        return tree[p].mx;
    }
    push_down(p, l, r);
    ll res = -LNF;
    if (lx <= m)
        cmax(res, query(ls, l, m, lx, rx));
    if (rx > m)
        cmax(res, query(rs, m + 1, r, lx, rx));
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int x;
            cin >> x;
            upd1(1, 1, n, l, r, x);
        } else if (op == 2) {
            int x;
            cin >> x;
            upd2(1, 1, n, l, r, x);
        } else {
            cout << query(1, 1, n, l, r) << '\n';
        }
        // cerr << query(1, 1, n, 1, n) << '\n';
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