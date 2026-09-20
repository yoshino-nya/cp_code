// Author: Zhangwuji
// Date: 2025-01-04
// Time: 18:44:57

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

int ppc[1025];
vector<vi> vec(11);

void solve()
{
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    int cnt=0;
    vi c(26);
    string t;
    for(auto x:a)
        c[x-'a']=1;
    for(int i=0;i<26;i++){
        if(c[i]){
            cnt++;
            t+=char(i+'a');
        }
    }
    if(k>=cnt){
        cout<<1ll*n*(n+1)/2<<'\n';
        return;
    }
    ll ans=0;
        vector<bool>ok(n);
        vi l(n);

    for(auto i:vec[k]){
        // if(ppc[i]>k) continue;
        vector<bool>f(26);
        for(int j=0;j<cnt;j++){
            if(i>>j&1) f[t[j]-'a']=true;
        }
        for(int i=0;i<n;i++){
            if(a[i]==b[i]||f[a[i]-'a']) ok[i]=true;
            else ok[i]=false;
        }
        l[0]=0;
        if(!ok[0]) l[0]=1;
        for(int i=1;i<n;i++){
            l[i]=i+1;
            if(ok[i]) l[i]=l[i-1];
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            // if(!ok[i]) continue;
            sum+=i-l[i]+1;
        }
        cmax(ans,sum);
        if(ans==1ll*(1+n)*n/2) break;
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
    for(int i=1;i<1025;i++)
        ppc[i]=ppc[i>>1]+(i&1);
    vec[0].push_back(0);
    for(int i=1;i<1025;i++){
        vec[ppc[i]].push_back(i);
    }
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}