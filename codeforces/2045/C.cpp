// Author: Zhangwuji
// Date: 2025-01-01
// Time: 02:01:53

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
    string s,t;
    cin>>s>>t;
    
    int n=sz(s),m=sz(t);
    vi l(26,n),r(26,-1);
    for(int i=1;i<n;i++)
        cmin(l[s[i]-'a'],i);
    for(int i=m-2;i>=0;i--)
        cmax(r[t[i]-'a'],i);
    int ans=n+m;
    for(int i=0;i<26;i++){
        if((l[i]==n)||(r[i]==-1)) continue;
        cmin(ans,l[i]+m-r[i]);
    }
    for(int i=0;i<26;i++){
        if((l[i]==n)||(r[i]==-1)) continue;
        if(l[i]+m-r[i]==ans){
            for(int j=0;j<l[i];j++)
                cout<<s[j];
            for(int j=r[i];j<m;j++)
                cout<<t[j];
            return;
        }
    }
    cout<<"-1";
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