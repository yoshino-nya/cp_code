// Author: Zhangwuji
// Date: 2025-01-20
// Time: 22:44:49

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
    int n;
    cin>>n;
    vi a(n+1);
    multiset<int>st;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    sort(ALL(a));
    int c=0;
    for(int i=n;i>=2;i--){
        if(a[i]==a[i-1]){
            c=a[i];
            st.erase(st.lower_bound(a[i]));
            st.erase(st.lower_bound(a[i]));
            break;
        }
    }
    if(!c){
        cout<<"-1\n";
        return;
    }
    for(auto it=st.begin();next(it)!=st.end();it++){
        int x=*it;
        int y=*next(it);
        if(y-x<2*c){
            cout<<c<<" "<<c<<" "<<y<<" "<<x<<'\n';
            return;
        }
    }
    cout<<"-1\n";
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