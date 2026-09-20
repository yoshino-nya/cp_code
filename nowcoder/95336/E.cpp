// Author: Zhangwuji
// Date: 2025-02-06
// Time: 13:40:46

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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vl>a(n+1,vl(m+1));
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    vector<vl>p1(a),p2(a);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p1[i][j]+=p1[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            p2[i][j]+=p2[i-1][j+1];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cerr<<p1[i][j]<<" \n"[j==m];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cerr<<p2[i][j]<<" \n"[j==m];
    ll ans=0;
    auto calc=[&](int x,int y){
        ll res=-a[x][y];
        if(n-x<m-y){
            assert(y+n-x<=m);
            res+=p1[n][y+n-x];
        }else{
            assert(x+m-y<=n);
            res+=p1[x+m-y][m];
        }
        if(n-x<y-1){
            assert(y-n+x<=m);
            res+=p2[n][y-(n-x)];
        }else{
            assert(x+y-1<=n);
            res+=p2[x+y-1][1];
        }
        return res;
    };
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cmax(ans,calc(i,j));
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