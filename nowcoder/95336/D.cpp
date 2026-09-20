// Author: Zhangwuji
// Date: 2025-02-08
// Time: 15:46:00

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
    string a,b;
    cin>>a>>b;
    if(n<m) swap(a,b);
    vi cnt1(26),cnt2(26);
    for(auto x:a){
        cnt1[x-'a']++;
    }
    for(auto x:b){
        cnt2[x-'a']++;
    }
    int ans=0;
    for(int i=0;i<26;i++){
        if(cnt1[i]<cnt2[i])
            ans+=cnt2[i]-cnt1[i];
        cnt1[i]=max(0,cnt1[i]-cnt2[i]);
    }
    int x=0;
    for(int i=0;i<26;i++){
        x+=cnt1[i]&1;
    }
    if(ans>=x){
        cout<<ans<<'\n';
    }else{
        cout<<ans+(x-ans)/2<<'\n';
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}