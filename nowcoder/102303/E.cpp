// Author: Zhangwuji
// Date: 2025-02-23
// Time: 20:17:42

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

void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n+1),b(n+1);
    vl s1(n+1),s2(n+1);
    multiset<int>st1,st2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        st1.insert(a[i]);
        sum+=a[i];
        while(sz(st1)>m){
            sum-=*st1.rbegin();
            st1.erase(prev(st1.end()));
        }
        s1[i]=sum;
    }
    sum=0;
    for(int i=n;i>=1;i--){
        st2.insert(b[i]);
        sum+=b[i];
        while(sz(st2)>m){
            sum-=*st2.rbegin();
            st2.erase(prev(st2.end()));
        }
        s2[i]=sum;
    }
    ll ans=LNF;
    for(int i=m;i+m<=n;i++){
        cmin(ans,s1[i]+s2[i+1]);
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