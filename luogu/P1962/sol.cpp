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

constexpr int mod = int(1e9)+7;
void ChatGptDeepSeek() // Date: 2025-04-28
{                      // Time: 17:32:58 
    ll n;
    cin >> n;
    vector<vl> res(3, vl(3));
    vector<vl> a(3, vl(3));
    a[1][1] = a[1][2] = a[2][1] = 1;
    res[1][1] = res[2][2] = 1;
    n--;
    while(n){
        if(n&1){
            vector<vl> tmp(3,vl(3));
            for(int i=1;i<=2;i++){
                for(int j=1;j<=2;j++){
                    for(int k=1;k<=2;k++){
                        tmp[i][j]=(tmp[i][j]+res[i][k]*a[k][j]%mod)%mod;
                    }
                }
            }
            res=tmp;
            // for(int i=1;i<=2;i++)
            //     for(int j=1;j<=2;j++)
            //         cout<<res[i][j]<<" \n"[j==2];
        }
        {
            vector<vl> tmp(3,vl(3));
            for(int i=1;i<=2;i++){
                for(int j=1;j<=2;j++){
                    for(int k=1;k<=2;k++){
                        tmp[i][j]=(tmp[i][j]+a[i][k]*a[k][j]%mod)%mod;
                    }
                }
            }
            a=tmp;
        }
        n>>=1;
    }
    //[1,0] 
    cout << res[1][1] << '\n';
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
        ChatGptDeepSeek();
    return 0;
}