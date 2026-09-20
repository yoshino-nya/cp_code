// Author: Zhangwuji
// Date: 2025-01-04
// Time: 22:40:47

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

void solve()
{
    int n,k;
    cin>>n>>k;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(ALL(a));
    int cnt=1;
    multiset<int>st;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            st.insert(cnt);
            cnt=1;
        }else cnt++;
    }
    st.insert(cnt);
    while(sz(st)>=2&&k){
        if(*st.begin()>k) break;
        int x=*st.begin();
        st.erase(st.begin());
        int y=*st.rbegin();
        st.erase(st.lower_bound(y));
        st.insert(x+y);
        k-=x;
    }
    cout<<sz(st)<<'\n';
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