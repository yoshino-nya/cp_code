// Author: Zhangwuji
// Date: 2025-01-05
// Time: 15:06:08

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

const int N = 2e5 + 10;

struct segTree {
    struct node {
        int Max, Min, Val;
    };
    vector<node> tr;

#define ls p << 1
#define rs p << 1 | 1
#define m ((l + r) >> 1)

    node merge(node& x, node& y)
    {
        node res;
        res.Max = max(x.Max, y.Max);
        res.Min = min(x.Min, y.Min);
        res.Val = max(x.Val, y.Val);
        cmax(res.Val, y.Max - x.Min);
        return res;
    }

    void upd(int p, int l, int r, int i, int x)
    {
        if (l == r) {
            tr[p].Max = tr[p].Min = x - l;
            return;
        }
        if (i <= m)
            upd(ls, l, m, i, x);
        else
            upd(rs, m + 1, r, i, x);
        tr[p] = merge(tr[ls], tr[rs]);
    }

    segTree(const auto& a)
    {
        tr = vector<node>(sz(a)<<2);
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) {
                tr[p].Max = tr[p].Min = a[l]-l;
                tr[p].Val = 0;
                return;
            }
            self(self, ls, l, m);
            self(self, rs, m + 1, r);
            tr[p] = merge(tr[ls], tr[rs]);
        };
        build(build, 1, 1, sz(a)-1);
    }
    //a[l]-a[r]-(r-l)
    //a[l]+l - (a[r]+r)
    //
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    segTree t1(a);
    reverse(ALL(a));
    segTree t2(a);
    cout << max(t1.tr[1].Val, t2.tr[1].Val) << '\n';
    while (q--) {
        int p, x;
        cin >> p >> x;
        t1.upd(1, 1, n, p, x);
        t2.upd(1, 1, n, n - p + 1, x);
        cout << max(t1.tr[1].Val, t2.tr[1].Val) << '\n';
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}