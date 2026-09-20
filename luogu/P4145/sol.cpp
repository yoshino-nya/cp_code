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

constexpr int N = 100005;

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)
struct node{
    ll max,sum;
};
node tr[N<<2];
void push_up(int p)
{
    tr[p].sum = tr[ls].sum + tr[rs].sum;
    tr[p].max = max(tr[ls].max,tr[rs].max);
}
void upd(int p,int l,int r,int lx,int rx)
{
    if(tr[p].max == 1) return;
    if(l == r){
        tr[p].sum = tr[p].max = (int)sqrt(tr[p].max);
        return;
    }
    if(lx <= mi) upd(ls,l,mi,lx,rx);
    if(rx > mi) upd(rs,mi+1,r,lx,rx);
    push_up(p);
}
ll query(int p,int l,int r,int lx,int rx)
{
    if(l >= lx && r <= rx) return tr[p].sum;
    ll res=0;
    if(lx <= mi) res += query(ls,l,mi,lx,rx);
    if(rx > mi) res += query(rs,mi+1,r,lx,rx);
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-22
{                      // Time: 14:50:52 
    int n;
    cin >> n;
    vl a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    auto build=[&](auto &&self,int p,int l,int r)->void{
        if(l==r){
            tr[p]={a[l],a[l]};
            return;
        }
        self(self,ls,l,mi),self(self,rs,mi+1,r);
        push_up(p);
    };
    build(build,1,1,n);
    int q;
    cin >> q;
    while(q--){
        int op,l,r;
        cin >> op >> l >> r;
        if(l > r) swap(l,r);
        if(op == 0)
            upd(1,1,n,l,r);
        else
            cout<<query(1,1,n,l,r)<<'\n';
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
        ChatGptDeepSeek();
    return 0;
}