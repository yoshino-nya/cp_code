// Author: Zhangwuji
// Date: 2024-12-29
// Time: 19:03:05

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
    int n,m,k;
    cin>>n>>m>>k;
    if(k<max(n,m)){
        cout<<"-1\n";
        return;
    }
    vector a(n+1,vi(m+1));
    int j=1;
    if(n>m){
        for(int i=1;i<=n;i++){
            a[i][j]=1;
            j++;
            if(j==m+1) j=1;
            k--;
        }
    }else{
        for(int i=1;i<=m;i++){
            a[j][i]=1;
            j++;
            if(j==n+1) j=1;
            k--;
        }
    }
    a[1][1]+=k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<" \n"[j==m];
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