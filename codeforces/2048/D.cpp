// Author: Zhangwuji
// Date: 2024-12-21
// Time: 12:03:53

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
    vi a(n+1),b(m+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(b[i]<=a[1])
            b[i]=INF+1;
    }
    sort(ALL(a));
    for(int i=1;i<=m;i++){
        b[i]=n+1-(lower_bound(ALL(a),b[i])-a.begin());
    }
    sort(ALL(b));
    for(int k=1;k<=m;k++){
        ll ans=0;
        for(int i=k;i<=m;i+=k)
            ans+=b[i]+1;
        cout<<ans<<" \n"[k==m];
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