// Author: Zhangwuji
// Date: 2024-12-17
// Time: 23:43:01

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
constexpr int N = 2e5;

struct Fenwick{
    int b[N+5]={};
    int lowbit(int x){return (x)&(-x);}
    void add(int i,int x){
        while(i<=N){
            b[i]+=x;
            i+=lowbit(i);
        }
    }
    int get(int i){
        int res=0;
        while(i){
            res+=b[i];
            i-=lowbit(i);
        }
        return res;
    }
    int query(int l,int r){
        return get(r)-get(l-1);
    }
};
Fenwick t1,t2;
void solve()
{
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t2.add(a[i],1);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        t2.add(a[i],-1);
        ans+=1ll*t1.query(1,a[i]-1)*t2.query(a[i]+1,N);
        t1.add(a[i],1);
    }
    cout<<ans<<'\n';
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