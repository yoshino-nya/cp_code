// Author: Zhangwuji
// Date: 2025-01-22
// Time: 20:13:17

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
    // 只能是选左边的或者选右边的数字
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + l);
    sort(a.begin() + l, a.begin() + r + 1,greater<int>());
    if (r != n)
        sort(a.begin() + r + 1, a.end());
    vl p1(n+1),p2(n+1),p3(n+1);
    for(int i=1;i<l;i++)
        p1[i]=p1[i-1]+a[i];
    for(int i=l;i<=r;i++){
        p2[i]=p2[i-1]+a[i];
    }
    for(int i=r+1;i<=n;i++){
        p3[i]=p3[i-1]+a[i];
    }
    // dbg(a);
    // dbg(p1);
    // dbg(p2);
    // dbg(p3);
    ll ans=p2[r];
    for(int i=l;i<=r;i++){
        if(i-l+1<l){
            cmin(ans,p1[i-l+1]+p2[r]-p2[i]);
        }
        if(i-l+1<=n-r){
            cmin(ans,p3[r+i-l+1]+p2[r]-p2[i]);
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