/*
每一次肯定都会去找值最大的那一个
如果有多个值相同 那么肯定会选择下标尽量大的
那么咱们可以用pair来存，
然后选了之后，把[idx+1,n]之间给区间-1
*/
// Author: Zhangwuji
// Date: 2025-02-20
// Time: 22:05:30

// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
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

// struct segtree {
// #define ls p << 1
// #define rs p << 1 | 1
// #define mid ((l + r) >> 1)
//     vector<pii> tr;
//     vi t;
//     void pushdown(int p, int l, int r)
//     {
//         t[ls] += t[p];
//         t[rs] += t[p];
//         tr[ls].fi -= t[p];
//         tr[rs].fi -= t[p];
//         t[p] = 0;
//     }
//     pii merge(pii x, pii y)
//     {
//         if(x.fi>y.fi)
//             return x;
//         else if(x.fi<y.fi)
//             return y;
//         if(x.se<y.se)
//             return x;
//         return y;
//     }
//     pii query(int p, int l, int r, int lx, int rx)
//     {
//         // 查询区间最大值
//         if (lx >= l && rx <= r)
//             return tr[p];
//         if (t[p])
//             pushdown(p, l, r);
//         pii res { 0, 0 };
//         if (lx <= mid)
//             res=merge(res, query(ls, l, mid, lx, rx));
//         if (rx > mid)
//             res=merge(res, query(rs, mid + 1, r, lx, rx));
//         return res;
//     }
//     void change(int p, int l, int r, int i)
//     {
//         if (l == r) {
//             tr[p] = { 0, 0 };
//             return;
//         }
//         if (t[p])
//             pushdown(p, l, r);
//         if (i <= mid)
//             change(ls, l, mid, i);
//         else
//             change(rs, mid + 1, r, i);
//         tr[p] = merge(tr[ls], tr[rs]);
//     }
//     void upd(int p, int l, int r, int lx, int rx, int x)
//     {
//         if (l >= lx && r <= rx) {
//             tr[p].fi -= x;
//             t[p] += x;
//             return;
//         }
//         if (t[p])
//             pushdown(p, l, r);
//         if (lx <= mid)
//             upd(ls, l, mid, lx, rx, x);
//         if (mid < rx)
//             upd(rs, mid + 1, r, lx, rx, x);
//     }
//     segtree(vi a)
//     {
//         tr.resize(sz(a) << 2);
//         t.resize(sz(a) << 2, 0);
//         auto build = [&](auto&& self, int p, int l, int r) -> void {
//             // cerr<<l<<" \n";
//             if (l == r) {
//                 tr[p] = { a[l] + l, l };
//                 return;
//             }
//             self(self, ls, l, mid);
//             self(self, rs, mid + 1, r);
//             tr[p] = merge(tr[ls], tr[rs]);
//         };
//         build(build, 1, 1, sz(a) - 1);
//     }
// };
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += i;
    sort(ALL(a), greater<>());
    set<int> st;
    st.insert(a[1]);
    for (int i = 2; i <= n; i++) {
        cmin(a[i],a[i-1]-1);
        st.insert(a[i]);
    }
    for (auto it = st.rbegin(); it != st.rend(); it++)
        cout << *it << ' ';
    cout << '\n';
    // segtree sg(a);
    // set<int> ans;
    // for (int i = 1; i <= n; i++) {
    //     auto [x, y] = sg.query(1, 1, n, 1, n);
    //     // ans.push_back(x);
    //     ans.insert(x);

    //     // cout << x << " \n"[i == n];
    //     sg.upd(1, 1, n, y + 1, n, 1);
    //     sg.change(1, 1, n, y);
    // }
    // for(auto it=ans.rbegin();it!=ans.rend();it++)
    //     cout<<*it<<" ";
    // cout<<'\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}