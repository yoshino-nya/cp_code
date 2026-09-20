// Author: Zhangwuji
// Date: 2025-01-01
// Time: 22:58:32

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
    vi cnt(n*2+1),l(n),r(n);
    set<int>st;
    for(int i=1;i<=2*n;i++)
        st.insert(i);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        if(l[i]==r[i]){
            cnt[l[i]]++;
            st.erase(l[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(l[i]==r[i]){
            if(cnt[l[i]]==1)
                cout<<"1";
            else cout<<"0";
        }else{
            auto it=st.lower_bound(l[i]);
            if(it!=st.end()&&*it<=r[i]) cout<<"1";
            else cout<<"0";
        }
    }
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}