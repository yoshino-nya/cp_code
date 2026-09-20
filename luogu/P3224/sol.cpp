// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

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
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-16
// Time: 09:35:03
constexpr int N = int(1e5) + 5;
int f[N], T[N], ans[N];
struct node{
    int l, r, sum, LL, RR;
    //l, r 用来记左右子节点
    //LL, RR 用来记维护的值域范围
};
node tr[N * 50];
int tot = 0;
int insert(int val, int l, int r)
{
    // 插入值为 val 的节点, 实际上是开了一棵新线段树
    // insert 只需要 log 个点， 应该是不太好省空间
    int rt = ++tot;
    tr[rt].LL = l, tr[rt].RR = r, tr[rt].sum = 1;
    if(l == r) return rt;
    int mid = (l + r) >> 1;
    if(val <= mid) tr[rt].l = insert(val, l, mid);
    else tr[rt].r = insert(val, mid + 1, r);
    return rt;
}
int merge(int a, int b, int l, int r){
    if(!a) return b;
    if(!b) return a;

    // 这里是否必须开新点？ 好像并非
    // int rt = ++tot;
    // tr[rt].LL = l, tr[rt].RR = r, tr[rt].sum = tr[a].sum + tr[b].sum;

    // // 递归合并左右子树
    int mid = (l + r) >> 1;
    // tr[rt].l = merge(tr[a].l, tr[b].l, l, mid);
    // tr[rt].r = merge(tr[a].r, tr[b].r, mid + 1, r);
    // return rt;

    tr[a].sum += tr[b].sum;
    tr[a].l = merge(tr[a].l, tr[b].l, l, mid);
    tr[a].r = merge(tr[a].r, tr[b].r, mid + 1, r);
    return a;
}
int query(int x, int k)
{
    //在线段树 x 中找第 k 小
    if(tr[x].sum < k) return -1;
    if(tr[x].LL == tr[x].RR) return ans[tr[x].LL];
    if(tr[tr[x].l].sum >= k) return query(tr[x].l, k);
    return query(tr[x].r, k - tr[tr[x].l].sum);
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void ChatGptDeepSeek()
{
    // 好像挺简单，并查集搞一下，然后线段树合并
    int n, m;
    cin >> n >> m;
    vi p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        f[i] = i;
        T[i] = insert(p[i], 1, n);
        ans[p[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        int X = find(x), Y = find(y);
        if(X != Y){
            f[Y] = X;
            T[X] = merge(T[X], T[Y], 1, n);
        }
    }
    int q;
    cin >> q;
    while(q--){
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'Q')
            cout << query(T[find(x)], y) << '\n';
        else{
            int X = find(x), Y = find(y);
            if(X != Y){
                f[Y] = X;
                T[X] = merge(T[X], T[Y], 1, n);
            }
        }
    }
}

int main()
{
    // freopen("1.in", "r", stdin);
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}