// Author: Zhangwuji
// Date: 2025-01-24
// Time: 02:13:42

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
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    bool multi=false;
    for(int i=0;i<n;i++){
        if(s[0][i]=='.'&&s[1][i]=='.'){
            if(i+1<n&&s[0][i+1]=='.'&&s[1][i+1]=='.'){
                multi=true;
            }
        }
        else if(s[0][i]=='.'&&s[1][i]=='#'){
            if(i+1==n||s[0][i+1]!='.'){
                cout<<"None\n";
                return;            
            }
            s[0][i+1]='#';
        }else if(s[0][i]=='#'&&s[1][i]=='.'){
            if(i+1==n||s[1][i+1]!='.'){
                cout<<"None\n";
                return;
            }
            s[1][i+1]='#';
        }
    }
    if(multi) cout<<"Multiple\n";
    else cout<<"Unique\n";
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