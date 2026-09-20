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

void ChatGptDeepSeek() // Date: 2025-04-19
{                      // Time: 22:53:39 
    int n,k;
    cin>>n>>k;
    vi l(n),r(n);
    for(int i=0;i<n;i++) cin>>l[i];
    for(int i=0;i<n;i++) cin>>r[i];
    ll ans=0;
    vi c(n);
    for(int i=0;i<n;i++){
        ans+=max(l[i],r[i]);
        c[i]=min(l[i],r[i]);
    }
    sort(all(c),greater<int>());
    for(int i=0;i+1<k;i++)
        ans+=c[i];
    cout<<ans+1<<'\n';

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
        ChatGptDeepSeek();
    return 0;
}