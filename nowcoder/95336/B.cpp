// Author: Zhangwuji
// Date: 2025-02-06
// Time: 14:02:59

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

constexpr int mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    auto calc=[&](string &x){
        int A=0,B=0;
        for(int i=0;i+1<n;i++){
            if(x[i]=='0'&&x[i+1]=='1')
                A++;
            if(x[i]=='1'&&x[i+1]=='0')
                B++;
        }
        int ans=0;
        // if(ans) cerr<<x<<'\n';
        for(int i=0;i<n;i++){
            if(i-1>=0){
                A-=(x[i-1]=='0'&&x[i]=='1');
                B-=(x[i-1]=='1'&&x[i]=='0');
            }
            if(i+1<n){
                A-=(x[i]=='0'&&x[i+1]=='1');
                B-=(x[i]=='1'&&x[i+1]=='0');
            }
            x[i]='0'+((x[i]-'0')^1);
            if(i-1>=0){
                A+=(x[i-1]=='0'&&x[i]=='1');
                B+=(x[i-1]=='1'&&x[i]=='0');
            }
            if(i+1<n){
                A+=(x[i]=='0'&&x[i+1]=='1');
                B+=(x[i]=='1'&&x[i+1]=='0');
            }
            ans+=(A==B);
            // if(A==B) cerr<<x<<'\n';
            // x[i]='0'+((x[i]-'0')^1);
            if(i-1>=0){
                A-=(x[i-1]=='0'&&x[i]=='1');
                B-=(x[i-1]=='1'&&x[i]=='0');
            }
            if(i+1<n){
                A-=(x[i]=='0'&&x[i+1]=='1');
                B-=(x[i]=='1'&&x[i+1]=='0');
            }
            x[i]='0'+((x[i]-'0')^1);
            if(i-1>=0){
                A+=(x[i-1]=='0'&&x[i]=='1');
                B+=(x[i-1]=='1'&&x[i]=='0');
            }
            if(i+1<n){
                A+=(x[i]=='0'&&x[i+1]=='1');
                B+=(x[i]=='1'&&x[i+1]=='0');
            }
        }
        return ans;
    };
    vector<int>idx;
    for(int i=0;i<n;i++){
        if(s[i]=='?') idx.push_back(i);
    }
    ll res=0;
    // if(idx.empty()) res+=calc(s);
    for(int i=0;i<(1<<sz(idx));i++){
        for(int j=0;j<sz(idx);j++){
            if(i>>j&1) s[idx[j]]='1';
            else s[idx[j]]='0';
        }
        res=(res+calc(s))%mod;
    }
    cout<<res<<'\n';
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