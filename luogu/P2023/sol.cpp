// Author: Zhangwuji
// Date: 2025-01-01
// Time: 04:09:59

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

constexpr int N = 1e5 + 10;
int mod, a[N];

struct node {
    ll sum, t1, t2;
};

#define ls p << 1
#define rs p << 1 | 1
#define m ((l + r) >> 1)
node tr[N << 2];

void build(int p, int l, int r)
{
    tr[p].t1 = 1, tr[p].t2 = 0;
    if (l == r) {
        tr[p].sum = a[l];
        return;
    }
    build(ls, l, m);
    build(rs, m + 1, r);
    tr[p].sum = (tr[ls].sum + tr[rs].sum) % mod;
}

void pushdown(int p, int l, int r)
{
    ll t1 = tr[p].t1, t2 = tr[p].t2;
    if (t1 != 1) {
        tr[ls].sum = tr[ls].sum * t1 % mod;
        tr[ls].t1 = tr[ls].t1 * t1 % mod;
        tr[ls].t2 = tr[ls].t2 * t1 % mod;
        tr[rs].sum = tr[rs].sum * t1 % mod;
        tr[rs].t1 = tr[rs].t1 * t1 % mod;
        tr[rs].t2 = tr[rs].t2 * t1 % mod;
        tr[p].t1 = 1;
        // cerr<<l<<" "<<r<<" "<<t2<<" "<<tr[ls].sum<<" \n";
    }
    if (t2) {
        tr[ls].sum = (tr[ls].sum + t2 * (m - l + 1) % mod) % mod;
        tr[ls].t2 = (tr[ls].t2 + t2) % mod;
        tr[rs].sum = (tr[rs].sum + t2 * (r - m) % mod) % mod;
        tr[rs].t2 = (tr[rs].t2 + t2) % mod;
        tr[p].t2 = 0;
        // cerr<<tr[ls].sum<<" "<<tr[rs].sum<<'\n';
    }
}

void upd1(int p, int l, int r, int lx, int rx, int x)
{
    if (l >= lx && r <= rx) {
        tr[p].sum = tr[p].sum * x % mod;
        tr[p].t1 = tr[p].t1 * x % mod;
        tr[p].t2 = tr[p].t2 * x % mod;
        return;
    }
    pushdown(p, l, r);
    if (lx <= m)
        upd1(ls, l, m, lx, rx, x);
    if (rx > m)
        upd1(rs, m + 1, r, lx, rx, x);
    tr[p].sum = (tr[ls].sum + tr[rs].sum) % mod;
}

void upd2(int p, int l, int r, int lx, int rx, int x)
{
    if (l >= lx && r <= rx) {
        tr[p].sum = (tr[p].sum + x * (r - l + 1) % mod) % mod;
        // 我测 孩子们 我一才发现是+ x*( ) ，这辈子有了
        tr[p].t2 = (tr[p].t2 + x) % mod;
        return;
    }
    pushdown(p, l, r);
    if (lx <= m)
        upd2(ls, l, m, lx, rx, x);
    if (rx > m)
        upd2(rs, m + 1, r, lx, rx, x);
    tr[p].sum = (tr[ls].sum + tr[rs].sum) % mod;
}

int query(int p, int l, int r, int lx, int rx)
{
    if (l >= lx && r <= rx) {
        return tr[p].sum;
    }
    pushdown(p, l, r);
    ll res = 0;
    if (lx <= m)
        res += query(ls, l, m, lx, rx);
    if (rx > m)
        res += query(rs, m + 1, r, lx, rx);
    return res % mod;
}

void solve()
{
    int n;
    cin >> n >> mod;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int q;
    cin >> q;
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
    }
    // cerr << query(1, 1, n, 4, 4) << "\n";
    // cerr << query(1, 1, n, 5, 5) << "\n";
    // cerr << query(1, 1, n, 6, 6) << "\n";
    // cerr << query(1, 1, n, 7, 7) << "\n";
    // cerr << query(1, 1, n, 4, 5) << '\n';
    // cerr << query(1, 1, n, 4, 6) << '\n';
    // cerr << query(1, 1, n, 6, 6) << " 66\n";
    // cerr << query(1, 1, n, 4, 7) << '\n';
    // cerr << query(1, 1, n, 6, 7) << '\n';
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