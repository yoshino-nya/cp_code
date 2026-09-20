// Author: Zhangwuji
// Date: 2024-12-20
// Time: 10:25:30

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
    string s;
    cin>>s;
    int n=sz(s),idx=0;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]!='1'){
            idx=i;
            break;
        }
    }
    if(!idx){
        cout<<"1 "<<n<<" 1 1\n";
        return;
    }
    auto calc=[&](int j){
        //calc the res of [j, ] ^ [idx,n]
        // idx-j=n-x
        // x=n+j-idx
        for(int i=idx;i<=n;i++,j++){
            if(s[i]==s[j]){
                // cerr<<i<<" ";
                return i;
            }
        }
        return n+1;
    };
    vector<int>val(idx);
    int mx=0;
    for(int i=1;i<idx;i++)
        val[i]=calc(i),cmax(mx,val[i]);
    for(int i=1;i<idx;i++){
        // cerr<<val[i]<<" ";
        if(val[i]==mx){
            cout<<"1 "<<n<<" "<<i<<" "<<n+i-idx<<'\n';
            return;
        }
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}