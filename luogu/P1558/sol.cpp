// Author: Zhangwuji
// Date: 2024-12-19
// Time: 23:54:39

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

#define ls p<<1
#define rs p<<1|1
#define m ((l+r)>>1)
constexpr int N = 1e5+10;
struct node{
    int val,t;
};
node tr[N<<2];
void push_down(int p,int l,int r)
{
    if(tr[p].t){
        int x=tr[p].t;
        tr[ls].t=x;
        tr[rs].t=x;
        tr[ls].val=x;
        tr[rs].val=x;
        tr[p].t=0;
    }
}
void build(int p,int l,int r)
{
    tr[p].val=1;
    tr[p].t=0;
    if(l==r)
        return;
    build(ls,l,m);
    build(rs,m+1,r);
}
void upd(int p,int l,int r,int lx,int rx,int x)
{
    if(l>=lx&&r<=rx){
        tr[p].val=x;
        tr[p].t=x;
        return;
    }
    push_down(p,l,r);
    if(lx<=m) upd(ls,l,m,lx,rx,x);
    if(rx>m) upd(rs,m+1,r,lx,rx,x);
    tr[p].val=tr[ls].val|tr[rs].val;
}
int query(int p,int l,int r,int lx,int rx)
{
    if(l>=lx&&r<=rx)
        return tr[p].val;
    push_down(p,l,r);
    int res=0;
    if(lx<=m) res|=query(ls,l,m,lx,rx);
    if(rx>m) res|=query(rs,m+1,r,lx,rx);
    return res;
}
void solve()
{
    int L,T,O;
    cin>>L>>T>>O;
    build(1,1,L);
    while(O--){
        int l,r;
        char op;
        cin>>op>>l>>r;
        if(l>r) swap(l,r);
        if(op=='C'){
            int x;
            cin>>x;
            x--;
            upd(1,1,L,l,r,1<<x);
        }else {
            cout<<__builtin_popcount(query(1,1,L,l,r))<<'\n';
        }
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