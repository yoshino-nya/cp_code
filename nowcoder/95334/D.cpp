// Author: Zhangwuji
// Date: 2025-01-23
// Time: 15:01:48

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
    string s;
    cin>>s;
    vector<bool>vis(26);
    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(vis[s[i]-'a']){
            // cout<<i+1<<'\n';
            cmax(ans,i+1);
            break;
        }
        vis[s[i]-'a']=true;
    }
    vis=vector<bool>(26);
    for(int i=0;i<n;i++){
        if(vis[s[i]-'a']){
            cmax(ans,n-i);
            break;
        }//azabc
        vis[s[i]-'a']=true;
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
//aaaa 3
//lmyjrxbvcn 
//sdhixlgsmj 1
//kxauxhdmfggvcibbuzji 15
//xlqounjgkdgrqjkbqaedsurwrnftvv 29
//rahgqsjbodpyrsdwketimqoqemrpko 23