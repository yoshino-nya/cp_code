// Author: Zhangwuji
// Date: 2025-02-19
// Time: 08:30:54

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
    /*
    dp0 dp1 dp2
    X.  XX  XX
    XX  X.  XX 
    */
    int n;
    cin>>n;
    string s[2];
    cin>>s[0]>>s[1];
    s[0]=" "+s[0];
    s[1]=" "+s[1];
    auto check1=[&](int i){
        return ((s[0][i+1]=='A')+(s[1][i+1]=='A')+(s[1][i+2]=='A'))>=2;
    };
    auto check2=[&](int i){
        return (s[0][i+1]=='A')+(s[1][i+1]=='A')+(s[0][i+2]=='A')>=2;
    };
    auto check3=[&](int i){
        int res=0;
        assert(i+3<=n);
        if((s[0][i+1]=='A')+(s[0][i+2]=='A')+(s[0][i+3]=='A')>=2) res++;
        if((s[1][i+1]=='A')+(s[1][i+2]=='A')+(s[1][i+3]=='A')>=2) res++;
        return res;
    };
    vector<vi> dp(n+1,vi(3));
    for(int i=1;i<=n;i++){
        if(i+1<=n){
            cmax(dp[i+1][0],dp[i-1][2]+check1(i-1));
            cmax(dp[i+1][1],dp[i-1][2]+check2(i-1));
            cmax(dp[i+1][2],dp[i][0]+((s[0][i]=='A')+(s[0][i+1]=='A')+(s[1][i+1]=='A')>=2));
            cmax(dp[i+1][2],dp[i][1]+((s[1][i]=='A')+(s[0][i+1]=='A')+(s[1][i+1]=='A')>=2));
        }
        if(i+3<=n){
            cmax(dp[i+3][0],dp[i][0]+((s[0][i]=='A')+(s[0][i+1]=='A')+(s[0][i+2]=='A')>=2)+((s[1][i+1]=='A')+(s[1][i+2]=='A')+(s[1][i+3]=='A')>=2));
            cmax(dp[i+3][1],dp[i][1]+((s[1][i]=='A')+(s[1][i+1]=='A')+(s[1][i+2]=='A')>=2)+((s[0][i+1]=='A')+(s[0][i+2]=='A')+(s[0][i+3]=='A')>=2));
        }
        if(i+2<=n){
            cmax(dp[i+2][2],dp[i-1][2]+check3(i-1));
        }
    }
    // for(int i=1;i<=n;i++)
    //     cerr<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" \n";
    cout<<dp[n][2]<<'\n';
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