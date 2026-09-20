// Author: Zhangwuji
// Date: 2025-01-17
// Time: 22:39:45

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

void solve()
{
    int n,m;
    cin>>n>>m;
    vi x(n),y(n);
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    ll ans=m*m*n;
    int xx=m+x[0],yy=m+y[0];
    auto calc=[&](int x1,int y1,int x2,int y2){
        return abs((x1-x2)*(y1-y2));
    };
    for(int i=1;i<n;i++){
        int nx=xx+x[i],ny=yy+y[i];
        ans-=calc(xx,yy,nx-m,ny-m);
        nx+=x[i],ny+=y[i];
        cerr<<ans<<'\n';
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}