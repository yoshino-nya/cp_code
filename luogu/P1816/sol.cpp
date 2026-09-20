// Author: Zhangwuji
// Date: 2024-12-18
// Time: 00:06:38

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

const int N=1e5+5;
int f[N][22];
void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][0]=a[i];
    }
    for(int j=1;j<=__lg(n);j++){
        for(int i=1;i+(1<<j)<=n+1;i++)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
    auto query=[&](int l,int r){
        int k=__lg(r-l+1);
        return min(f[l][k],f[r-(1<<k)+1][k]);
    };
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<' ';
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