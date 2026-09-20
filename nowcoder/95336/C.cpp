// Author: Zhangwuji
// Date: 2025-02-08
// Time: 14:48:35

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

ll ksm(ll a,ll b)
{
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    if(n==1){
        if(s[0]=='?') cout<<"2\n";
        else cout<<"1\n";
        return;
    }
    int cnt=count(s.begin()+1,s.begin()+n-1,'?');
    if(s[0]!=s[n-1]){
        if(s[0]=='?'||s[n-1]=='?')
            cout<<(ksm(2,cnt)*(n-2)+2*ksm(2,cnt))%mod<<'\n';
        else
            cout<<2*ksm(2,cnt)%mod<<'\n';
    }else if(s[0]=='?')
        cout<<(ksm(2,cnt)*2*2+2*ksm(2,cnt)*(n-2))%mod<<'\n';
    else
        cout<<((n-2)*ksm(2,cnt))%mod<<'\n';
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