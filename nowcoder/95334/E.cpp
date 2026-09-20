// Author: Zhangwuji
// Date: 2025-01-23
// Time: 16:09:46

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
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    //2 1 2 7
    // 3->4 5
    // 2->3 1 2->4 6
    // -1 1 5
    // 2  3 5
    // pre[i]-a[i]-(s[i])
    vl pre(n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    vl s(n);
    for(int i=1;i<n;i++)
        s[i]=s[i-1]+a[i+1]-a[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        int lo=0,hi=INF+1;
        while(lo<hi-1){
            int mid=(lo+hi)>>1;
            if(check())
        }
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}