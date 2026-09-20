// Author: Zhangwuji
// Date: 2025-01-01
// Time: 03:00:49

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
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    ll sum=0;
    priority_queue<int>q;
    for(int i=m;i>1;i--){
        sum+=a[i];
        if(a[i]<=0) continue;
        q.push(a[i]*2);
        if(sum>0){
            sum-=q.top();
            q.pop();
            ans++;
        }
    }
    //sum[i,m]一定要是负数
    //否则不如不加，但是a[1] 无论如何都没必要变
    //。。。。我真傻真的
    while(!q.empty()) q.pop();
    sum=0;
    for(int i=m+1;i<=n;i++){
        sum+=a[i];
        if(a[i]>=0) continue;
        q.push(-a[i]*2);
        if(sum<0){
            sum+=q.top();
            q.pop();
            ans++;
        }
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