// Author: Zhangwuji
// Date: 2025-02-02
// Time: 13:33:13

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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pii>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(ALL(a),greater<>());
    vector<int>idx(m*k+1);
    ll sum=0;
    for(int i=1;i<=m*k;i++){
        idx[i]=a[i].se;
        sum+=a[i].fi;
    }
    sort(ALL(idx));
    cout<<sum<<'\n';
    for(int i=1;i<k;i++)
        cout<<idx[i*m]<<" ";
    cout<<'\n';
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