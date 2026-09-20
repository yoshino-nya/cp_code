// Author: Zhangwuji
// Date: 2025-01-27
// Time: 23:16:31

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
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(all(a),greater<>());
    int now=1;
    vector<int>ans;
    while(m){
        if(m<now){
            break;
        }
        // cerr<<a.back();
        if(!a.empty()&&now==a.back()){
            a.pop_back();
            
            now++;
            continue;
        }
        ans.push_back(now);
        m-=now;
        now++;
    }
    cout<<sz(ans)<<'\n';
    for(auto x:ans)
        cout<<x<<" ";
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