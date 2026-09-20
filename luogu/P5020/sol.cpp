// Author: Zhangwuji
// Date: 2025-01-01
// Time: 04:01:34

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
    //一个货币只能被面额更小的给淘汰
    //被淘汰了就不用考虑它了
    //因为n很小 所以可以遍历每一个面额 看能不能被表示
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(ALL(a));
    int mx=a[n];
    vector<bool>ok(mx+1);
    ok[0]=true;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(ok[a[i]]) continue;
        for(int j=0;j+a[i]<=mx;j++){
            if(ok[j]) ok[j+a[i]]=true;
        }
        ans++;
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