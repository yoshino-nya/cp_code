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

string s;
#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)

constexpr int N = int(1e6)+5;
struct node{
    int l,r;
};
node tr[N<<2];

node merge(node x,node y){
    node res;
    res.l=x.l+y.l-min(x.l,y.r);
    res.r=x.r+y.r-min(x.l,y.r);
    return res;
}
void build(int p,int l,int r){
    if(l==r){
        if(s[l]=='(') tr[p]={1,0};
        else tr[p]={0,1};
        return;
    }
    build(ls,l,mi),build(rs,mi+1,r);
    tr[p]=merge(tr[ls],tr[rs]);
}
node query(int p,int l,int r,int lx,int rx)
{
    if(l>=lx&&r<=rx) return tr[p];
    node res{0,0};
    if(lx<=mi) res=merge(res,query(ls,l,mi,lx,rx));
    if(rx>mi) res=merge(res,query(rs,mi+1,r,lx,rx));
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-16
{                      // Time: 11:32:28 
    cin>>s;
    int n=sz(s);
    s=" "+s;
    build(1,1,n);
    int m; cin >> m;
    while(m--){
        int l,r; cin>>l>>r;
        node res=query(1,1,n,l,r);
        cout<<r-l+1-res.l-res.r<<'\n';
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