// Author: Zhangwuji
// Date: 2024-12-24
// Time: 00:39:36

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/templates/debug.hpp"
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
    ll x,y;
    cin>>n>>x>>y;
    ll sum=0;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    sort(ALL(a));
    ll ans=0;
    for(int i=1;i<=n;i++){
        auto i1=upper_bound(a.begin()+i+1,a.end(),sum-x-a[i]);
        auto i2=lower_bound(a.begin()+i+1,a.end(),sum-y-a[i]);
        ans+=i1-i2;
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