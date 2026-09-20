// Author: Zhangwuji
// Date: 2024-12-29
// Time: 19:13:25

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

int f[31623];
void solve()
{
    int n,m;
    cin>>n>>m;
    int now=n;
    auto f1=[&](int x){
        int res=lower_bound(f,f+31623,x)-f;
        // cerr<<res<<'\n';
        return res;
        //0 1 4 9 16
    };
    // cerr<<f1(10)<<'\n';
    for(int i=1;i<=m;i++){
        cmin(now,min({now-1,f1(now),(now+1)/2}));
        if(!now){
            now-=m-i;
            break;
        }
    }
    cout<<now<<'\n';
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
    // int i;
    for(int i=1;i*i<=INF;i++){
        f[i]=i*i;
        
    }
    // cerr<<i<<'\n';
    while (T--)
        solve();
    return 0;
}