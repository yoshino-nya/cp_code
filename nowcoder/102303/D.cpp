// Author: Zhangwuji
// Date: 2025-02-23
// Time: 20:27:10

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

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int have=n-a[1];
    ll res=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            res=res*have%mod;
            have--;
        }else if(a[i]<a[i-1]){
            have+=a[i-1]-a[i]-1;
        }else{
            cout<<"0\n";
            return;
        }
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