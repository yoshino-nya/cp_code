// Author: Zhangwuji
// Date: 2025-02-19
// Time: 22:32:58

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
    int n;
    cin>>n;
    vl a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll ans=0;
    vl b(n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==1&&a[i]<a[i-1]){
            cout<<"-1\n";
            return;
        }
    }
    for(int i=2;i<=n;i++){
        ll x=a[i],y=a[i-1];
        while(x<y){
            x*=x;
            b[i]++;
        }
        while(y!=1&&y*y<=x){
            y*=y;
            b[i]--;
        }
        b[i]+=b[i-1];
        cmax(b[i],0LL);
        ans+=b[i];
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